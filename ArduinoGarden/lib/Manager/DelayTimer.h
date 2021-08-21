#ifndef DELAYTIMER_DEFINE
#define DELAYTIMER_DEFINE

#include "AbstractOperation.h"
#include "ATimer.h"

#define DELAYTIMER_CURSOR_POS_LENGTH 2
class DelayTimer : public AbstractOperation
{
private:
    ATimer _timer;
    bool _isFirstExecuteComplete;

    uint8_t _cursorPosition;
    uint8_t _cursorPositions[DELAYTIMER_CURSOR_POS_LENGTH] 
    = {0, 2};
public:
    DelayTimer(uint32_t interval, Model* model);
    ~DelayTimer() override;
    void Execute() override;
    char* GetString() override;
    uint8_t GetCursorPosition() override;
    void HandleCommand(EncoderAction action) override;
};

DelayTimer::DelayTimer(uint32_t interval, Model* model) : AbstractOperation(model)
{
    _timer.SetInterval(interval);
    _isFirstExecuteComplete = false;
}

DelayTimer::~DelayTimer()
{
}
void DelayTimer::Execute(){
    if(!_isFirstExecuteComplete){
        _isFirstExecuteComplete = true;
        _timer.Start();
        return;
    }
    if(_timer.CheckTimer() == ATimerStatus::EXPIRED){
        IsCompleted = true;
    }
}

char* DelayTimer::GetString(){
    char* tmp = new char[10]{"W "};
    char number[3];
    uint32_t val = _timer.GetInterval();
    if(val < 1000){
        itoa(val, number, DEC);
        strcat(tmp, number);
        strcat(tmp, "ms");
        return tmp;
    }
    if(val < 1000*60){
        itoa((val/1000), number, DEC);
        strcat(tmp, number);
        strcat(tmp, "s");
        return tmp;
    }
    if(val < 1000*60*60){
        itoa((val/(1000*60)), number, DEC);
        strcat(tmp, number);
        strcat(tmp, "m");
        return tmp;
    }
    if(val < 1000*60*60*24){
        itoa((val/(1000*60*60)), number, DEC);
        strcat(tmp, number);
        strcat(tmp, "h");
        return tmp;
    }
    itoa((val/(1000*60*60*24)), number, DEC);
    strcat(tmp, number);
    strcat(tmp, "d");
    return tmp;
}
uint8_t DelayTimer::GetCursorPosition(){
    return _cursorPosition;
}
void DelayTimer::HandleCommand(EncoderAction action){
    if(action == EncoderAction::Left){
        if(_cursorPosition == 0) _cursorPosition = DELAYTIMER_CURSOR_POS_LENGTH;
        _cursorPosition--;
        return;
    }
    if(action == EncoderAction::Right){
        if(_cursorPosition == DELAYTIMER_CURSOR_POS_LENGTH - 1) {
            _cursorPosition = 0;
            return;
        }
        _cursorPosition++;
        return;
    }
    uint32_t val = _timer.GetInterval();
    if(action == EncoderAction::LeftHold){
        switch (_cursorPosition)
        {
        case 0: return;
        case 1:
            if(val <= 100) {
                _timer.SetInterval(100);
                return;
            }
            if(val < 1000){
                _timer.SetInterval(val - 100);
                return;
            }
            if(val < 1000*60){
                _timer.SetInterval(val - 1000);
                return;
            }
            if(val < 1000*60*60){
                _timer.SetInterval(val - 1000*60);
                return;
            }
            if(val < 1000*60*60*24){
                _timer.SetInterval(val - 1000*60*60);
                return;
            }
            _timer.SetInterval(val - 1000*60*60*24);
            return;
        default:
            break;
        }
    }
    if(action == EncoderAction::RightHold){
        switch (_cursorPosition)
        {
        case 0: return;
        case 1:
            if(val > 1000*60*60*24*40){
                return;
            }
            if(val < 1000){
                _timer.SetInterval(val + 100);
                return;
            }
            if(val < 1000*60){
                _timer.SetInterval(val + 1000);
                return;
            }
            if(val < 1000*60*60){
                _timer.SetInterval(val + 1000*60);
                return;
            }
            if(val < 1000*60*60*24){
                _timer.SetInterval(val + 1000*60*60);
                return;
            }
            _timer.SetInterval(val + 1000*60*60*24);
            return;
        default:
            break;
        }
    }
}

#endif
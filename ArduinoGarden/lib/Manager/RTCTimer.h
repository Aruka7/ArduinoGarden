#ifndef RTCTIMER_DEFINE
#define RTCTIMER_DEFINE

#include "AbstractOperation.h"
#include "Config.h"

#define RTC_CURSOR_POS_LENGTH 3
class RTCTimer : public AbstractOperation
{
private:
    uint8_t _cursorPosition;
    uint8_t _cursorPositions[RTC_CURSOR_POS_LENGTH] 
    = {0, 4, 8};

    int32_t _minutes;
    int32_t Abs(int32_t number);
public:
    RTCTimer(uint8_t hour, uint8_t minute, Model* model);
    ~RTCTimer() override;
    void Execute() override;
    char* GetString() override;
    uint8_t GetCursorPosition() override;
    void HandleCommand(EncoderAction action) override;
};

RTCTimer::RTCTimer(uint8_t hour, uint8_t minute, Model* model) : AbstractOperation(model)
{
    _minutes = ((int32_t)hour)*60*60*1000 + ((int32_t)minute*60*1000);

}
int RTCTimer::Abs(int number){
    if(number < 0) return -number;
    return number;
}
RTCTimer::~RTCTimer(){}

void RTCTimer::Execute(){
    model->_timeStorage->SurveyTime();
    int32_t tmp = ((int32_t)model->_timeStorage->GetHour())*60*60*1000 + ((int32_t)model->_timeStorage->GetMinute()*60*1000);
    int32_t firstResult = Abs(_minutes - tmp);
    if(firstResult < (SLEEP_PERIOD + SLEEP_PERIOD/10)){ //todo Заменить на настройки, учесть в будущем интервалы меньше секунды
        IsCompleted = true;
        return;
    }
    int32_t secondResult = Abs(_minutes - (tmp + 24*60*60*1000));
    if(secondResult < (SLEEP_PERIOD + SLEEP_PERIOD/10)){ 
        IsCompleted = true;
        return;
    }
}

char* RTCTimer::GetString(){
    char* tmp = new char[8]{"R "};
    char number[2];
    itoa(_relayNumber, number, DEC);
    strcat(tmp, number);
    strcat(tmp, " ");
    char switcher[3];
    if(_switchingType){
        strcat(switcher, "on");
    }
    else{
        strcat(switcher, "off");
    }
    strcat(tmp, switcher);
    return tmp;
    
}
uint8_t RelaySwitch::GetCursorPosition(){
    return _cursorPosition;
}
void RelaySwitch::HandleCommand(EncoderAction action){
    if(action == EncoderAction::Left){
        if(_cursorPosition == 0) _cursorPosition = RELAYSWITCH_CURSOR_POS_LENGTH;
        _cursorPosition--;
        return;
    }
    if(action == EncoderAction::Right){
        if(_cursorPosition == RELAYSWITCH_CURSOR_POS_LENGTH - 1) {
            _cursorPosition = 0;
            return;
        }
        _cursorPosition++;
        return;
    }
    if(action == EncoderAction::LeftHold){
        switch (_cursorPosition)
        {
        case 0: return;
        case 1: 
            _relayNumber--;
            if(_relayNumber == 0) _relayNumber = 7;
            return;
        case 2:
            _switchingType = !_switchingType;
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
            _relayNumber++;
            if(_relayNumber == 8) _relayNumber = 1;
            return;
        case 2:
             _switchingType = !_switchingType;
             return;
        default:
            break;
        }
    }
}
#endif
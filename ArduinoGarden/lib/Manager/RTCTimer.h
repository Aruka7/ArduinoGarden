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

    uint8_t hour;
    uint8_t minute;
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
    this->hour = hour;
    this->minute = minute; 
}
int RTCTimer::Abs(int number){
    if(number < 0) return -number;
    return number;
}
RTCTimer::~RTCTimer(){}

void RTCTimer::Execute(){
    model->_timeStorage->SurveyTime();
    int32_t tmp = ((int32_t)model->_timeStorage->GetHour())*60*60*1000 + ((int32_t)model->_timeStorage->GetMinute()*60*1000);
    int32_t mileseconds = ((int32_t)hour)*60*60*1000 + ((int32_t)minute*60*1000);
    int32_t firstResult = Abs(mileseconds- tmp);
    if(firstResult < (SLEEP_PERIOD + SLEEP_PERIOD/10)){ //todo Заменить на настройки, учесть в будущем интервалы меньше секунды
        IsCompleted = true;
        return;
    }
    int32_t secondResult = Abs(mileseconds - (tmp + 24*60*60*1000));
    if(secondResult < (SLEEP_PERIOD + SLEEP_PERIOD/10)){ 
        IsCompleted = true;
        return;
    }
}

char* RTCTimer::GetString(){
    char* tmp = new char[12]{"RTC "};
    char hours[2];
    itoa(hour, hours, DEC);
    if(hour < 10) strcat(tmp, " ");
    strcat(tmp, hours);
    strcat(tmp, "h ");
    char min[2];
    itoa(minute, min, DEC);
    strcat(tmp, min);
    strcat(tmp, "m");
    return tmp;
    
}
uint8_t RTCTimer::GetCursorPosition(){
    return _cursorPosition;
}
void RTCTimer::HandleCommand(EncoderAction action){
    if(action == EncoderAction::Left){
        if(_cursorPosition == 0) _cursorPosition = RTC_CURSOR_POS_LENGTH;
        _cursorPosition--;
        return;
    }
    if(action == EncoderAction::Right){
        if(_cursorPosition == RTC_CURSOR_POS_LENGTH - 1) {
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
            if(hour == 0) hour = 23;
            return;
            hour--;
            return;
        case 2:
            minute--;
            if(minute == 0) minute = 59;
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
            hour++;
            if(hour == 24) hour = 0;
            return;
        case 2:
            minute++;
            if(minute == 60) minute = 1;
            return;
        default:
            break;
        }
    }
}
#endif
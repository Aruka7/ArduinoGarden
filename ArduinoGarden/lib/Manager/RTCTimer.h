#ifndef RTCTIMER_DEFINE
#define RTCTIMER_DEFINE

#include "AbstractOperation.h"
#include "Config.h"
class RTCTimer : public AbstractOperation
{
private:
    int32_t _minutes;
    int32_t Abs(int32_t number);
public:
    RTCTimer(uint8_t hour, uint8_t minute, Model* model);
    ~RTCTimer() override;
    void Execute() override;
    
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

#endif
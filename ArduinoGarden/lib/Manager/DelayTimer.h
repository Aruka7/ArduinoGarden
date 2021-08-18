#ifndef DELAYTIMER_DEFINE
#define DELAYTIMER_DEFINE

#include "AbstractOperation.h"
#include "ATimer.h"
class DelayTimer : public AbstractOperation
{
private:
    ATimer _timer;
    bool _isFirstExecuteComplete;
public:
    DelayTimer(uint32_t interval, Model* model);
    ~DelayTimer() override;
    void Execute() override;
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


#endif
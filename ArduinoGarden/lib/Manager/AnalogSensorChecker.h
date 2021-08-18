#ifndef SENSORCHECKER_DEFINE
#define SENSORCHECKER_DEFINE
# include "AbstractOperation.h"
class AnalogSensorChecker : public AbstractOperation
{
private:
    uint8_t _sensorNumber;
    bool _isExceccMode;
    int _threashold;
public:
    /*
    sensorNumber - Number of surveying sensor
    IsExceccMode - true mean that complete flag will reached when sensor value exceeds the setted mark
    threashold - threashold value
    */
    AnalogSensorChecker(uint8_t sensorNumber, bool isExceccMode, int threashold, Model* model);
    ~AnalogSensorChecker() override;
    void Execute() override;
};

AnalogSensorChecker::AnalogSensorChecker(uint8_t sensorNumber, bool isExceccMode, int threashold, Model* model) : AbstractOperation(model){
    _sensorNumber = sensorNumber;
    _isExceccMode = isExceccMode;
    _threashold = threashold;
}

void AnalogSensorChecker::Execute(){
    int tmp = model->_sensorsValueStorage->SurveySensor(_sensorNumber);
    if((_isExceccMode && tmp >= _threashold) || (!_isExceccMode && tmp <= _threashold)){
        IsCompleted = true;
    }
}

AnalogSensorChecker::~AnalogSensorChecker()
{
}

#endif
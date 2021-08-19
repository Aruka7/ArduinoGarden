#include "AnalogSensorChecker.h"

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
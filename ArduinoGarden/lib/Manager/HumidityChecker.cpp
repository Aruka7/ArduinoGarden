#include "HumidityChecker.h"
HumidityChecker::HumidityChecker( bool isExceccMode, int threashold, Model* model) : AbstractOperation(model){
    _isExceccMode = isExceccMode;
    _threashold = threashold;
}

void HumidityChecker::Execute(){
    model->_sensorsValueStorage->SurveyHumidity();
    int Humidity = (int)model->_sensorsValueStorage->GetHumidity();  
    if((_isExceccMode && Humidity >= _threashold) || (!_isExceccMode && Humidity <= _threashold)){
        IsCompleted = true;
    }
}
HumidityChecker::~HumidityChecker()
{
}

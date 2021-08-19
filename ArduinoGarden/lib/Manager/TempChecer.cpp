# include "TempChecer.h"
TempChecker::TempChecker( bool isExceccMode, int threashold, Model* model) : AbstractOperation(model){
    _isExceccMode = isExceccMode;
    _threashold = threashold;
}

void TempChecker::Execute(){
    
    model->_sensorsValueStorage->SurveyTemperature();
    int tmp = (int)model->_sensorsValueStorage->GetTemperature();  
    if((_isExceccMode && tmp >= _threashold) || (!_isExceccMode && tmp <= _threashold)){
        IsCompleted = true;
    }
}
TempChecker::~TempChecker(){
}
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

char* AnalogSensorChecker::GetString(){
    char* tmp = new char[11]{"S "};
    char number[1];
    itoa(_sensorNumber, number, DEC);
    strcat(tmp, number);
    strcat(tmp, " ");
    char excess[1];
    if(_isExceccMode){
        excess[0] = '>';
    }
    else{
        excess[0] = '<';
    }
    strcat(tmp, excess);
    strcat(tmp, " ");
    char value[4];
    itoa(_threashold, value, DEC);
    strcat(tmp, value);
    return tmp;
}
uint8_t AnalogSensorChecker::GetCursorPosition(){
    return _cursorPosition;
}
void AnalogSensorChecker::HandleCommand(EncoderAction action){
    if(action == EncoderAction::Left){
        if(_cursorPosition == 0) _cursorPosition = ANALOGCHECKER_CURSOR_POS_LENGTH;
        _cursorPosition--;
        return;
    }
    if(action == EncoderAction::Right){
        if(_cursorPosition == ANALOGCHECKER_CURSOR_POS_LENGTH - 1) {
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
            _sensorNumber--;
            if(_sensorNumber == 0) _sensorNumber = 4;
            return;
        case 2:
            _isExceccMode = !_isExceccMode;
            return;
        case 3:
            _threashold -= 32;
            if(_threashold < 0) _threashold = 1024;
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
            _sensorNumber++;
            if(_sensorNumber == 5) _sensorNumber = 1;
            return;
        case 2:
             _isExceccMode = !_isExceccMode;
        case 3:
            _threashold += 32;
            if(_threashold > 1024) _threashold = 0;
             return;
        default:
            break;
        }
    }
}

char* AnalogSensorChecker::GetString(){
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
uint8_t AnalogSensorChecker::GetCursorPosition(){
    return _cursorPosition;
}
void AnalogSensorChecker::HandleCommand(EncoderAction action){
    if(action == EncoderAction::Left){
        if(_cursorPosition == 0) _cursorPosition = ANALOGCHECKER_CURSOR_POS_LENGTH;
        _cursorPosition--;
        return;
    }
    if(action == EncoderAction::Right){
        if(_cursorPosition == ANALOGCHECKER_CURSOR_POS_LENGTH - 1) {
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
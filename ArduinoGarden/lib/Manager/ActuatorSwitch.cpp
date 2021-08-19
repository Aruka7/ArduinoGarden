#include "ActuatorSwitch.h"


ActuatorSwitch::ActuatorSwitch(bool switchingType, Model* model) : AbstractOperation(model){
    _switchingType = switchingType;
}

ActuatorSwitch::~ActuatorSwitch(){

}
void ActuatorSwitch::Execute(){

    model->_relayStatusStorage->SetActuator(_switchingType ? 1 : 0);
    IsCompleted = true;
}
char* ActuatorSwitch::GetString(){
    char* tmp = new char[10]{"ACT "};
    char switcher[5];
    if(_switchingType){
        strcat(switcher, "Open");
    }
    else{
        strcat(switcher, "Close");
    }
    strcat(tmp, switcher);
    return tmp;
}
uint8_t ActuatorSwitch::GetCursorPosition(){
    return _cursorPosition;
}
void ActuatorSwitch::HandleCommand(EncoderAction action){
    if(action == EncoderAction::Left){
        if(_cursorPosition == 0) _cursorPosition = ACTSWITCH_CURSOR_POS_LENGTH;
        _cursorPosition--;
        return;
    }
    if(action == EncoderAction::Right){
        if(_cursorPosition == ACTSWITCH_CURSOR_POS_LENGTH - 1) {
            _cursorPosition = 0;
            return;
        }
        _cursorPosition++;
        return;
    }
    if((action == EncoderAction::LeftHold) || (action == EncoderAction::RightHold)){
        switch (_cursorPosition)
        {
        case 0: return;
        case 1:
            _switchingType = !_switchingType;
            return;
        default:
            break;
        }
    }
}
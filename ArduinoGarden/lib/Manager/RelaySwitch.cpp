#include "RelaySwitch.h"


RelaySwitch::RelaySwitch(bool switchingType, uint8_t relayNumber, Model* model) : AbstractOperation(model){
    _switchingType = switchingType;
    _relayNumber = relayNumber;
    _cursorPosition = 0;
}

RelaySwitch::~RelaySwitch(){

}
void RelaySwitch::Execute(){

    model->_relayStatusStorage->SetRel(_relayNumber, _switchingType ? 1 : 0);
    IsCompleted = true;
}

char* RelaySwitch::GetString(){
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
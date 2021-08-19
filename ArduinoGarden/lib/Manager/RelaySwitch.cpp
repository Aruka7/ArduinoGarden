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
    
}
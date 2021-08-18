#include "RelaySwitch.h"


RelaySwitch::RelaySwitch(bool switchingType, uint8_t relayNumber, Model* model) : AbstractOperation(model){
    _switchingType = switchingType;
    _relayNumber = relayNumber;
}

RelaySwitch::~RelaySwitch(){

}
void RelaySwitch::Execute(){

    model->_relayStatusStorage->SetRel(_relayNumber, _switchingType ? 1 : 0);
    IsCompleted = true;
}
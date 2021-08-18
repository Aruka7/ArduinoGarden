#include "ActuatorSwitch.h".h"


ActuatorSwitch::ActuatorSwitch(bool switchingType, Model* model) : AbstractOperation(model){
    _switchingType = switchingType;
}

ActuatorSwitch::~ActuatorSwitch(){

}
void ActuatorSwitch::Execute(){

    model->_relayStatusStorage->SetActuator(_switchingType ? 1 : 0);
    IsCompleted = true;
}
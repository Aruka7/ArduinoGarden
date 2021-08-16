#ifndef RELAYSWITCH_DEFINE
#define RELAYSWITCH_DEFINE

#include "AbstractOperation.h"
#include <stdint.h>
#include "Model.h"
class RelaySwitch : public AbstractOperation
{
private:
    uint8_t _relayNumber;
    bool _switchingType; //Type of direction switching 1 is mean that relay will turn on and otherwise 0 mean off
public:
    RelaySwitch(bool switchingType, uint8_t relayNumber, Model* model);
    ~RelaySwitch() override;
    void Execute() override;
};

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
#endif
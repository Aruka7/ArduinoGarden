#ifndef RELAYSWITCH_DEFINE
#define RELAYSWITCH_DEFINE

#include "AbstractOperation.h"
#include <stdint.h>
#include "Model.h"
class RelaySwitch : public AbstractOperation
{
private:
    uint8_t _relayPin;
    bool _switchingType; //Type of direction switching 1 is mean that relay will turn on and otherwise 0 mean off
public:
    RelaySwitch(bool switchingType, uint8_t relayPin, Model* model);
    ~RelaySwitch() override;
    void Execute() override;
};

RelaySwitch::RelaySwitch(bool switchingType, uint8_t relayPin, Model* model) : AbstractOperation(model){
    _switchingType = switchingType;
    _relayPin = relayPin;
}

RelaySwitch::~RelaySwitch(){

}
RelaySwitch::Execute(){

    
    IsCompleted = true;
}
#endif
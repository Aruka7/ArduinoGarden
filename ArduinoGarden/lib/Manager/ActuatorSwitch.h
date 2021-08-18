#ifndef ACTSWITCH_DEFINE
#define ACTSWITCH_DEFINE

#include "AbstractOperation.h"
#include <stdint.h>
#include "Model.h"
class ActuatorSwitch : public AbstractOperation
{
private:
    bool _switchingType; //Type of direction switching 1 is mean that act will turn outside and otherwise 0 mean inside
public:
    ActuatorSwitch(bool switchingType, Model* model);
    ~ActuatorSwitch() override;
    void Execute() override;
};

#endif
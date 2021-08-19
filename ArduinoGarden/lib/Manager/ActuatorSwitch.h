#ifndef ACTSWITCH_DEFINE
#define ACTSWITCH_DEFINE

#include "AbstractOperation.h"
#include <stdint.h>
#include "Model.h"
#define ACTSWITCH_CURSOR_POS_LENGTH 2
class ActuatorSwitch : public AbstractOperation
{
private:
    uint8_t _cursorPosition;
    uint8_t _cursorPositions[ACTSWITCH_CURSOR_POS_LENGTH] 
    = {0, 4};
    bool _switchingType; //Type of direction switching 1 is mean that act will turn outside and otherwise 0 mean inside
public:
    ActuatorSwitch(bool switchingType, Model* model);
    ~ActuatorSwitch() override;
    void Execute() override;
    char* GetString() override;
    uint8_t GetCursorPosition() override;
    void HandleCommand(EncoderAction action) override;
};

#endif
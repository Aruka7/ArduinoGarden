#ifndef RELAYSWITCH_DEFINE
#define RELAYSWITCH_DEFINE

#include "AbstractOperation.h"
#include <stdint.h>
#include "Model.h"
class RelaySwitch : public AbstractOperation
{
private:
uint8_t _cursorPosition;
    uint8_t _cursorPositions[3] = {0, 2, 4};
    uint8_t _relayNumber;
    bool _switchingType; //Type of direction switching 1 is mean that relay will turn on and otherwise 0 mean off
public:
    RelaySwitch(bool switchingType, uint8_t relayNumber, Model* model);
    ~RelaySwitch() override;
    void Execute() override;
    char* GetString() override;
    uint8_t GetCursorPosition() override;
    void HandleCommand(EncoderAction action) override;
};

#endif
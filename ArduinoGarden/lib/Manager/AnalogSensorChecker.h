#ifndef SENSORCHECKER_DEFINE
#define SENSORCHECKER_DEFINE
# include "AbstractOperation.h"
#define ANALOGCHECKER_CURSOR_POS_LENGTH 4
class AnalogSensorChecker : public AbstractOperation
{
private:
    uint8_t _sensorNumber;
    bool _isExceccMode;
    int _threashold;
    uint8_t _cursorPosition;
    uint8_t _cursorPositions[ANALOGCHECKER_CURSOR_POS_LENGTH] 
    = {0, 2, 4, 6};
public:
    /*
    sensorNumber - Number of surveying sensor
    IsExceccMode - true mean that complete flag will reached when sensor value exceeds the setted mark
    threashold - threashold value
    */
    AnalogSensorChecker(uint8_t sensorNumber, bool isExceccMode, int threashold, Model* model);
    ~AnalogSensorChecker() override;
    void Execute() override;
    char* GetString() override;
    uint8_t GetCursorPosition() override;
    void HandleCommand(EncoderAction action) override;
};



#endif
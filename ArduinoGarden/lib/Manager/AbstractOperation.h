#ifndef ABSTRACTOPERATION_DEFINE
#define ABSTRACTOPERATION_DEFINE

#include "Model.h"
#include "PublisherObserver.h"

class Model;
class AbstractOperation : public IEncoderObserver {
public:
    Model* model;
    bool IsCompleted;
    virtual void Execute()=0;
    virtual char* GetString()=0;
    virtual uint8_t GetCursorPosition()=0;
    virtual void HandleCommand(EncoderAction action) = 0;

    AbstractOperation(Model* model);
    virtual ~AbstractOperation()=0;
};
#endif
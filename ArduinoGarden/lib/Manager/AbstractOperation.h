#ifndef AO_DEFINE
#define AO_DEFINE

#include "Model.h"

class AbstractOperation{
public:
    Model* model;
    bool IsCompleted;
    virtual void Execute()=0;
    virtual char* GetString()=0;
    virtual uint8_t GetCursorPosition()=0;

    AbstractOperation(Model* model);
    virtual  ~AbstractOperation()=0;
};
#endif
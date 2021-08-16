#ifndef AO_DEFINE
#define AO_DEFINE

#include "Model.h"

class AbstractOperation{
public:
    Model* model;
    bool IsCompleted;
    virtual void Execute()=0;
    AbstractOperation(Model* model);
    virtual  ~AbstractOperation()=0;
};
#endif
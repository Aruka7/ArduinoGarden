#include "AbstractOperation.h"
AbstractOperation :: AbstractOperation(Model* model){
    this->model = model;
    IsCompleted = false;
}
AbstractOperation :: ~AbstractOperation(){}; 
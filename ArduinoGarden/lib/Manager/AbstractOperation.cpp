#include "AbstractOperation.h"
AbstractOperation :: AbstractOperation(Model* model){
    this->model = model;
    IsComplete = false;
}
AbstractOperation :: ~AbstractOperation(){}; 
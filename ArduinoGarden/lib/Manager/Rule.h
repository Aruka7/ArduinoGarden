#ifndef RULE_DEFINE
#define RULE_DEFINE

//#include "AbstractOperation.h"
#include "ListClass.h"

#include "PublisherObserver.h"
class AbstractOperation;
class Rule {
private:
    List<AbstractOperation> _listOperation;
public:
    void BypassSequence(){
        _listOperation.SetStart();
        AbstractOperation* tmp = _listOperation.Next();
        while (tmp!= nullptr)
        {
            if(!tmp->IsCompleted){
                tmp->Execute();
            }
            if(!tmp->IsCompleted) return;
            tmp = _listOperation.Next();
        }
        
    }
};
#endif

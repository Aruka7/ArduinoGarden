#ifndef RULESTORAGE_DEFINE
#define RULESTORAGE_DEFINE
#include "ListClass.h"
#include "Rule.h"
class Rule;
class RulesStorage{ 
private:
    List<Rule> _listRule;
public:
    void Execute(){
        _listRule.SetStart();
        Rule* tmp = _listRule.Next();
        while (tmp != nullptr)
        {
            tmp->BypassSequence();
        }
        
    }
    
};
#endif
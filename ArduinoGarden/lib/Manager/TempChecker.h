#ifndef TEMPCHECKER_DEFINE
#define TEMPCHECKER_DEFINE
# include "AbstractOperation.h"
class TempChecker : public AbstractOperation
{
private:
    bool _isExceccMode;
    int _threashold;
public:
    TempChecker( bool isExceccMode, int threashold, Model* model);
    ~TempChecker() override;
    void Execute() override;
};


#endif
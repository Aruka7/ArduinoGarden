#ifndef HUMIDITYCHECKER_DEFINE
#define HUMIDITYCHECKER_DEFINE
# include "AbstractOperation.h"
class HumidityChecker : public AbstractOperation
{
private:
    bool _isExceccMode;
    int _threashold;
public:
    HumidityChecker( bool isExceccMode, int threashold, Model* model);
    ~HumidityChecker() override;
    void Execute() override;
};

#endif
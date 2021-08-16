#ifndef MODEL_DEFINE
#define MODEL_DEFINE


#include "RelaysStatusStorage.h"
#include "TimeStorage.h"
#include "SensorsValueStorage.h"
#include "RulesStorage.h"

class Model {
public:
	SensorsValueStorage* _sensorsValueStorage;
	RelayStatusStorage* _relayStatusStorage;
	TimeStorage* _timeStorage;
	RulesStorage* _rulesStorege;
	Model();

};
#endif

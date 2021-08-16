#include "Model.h"


Model::Model() {
	_sensorsValueStorage = new SensorsValueStorage();
	_relayStatusStorage = new RelayStatusStorage();
	_timeStorage = new TimeStorage();
	_rulesStorege = new RulesStorage();
}

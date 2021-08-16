#ifndef MANAGER_DEFINE
#define MANAGER_DEFINE


#include "Config.h"
#include "Enums.h"

#include "GyverEncoder.h"
#include <LiquidCrystal_I2C.h>

#include "ATimer.h"
#include "ListClass.h"
#include "PublisherObserver.h"
#include "Command.h"
#include "Model.h"

#include "AbstractDisplayView.h"
#include "DebugView.h"
#include "ServiceView.h"

class MainManager {
private:
	Model* _model; 
	AbstractDisplay* _display; 
	LiquidCrystal_I2C* _lcd; 
	Encoder* _enc;
	ATimer sensors_check_timer; 
	IPublisher* _encActionPublisher; 
public:
	MainManager();
	void CheckEncoder(); 
	void ChangeDisplayToService(); 
	void ChangeDisplayToDebug(); 
	void CheckSensors(); 
	void TestMessage();
};
#endif

#include "RelaysStatusStorage.h"
#include "Config.h"
RelayStatusStorage :: RelayStatusStorage() {
	_pwm = ACTUATOR_PWM;
	_actuatorWorkTimer.SetInterval(ACTUATOR_WORK_PERIOD);
	Rel1 = 0;
	Rel2 = 0;
	Rel3 = 0;
	Rel4 = 0;
	Rel5 = 0;
	Rel6 = 0;
	Rel7 = 0;
	Actuator = 0;
	pinMode(REL1, OUTPUT);
	pinMode(REL2, OUTPUT);
	pinMode(REL3, OUTPUT);
	pinMode(REL4, OUTPUT);
	pinMode(REL5, OUTPUT);
	pinMode(REL6, OUTPUT);
	pinMode(REL7, OUTPUT);
	pinMode(ACTIN1, OUTPUT);
	pinMode(ACTIN2, OUTPUT);
	pinMode(ACT_PWM, OUTPUT);
}
uint8_t RelayStatusStorage :: GetRel1Status() { return Rel1; }
uint8_t RelayStatusStorage :: GetRel2Status() { return Rel2; }
uint8_t RelayStatusStorage :: GetRel3Status() { return Rel3; }
uint8_t RelayStatusStorage :: GetRel4Status() { return Rel4; }
uint8_t RelayStatusStorage :: GetRel5Status() { return Rel5; }
uint8_t RelayStatusStorage :: GetRel6Status() { return Rel6; }
uint8_t RelayStatusStorage :: GetRel7Status() { return Rel7; }
uint8_t RelayStatusStorage :: GetActuatorStatus() { return Actuator; }

void RelayStatusStorage :: SetRel1(uint8_t value) {
	digitalWrite(REL1, value);
	Rel1 = value;
}
void RelayStatusStorage :: SetRel2(uint8_t value) {
	digitalWrite(REL2, value);
	Rel2 = value;
	}
void RelayStatusStorage :: SetRel3(uint8_t value) {
	digitalWrite(REL3, value);
	Rel3 = value;
}
void RelayStatusStorage :: SetRel4(uint8_t value) {
	digitalWrite(REL4, value);
	Rel4 = value;
}
void RelayStatusStorage :: SetRel5(uint8_t value) {
	digitalWrite(REL5, value);
	Rel5 = value;
}
void RelayStatusStorage :: SetRel6(uint8_t value) {
	digitalWrite(REL6, value);
	Rel6 = value;
}
void RelayStatusStorage :: SetRel7(uint8_t value) {
	digitalWrite(REL7, value);
	Rel7 = value;
}
void RelayStatusStorage :: SetActuator(uint8_t value) {
	if (value == 1) digitalWrite(ACTIN1, 1);
	else digitalWrite(ACTIN2, 1); //todo ïðî÷åêàòü ìîæåò ïîìåíÿòü ïðèäåòñÿ ïèíû
	analogWrite(ACT_PWM, _pwm);
	_actuatorWorkTimer.Start();
	Actuator = value;
	//_threadHandler.AddTask(StopActuator, 8); //todo Ðàáîòàòü íå áóäåò íàäî äîáèòü
}

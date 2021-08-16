#ifndef RSS_DEFINE
#define RSS_DEFINE
#include "ATimer.h"
#include "Config.h"
class RelayStatusStorage {
private:
	uint8_t Rel1;
	uint8_t Rel2;
	uint8_t Rel3;
	uint8_t Rel4;
	uint8_t Rel5;
	uint8_t Rel6;
	uint8_t Rel7;
	uint8_t Actuator;

	uint8_t _pwm; //���������� ���� � ������� ����� ����������� ��������
	ATimer _actuatorWorkTimer; //������ �������������� ������ ���������
public:
	RelayStatusStorage();
	uint8_t GetRel1Status();
	uint8_t GetRel2Status();
	uint8_t GetRel3Status();
	uint8_t GetRel4Status();
	uint8_t GetRel5Status();
	uint8_t GetRel6Status();
	uint8_t GetRel7Status();
	uint8_t GetActuatorStatus();

	void SetRel1(uint8_t value);
	void SetRel2(uint8_t value);
	void SetRel3(uint8_t value);
	void SetRel4(uint8_t value);
	void SetRel5(uint8_t value);
	void SetRel6(uint8_t value);
	void SetRel7(uint8_t value);
	void SetActuator(uint8_t value);

	void SetRel(uint8_t relayNumber, uint8_t value);


};
#endif

#ifndef SVS1_DEFINE
#define SVS1_DEFINE

#include<Arduino.h>
#include<stdint.h>

#include "Config.h"

class SensorsValueStorage {
private:
#if DHTISENABLE == 1
	DHT* dht;
#endif
	int Sens1_value;
	int Sens2_value;
	int Sens3_value;
	int Sens4_value;
	//T and H
	float temperature;
	float humidity;

public:
	SensorsValueStorage();
	float GetTemperature();
	float GetHumidity();
	int GetSens1Value();
	int GetSens2Value();
	int GetSens3Value();
	int GetSens4Value();

	void SurveyAllSensors();
	//Survey sens 1
	void SurveySens1();
	//Survey sens 2
	void SurveySens2();
	//Survey sens 3
	void SurveySens3();
	//Survey sens 4
	void SurveySens4();

	int SurveySensor(uint8_t sensorNumber);
};


#endif // !SVS_DEFINE


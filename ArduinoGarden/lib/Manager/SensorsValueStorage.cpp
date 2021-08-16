#include "SensorsValueStorage.h"
#include "Config.h"

SensorsValueStorage::SensorsValueStorage() {
	pinMode(SENS_SUPPLY, OUTPUT);
#if DHTISENABLE == 1
	dht = new DHT(DHTPIN, DHT22);
	dht->begin();
#endif
}
float SensorsValueStorage::GetTemperature() { return temperature; }
float SensorsValueStorage::GetHumidity() { return humidity; }
int SensorsValueStorage::GetSens1Value() { return Sens1_value; }
int SensorsValueStorage::GetSens2Value() { return Sens2_value; }
int SensorsValueStorage::GetSens3Value() { return Sens3_value; }
int SensorsValueStorage::GetSens4Value() { return Sens4_value; }

void SensorsValueStorage::SurveyAllSensors() {
	digitalWrite(SENS_SUPPLY, 1);
	delay(SENS_DELAY);
	Sens1_value = analogRead(SENS1);
	Sens2_value = analogRead(SENS2);
	Sens3_value = analogRead(SENS3);
	Sens4_value = analogRead(SENS4);
#if DHTISENABLE == 1
	temperature = dht->readTemperature();
	humidity = dht->readHumidity();
#endif
	digitalWrite(SENS_SUPPLY, 0);
}

void SensorsValueStorage::SurveySens1() {
	digitalWrite(SENS_SUPPLY, 1);
	delay(SENS_DELAY);
	Sens1_value = analogRead(SENS1);
	digitalWrite(SENS_SUPPLY, 0);
}

void SensorsValueStorage::SurveySens2() {
	digitalWrite(SENS_SUPPLY, 1);
	delay(SENS_DELAY);
	Sens2_value = analogRead(SENS2);
	digitalWrite(SENS_SUPPLY, 0);
}

void SensorsValueStorage::SurveySens3() {
	digitalWrite(SENS_SUPPLY, 1);
	delay(SENS_DELAY);
	Sens3_value = analogRead(SENS3);
	digitalWrite(SENS_SUPPLY, 0);
}

void SensorsValueStorage::SurveySens4() {
	digitalWrite(SENS_SUPPLY, 1);
	delay(SENS_DELAY);
	Sens4_value = analogRead(SENS4);
	digitalWrite(SENS_SUPPLY, 0);
}

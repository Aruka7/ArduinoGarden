#ifndef TIMESTORAGE_DEFINE
#define TIMESTORAGE_DEFINE

#include <iarduino_RTC.h>
#include <DHT.h>
class TimeStorage {
private:
	iarduino_RTC* watch;
	//�����
	uint8_t hour;
	uint8_t minute;
	uint8_t second;
	uint8_t day;
	uint8_t month;
	uint8_t year;
	uint8_t weekday;

public:
	TimeStorage();

	void SurveyTime();
	uint8_t GetHour();
	uint8_t GetMinute();
	uint8_t GetSecond();
	uint8_t GetDay();
	uint8_t GetMonth();
	uint8_t GetYear();
	uint8_t GetWeekday();

	void SetTime(uint8_t second, uint8_t minute, uint8_t hour, uint8_t day, uint8_t month, uint8_t year, uint8_t weekday);

	~TimeStorage();
};
#endif

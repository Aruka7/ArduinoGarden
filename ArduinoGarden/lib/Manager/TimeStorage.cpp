#include "TimeStorage.h"

TimeStorage::TimeStorage() {
	watch = new iarduino_RTC(RTC_DS3231);
	watch->begin();
}

void TimeStorage::SurveyTime() {
	watch->gettime();
	hour = watch->Hours;
	minute = watch->minutes;
	second = watch->seconds;
	day = watch->day;
	month = watch->month;
	year = watch->year;
	weekday = watch->weekday;
}
uint8_t TimeStorage::GetHour() { return hour; }
uint8_t TimeStorage::GetMinute() { return minute; }
uint8_t TimeStorage::GetSecond() { return second; }
uint8_t TimeStorage::GetDay() { return day; }
uint8_t TimeStorage::GetMonth() { return month; }
uint8_t TimeStorage::GetYear() { return year; }
uint8_t TimeStorage::GetWeekday() { return weekday; }

void TimeStorage::SetTime(uint8_t second, uint8_t minute, uint8_t hour, uint8_t day, uint8_t month, uint8_t year, uint8_t weekday) {
	watch->settime(second, minute, hour, day, month, year, weekday);
}

TimeStorage::~TimeStorage() {
	delete watch;
}

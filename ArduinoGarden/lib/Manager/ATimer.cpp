#include"ATimer.h"

ATimer::ATimer(){
	_interval = 1000;
	_lastMillis = millis();
}
void ATimer::SetInterval(uint32_t interval) {
	_status = ATimerStatus::STOPPED;
	_interval = interval;
}

void ATimer::Start() {
	_lastMillis = millis();
	_status = ATimerStatus::RUNNING;
}

ATimerStatus ATimer::CheckTimer() {
	if (_status == ATimerStatus::RUNNING && millis() - _lastMillis > _interval) {
		_status = ATimerStatus::STOPPED;
		return ATimerStatus::EXPIRED;
	}
	if (_status == ATimerStatus::EXPIRED) {
		_status = ATimerStatus::STOPPED;
		return ATimerStatus::EXPIRED;
	}
	return _status;
}
void ATimer::ReleaseTimer() {
	_status = ATimerStatus::EXPIRED;
}

uint32_t ATimer::GetInterval(){
	return _interval;
}
uint32_t ATimer::GetLeftTime(){
	if(_status == ATimerStatus::EXPIRED || _status == ATimerStatus::STOPPED || millis() - _lastMillis > _interval){
		return 0;
	}
	return _interval - (millis() - _lastMillis);
}

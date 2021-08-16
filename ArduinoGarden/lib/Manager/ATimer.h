#ifndef TIMER_DEFINE
#define TIMER_DEFINE
#include <stdint.h>
#include <Arduino.h>
enum ATimerStatus {
	RUNNING,
	STOPPED,
	EXPIRED,
};
class ATimer {
private:
	ATimerStatus _status;
	uint32_t _interval;
	uint32_t _lastMillis;
public:
	void SetInterval(uint32_t interval);
	void Start();
	ATimerStatus CheckTimer();
	void ReleaseTimer();
};
#endif

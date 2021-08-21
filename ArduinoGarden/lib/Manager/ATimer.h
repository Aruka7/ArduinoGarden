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
	ATimer();
	void SetInterval(uint32_t interval);
	uint32_t GetInterval();
	uint32_t GetLeftTime();
	void Start();
	ATimerStatus CheckTimer();
	void ReleaseTimer();
};
#endif

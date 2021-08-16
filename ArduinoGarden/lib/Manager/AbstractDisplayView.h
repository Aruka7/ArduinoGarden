#ifndef ADV_DEFINE
#define ADV_DEFINE
//#include <stdint.h>
//#include <Arduino.h>
#include "Enums.h"
#include <LiquidCrystal_I2C.h>
#include "PublisherObserver.h"
#include "Model.h"

class AbstractDisplay : public IEncoderObserver {
protected:
	LiquidCrystal_I2C* lcd; //store lcd display main class
	Model* model;

public:
	AbstractDisplay(LiquidCrystal_I2C* lcd, Model* model);
	virtual void Draw() = 0; //drawing display
	virtual void HandleCommand(EncoderAction action) = 0; //Handling encoder action
	virtual ~AbstractDisplay() = 0;
};
#endif

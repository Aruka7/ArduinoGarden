#include "AbstractDisplayView.h"

AbstractDisplay::AbstractDisplay(LiquidCrystal_I2C* lcd, Model* model) {
	this->lcd = lcd;
	this->model = model;
}
AbstractDisplay::~AbstractDisplay() {};

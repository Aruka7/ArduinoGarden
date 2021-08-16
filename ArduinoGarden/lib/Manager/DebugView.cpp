#include "DebugView.h"

DebugView::DebugView(LiquidCrystal_I2C* lcd, Model* model, ICommand* changeToNextDisplay) : AbstractDisplay(lcd, model) {
	_changeToNextDisplay = changeToNextDisplay;
}
DebugView::~DebugView() {
	delete _changeToNextDisplay;
}

void DebugView::Draw() {
	lcd->clear();
	lcd->setCursor(0, 0);
	lcd->write(1);
	lcd->setCursor(1, 0);
	lcd->print("DEBUG");
	lcd->setCursor(7, 0);
	lcd->print("T:");
	lcd->setCursor(9, 0);
#if DHTISENABLE == 1
	if (isnan(model->_sensorsValueStorage->GetTemperature())) lcd->print("-"); else lcd->print((uint8_t)_statusStore->temperature);
#else
	lcd->print("-");
#endif
	lcd->setCursor(12, 0);
	lcd->print("H:");
	lcd->setCursor(14, 0);
#if DHTISENABLE == 1
	if (isnan(_statusStore->humidity)) lcd->print("-"); else lcd->print((uint8_t)_statusStore->humidity);
#else
	lcd->print("-");
#endif
	//������������ �������� � ��������
	lcd->setCursor(0, 1);
	lcd->print(model->_sensorsValueStorage->GetSens1Value());
	lcd->setCursor(5, 1);
	lcd->print(model->_sensorsValueStorage->GetSens2Value());
	lcd->setCursor(10, 1);
	lcd->print(model->_sensorsValueStorage->GetSens3Value());
	lcd->setCursor(15, 1);
	lcd->print(model->_sensorsValueStorage->GetSens4Value());
	//������������ ��������� �����
	lcd->setCursor(0, 2);
	lcd->print("REL:");
	lcd->setCursor(4, 2);
	lcd->print(model->_relayStatusStorage->GetRel1Status());
	lcd->setCursor(5, 2);
	lcd->print(model->_relayStatusStorage->GetRel2Status());
	lcd->setCursor(6, 2);
	lcd->print(model->_relayStatusStorage->GetRel3Status());
	lcd->setCursor(7, 2);
	lcd->print(model->_relayStatusStorage->GetRel4Status());
	lcd->setCursor(8, 2);
	lcd->print(model->_relayStatusStorage->GetRel5Status());
	lcd->setCursor(9, 2);
	lcd->print(model->_relayStatusStorage->GetRel6Status());
	lcd->setCursor(10, 2);
	lcd->print(model->_relayStatusStorage->GetRel7Status());
	//������������ �����
	lcd->setCursor(0, 3);
	lcd->print(model->_timeStorage->GetHour());
	lcd->print(":");
	lcd->print(model->_timeStorage->GetMinute());
	lcd->print(":");
	lcd->print(model->_timeStorage->GetSecond());
	lcd->print(" ");
	lcd->print(model->_timeStorage->GetWeekday());
	lcd->print(" ");
	lcd->print(model->_timeStorage->GetDay());
	lcd->print(":");
	lcd->print(model->_timeStorage->GetMonth());
	lcd->print(":");
	lcd->print(model->_timeStorage->GetYear());
}

void DebugView::HandleCommand(EncoderAction action) {
	if (action == EncoderAction::Release) return;
	if (action == EncoderAction::RightHold) _changeToNextDisplay->Execute();
}

#include "Manager.h"
#include "CreatedChars.h"
MainManager::MainManager() {
	//todo ������� � ��������� ������ ��� �����

	_model = new Model();
	_lcd = new LiquidCrystal_I2C(DISPLAY_ADDRESS, DISPLAY_COLUMNS, DISPLAY_ROWS);
	_encActionPublisher = new EncoderActionPublisher();
	_display = new DebugView(_lcd, _model, new ChangeDisplayToServiceCommand(this));
	_encActionPublisher->Attach(_display);
	_enc = new Encoder(CLK, DT, SW);

	_lcd->createChar(1, arrowSymbol); 
	_lcd->init();               
	_lcd->backlight();       
	_lcd->noAutoscroll();       

	_enc->setType(TYPE2);

	sensors_check_timer.SetInterval(SENSORS_CHECK_PERIOD);
	sensors_check_timer.Start();
}

void MainManager::CheckEncoder() {
	_enc->tick();
	EncoderAction command = EncoderAction::Release;
	if (_enc->isRight()) command = EncoderAction::Right;         // ���� ��� �������
	if (_enc->isLeft()) command = EncoderAction::Left;
	if (_enc->isRightH()) command = EncoderAction::RightHold;  // ���� ���� ��������� + �������
	if (_enc->isLeftH()) command = EncoderAction::LeftHold;
	if (_enc->isPress()) command = EncoderAction::Press;          // ������� �� ������ (+ �������)
	if (command == EncoderAction::Release) return;
	_encActionPublisher->Notify(command); //��������� ���� ����������� � ������� ��������
}

void MainManager::ChangeDisplayToService() {
	_encActionPublisher->Detach(_display);
	delete _display;
	_display = new ServiceView(_lcd, _model, new ChangeDisplayToDebugCommand(this), new ChangeDisplayToDebugCommand(this));
	_encActionPublisher->Attach(_display);
	_display->Draw();
}

void MainManager::ChangeDisplayToDebug() {
	_encActionPublisher->Detach(_display);
	delete _display;
	_display = new DebugView(_lcd, _model, new ChangeDisplayToServiceCommand(this));
	_encActionPublisher->Attach(_display);
	_display->Draw();
}

void MainManager::CheckSensors() {
	if (sensors_check_timer.CheckTimer() == ATimerStatus::EXPIRED) {
		sensors_check_timer.Start();
		_model->_sensorsValueStorage->SurveyAllSensors();
		_model->_timeStorage->SurveyTime();
		_display->Draw();
		
	}
}

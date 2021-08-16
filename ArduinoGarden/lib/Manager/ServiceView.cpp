#include "ServiceView.h"

ServiceView::ServiceView(LiquidCrystal_I2C* lcd, Model* model, ICommand* changeToNextDisplay, ICommand* changeToPreviosDisplay) : AbstractDisplay(lcd, model) {
	_pos = 0;
	_changeToNextDisplay = changeToNextDisplay;
	_changeToPreviosDisplay = changeToPreviosDisplay;
	AllowDrawingTimeFlag = true;
	TimeIsUpdated = false;
}

ServiceView::~ServiceView(){
	delete _changeToNextDisplay;
	delete _changeToPreviosDisplay;
}

void ServiceView::Draw(){
	lcd->clear();
	lcd->setCursor(1, 0);
	lcd->print("SERVICE");
	lcd->setCursor(0, 1);
	//������
	lcd->print("RELAY:");
	lcd->setCursor(1, 2);
	lcd->print(model->_relayStatusStorage->GetRel1Status());
	lcd->setCursor(3, 2);
	lcd->print(model->_relayStatusStorage->GetRel2Status());
	lcd->setCursor(5, 2);
	lcd->print(model->_relayStatusStorage->GetRel3Status());
	lcd->setCursor(7, 2);
	lcd->print(model->_relayStatusStorage->GetRel4Status());
	lcd->setCursor(9, 2);
	lcd->print(model->_relayStatusStorage->GetRel5Status());
	lcd->setCursor(11, 2);
	lcd->print(model->_relayStatusStorage->GetRel6Status());
	lcd->setCursor(13, 2);
	lcd->print(model->_relayStatusStorage->GetRel7Status());
	//��������
	lcd->setCursor(0, 3);
	lcd->print("A:");
	lcd->setCursor(3, 3);
	lcd->print(model->_relayStatusStorage->GetActuatorStatus());
	//����� � ����
	if (AllowDrawingTimeFlag) {
		lcd->setCursor(11, 0);
		lcd->print(model->_timeStorage->GetHour());
		lcd->setCursor(13, 0);
		lcd->print(":");
		lcd->print(model->_timeStorage->GetMinute());
		lcd->setCursor(16, 0);
		lcd->print(":");
		lcd->print(model->_timeStorage->GetSecond());
		lcd->setCursor(11, 1);
		lcd->print(model->_timeStorage->GetDay());
		lcd->setCursor(13, 1);
		lcd->print(":");
		lcd->print(model->_timeStorage->GetMonth());
		lcd->setCursor(16, 1);
		lcd->print(":");
		lcd->print(model->_timeStorage->GetYear());
		lcd->setCursor(18, 2);
		lcd->print(model->_timeStorage->GetWeekday());
	} //������� ��������� ��� ������������
	else {
		lcd->setCursor(11, 0);
		lcd->print(hour);
		lcd->setCursor(13, 0);
		lcd->print(":");
		lcd->print(minute);
		lcd->setCursor(16, 0);
		lcd->print(":");
		lcd->print(second);
		lcd->setCursor(11, 1);
		lcd->print(day);
		lcd->setCursor(13, 1);
		lcd->print(":");
		lcd->print(month);
		lcd->setCursor(16, 1);
		lcd->print(":");
		lcd->print(year);
		lcd->setCursor(18, 2);
		lcd->print(weekday);
	}
	//������ ������
	lcd->setCursor(_cursorPositions[_pos][0], _cursorPositions[_pos][1]);
	lcd->write(1);
}

void ServiceView::HandleCommand(EncoderAction action){
	if (action == EncoderAction::Release) return;
	bool flag = false; //���� ���������� �������� �������
	if (_pos >= TIME_LIMIT_POSITION) flag = true; //� 9�� ���������� ������� ��������� �������

	if (action == EncoderAction::Right) { // ������ �� �������, ������� �� ����� �������
		if (_pos < COUNT_CURSOR_POSITIONS_SERVICE - 1)_pos++;
		else _pos = 0;
	}
	if (action == EncoderAction::Left) { //�� ���� ���� �� �������
		if (_pos > 0)_pos--;
		else _pos = COUNT_CURSOR_POSITIONS_SERVICE - 1;
	}

	if (_pos < TIME_LIMIT_POSITION && flag) SaveTime(); //��������� ����� ���� ���������� �� ��������� ���������
	AllowDrawingTimeFlag = true; //��������� ��������� �����
	if (_pos < TIME_LIMIT_POSITION && (action == EncoderAction::RightHold || action == EncoderAction::LeftHold)) { //��������� ���� � ��������
		switch (_pos)
		{
		case 0:
			break;
		case 1:
			if (model->_relayStatusStorage->GetRel1Status() == 0) model->_relayStatusStorage->SetRel1(1);
			else model->_relayStatusStorage->SetRel1(0);
			break;
		case 2:
			if (model->_relayStatusStorage->GetRel2Status() == 0) model->_relayStatusStorage->SetRel2(1);
			else model->_relayStatusStorage->SetRel2(0);
			break;
		case 3:
			if (model->_relayStatusStorage->GetRel3Status() == 0) model->_relayStatusStorage->SetRel3(1);
			else model->_relayStatusStorage->SetRel3(0);
			break;
		case 4:
			if (model->_relayStatusStorage->GetRel4Status() == 0) model->_relayStatusStorage->SetRel4(1);
			else model->_relayStatusStorage->SetRel4(0);
			break;
		case 5:
			if (model->_relayStatusStorage->GetRel5Status() == 0) model->_relayStatusStorage->SetRel5(1);
			else model->_relayStatusStorage->SetRel5(0);
			break;
		case 6:
			if (model->_relayStatusStorage->GetRel6Status() == 0) model->_relayStatusStorage->SetRel6(1);
			else model->_relayStatusStorage->SetRel6(0);
			break;
		case 7:
			if (model->_relayStatusStorage->GetRel7Status() == 0) model->_relayStatusStorage->SetRel7(1);
			else model->_relayStatusStorage->SetRel7(0);
			break;
		default:
			break;
		}
		//todo �������� ��������
	}
	if (_pos < TIME_LIMIT_POSITION) return; //���� �� ����� �� ��������� ������� ������ ������ ������
	AllowDrawingTimeFlag = false; //���� �����, �� ���� �������� �������
	if (!flag && _pos >= TIME_LIMIT_POSITION) { //���� �� ����� �� �������� � ��������� ������� � ��� �����
		hour = model->_timeStorage->GetHour();
		minute = model->_timeStorage->GetMinute();
		second = model->_timeStorage->GetSecond();
		day = model->_timeStorage->GetDay();
		month = model->_timeStorage->GetMonth();
		year = model->_timeStorage->GetYear();
		weekday = model->_timeStorage->GetWeekday();
	}
	if (action == EncoderAction::RightHold) { //������ ���� ++
		TimeIsUpdated = true;
		switch (_pos)
		{
		case 9:
			hour++;
			if (hour >= 24) hour = 0;
			break;
		case 10:
			minute++;
			if (minute >= 60) minute = 0;
			break;
		case 11:
			second++;
			if (second >= 60) second = 0;
			break;
		case 12:
			day++;
			if (day >= 32) second = 0;
			break;
		case 13:
			month++;
			if (month >= 13) month = 1;
			break;
		case 14:
			year++;
			if (year >= 100) year = 0;
			break;
		case 15:
			weekday++;
			if (weekday >= 7) weekday = 0;
			break;
		default:
			break;
		}
	}
	if (action == EncoderAction::LeftHold) {    //������ ���� --
		TimeIsUpdated = true;
		switch (_pos)
		{
		case 9:
			if (hour == 1) hour = 23;
			else hour--;
			break;
		case 10:
			if (minute == 1) minute = 59;
			else minute--;
			break;
		case 11:
			if (second == 1) second = 59;
			else second--;
			break;
		case 12:
			if (day == 1) second = 31;
			else day--;
			break;
		case 13:
			if (month == 1) month = 12;
			else month--;
			break;
		case 14:
			if (year == 1) year = 99;
			else year--;
			break;
		case 15:
			if (weekday == 0)weekday = 6;
			else weekday--;
			break;
		default:
			break;
		}
	}
}

void ServiceView::SaveTime() {
	if (!TimeIsUpdated) return;
	TimeIsUpdated = false;
	model->_timeStorage->SetTime(second, minute, hour, day, month, year, weekday);
}

#ifndef SERVICEVIEW_DEFINE
#define SERVICEVIEW_DEFINE

#define COUNT_CURSOR_POSITIONS_SERVICE 16
#define TIME_LIMIT_POSITION 9
#include <Arduino.h>
#include <stdint.h>
#include "AbstractDisplayView.h"
#include "Model.h"
#include <LiquidCrystal_I2C.h>
#include "Command.h"
#include "Enums.h"


class ICommand;
class ServiceView : public AbstractDisplay {
private:
	uint8_t _cursorPositions[COUNT_CURSOR_POSITIONS_SERVICE][2] =
	{ {0,0}, {0,2}, {2,2}, {4,2}, {6,2}, {8,2}, {10,2}, {12,2}, {2,3}, {10,0}, {13,0}, {16,0}, {10,1}, {13,1}, {16,1}, {17,2} }; //������ ��������� �������
	uint8_t _pos; //����� �������
	ICommand* _changeToNextDisplay;
	ICommand* _changeToPreviosDisplay;
	//�����
	bool AllowDrawingTimeFlag;
	bool TimeIsUpdated;
	//������ ��������� �����
	uint8_t hour;
	uint8_t minute;
	uint8_t second;
	uint8_t day;
	uint8_t month;
	uint8_t year;
	uint8_t weekday;
public:
	ServiceView(LiquidCrystal_I2C* lcd, Model* model, ICommand* changeToNextDisplay, ICommand* changeToPreviosDisplay);
	~ServiceView() override;
	void Draw() override;
	void HandleCommand(EncoderAction action) override;
	void SaveTime();
};
#endif

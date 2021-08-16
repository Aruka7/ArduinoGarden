#ifndef COMMAND_DEFINE
#define COMMAND_DEFINE
#include "Manager.h"

class MainManager;

class ICommand {
public:
	virtual void Execute() = 0;
	virtual ~ICommand() = 0;
};
//��������� ���� �������
class ChangeDisplayToServiceCommand : public ICommand {
	MainManager* _manager;
	
public:
	ChangeDisplayToServiceCommand(MainManager* manager);
	void Execute() override;
	~ChangeDisplayToServiceCommand() override;
};
//��������� ���� ������
class ChangeDisplayToDebugCommand : public ICommand {
	MainManager* _manager;
public:
	ChangeDisplayToDebugCommand(MainManager* manager);
	void Execute() override;
	~ChangeDisplayToDebugCommand() override;
};
//todo ��������� ���� ��������

//todo ��������� ���� ������
#endif
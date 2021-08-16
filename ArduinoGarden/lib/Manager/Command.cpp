#include "Command.h"

ICommand::~ICommand(){};

ChangeDisplayToServiceCommand::ChangeDisplayToServiceCommand(MainManager* manager) {
	_manager = manager;
}
void ChangeDisplayToServiceCommand::Execute() {
	_manager->ChangeDisplayToService();
}
ChangeDisplayToServiceCommand::~ChangeDisplayToServiceCommand(){

}


ChangeDisplayToDebugCommand::ChangeDisplayToDebugCommand(MainManager* manager) {
	_manager = manager;
}
void ChangeDisplayToDebugCommand::Execute() {
	_manager->ChangeDisplayToDebug();
}

ChangeDisplayToDebugCommand::~ChangeDisplayToDebugCommand(){

}

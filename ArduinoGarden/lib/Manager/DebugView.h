#ifndef DEBUG_DEFINE
#define DEBUG_DEFINE
#include "AbstractDisplayView.h"
#include "Model.h"
#include <LiquidCrystal_I2C.h>
#include "Command.h"
#include "Enums.h"
//class IEncoderObserver;
//class AbstractDisplay;
class ICommand;
class DebugView : public AbstractDisplay {
private:
	ICommand* _changeToNextDisplay;
public:
	DebugView(LiquidCrystal_I2C* lcd, Model* model, ICommand* changeToNextDisplay);
	~DebugView() override;
	void Draw() override;
	void HandleCommand(EncoderAction action) override;

};
#endif

#ifndef RULESVIEW_DEBUG
#define RULESVIEW_DEBUG

#include "AbstractDisplayView.h"

class RulesView : public AbstractDisplay
{
private:
    /* data */
public:
    RulesView(LiquidCrystal_I2C* lcd, Model* model);
    ~RulesView() override;
    
	virtual void Draw() override; 
	virtual void HandleCommand(EncoderAction action) override; 
};

RulesView::RulesView(LiquidCrystal_I2C* lcd, Model* model) : AbstractDisplay(lcd, model){

}
RulesView::~RulesView(){}

void RulesView::Draw(){

}
void RulesView::HandleCommand(EncoderAction action){

}

#endif
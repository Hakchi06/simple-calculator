#include "controller/CalculatorController.h"
#include "model/CalculatorModel.h"
#include "view/CalculatorView.h"

CalculatorController::CalculatorController(CalculatorModel* model, CalculatorView* view) 
    : model(model), view(view) {
        view->setController(this);
}

CalculatorController::~CalculatorController() = default;

void CalculatorController::getButtonValue(const std::string& value){
    if(value == "AC"){
        model->clear();
        view->setDisplayText("");   
    } else if (value == "="){
        double result = model->calculate();
        view->setDisplayText(std::to_string(result));
    } else{
        model->setExpression(model->getExpression() + value);
        view->setDisplayText(model->getExpression());
    }
}
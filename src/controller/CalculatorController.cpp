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
        parenthesesClose = true;
    } else if (value == "="){
        if(parenthesesClose){
            double result = model->calculate();
            
            view->setDisplayText(std::to_string(result));
        }
    } else if(value == "del"){
        std::string del = model->getExpression();
        del.pop_back();
        model->setExpression(del);
        view->setDisplayText(model->getExpression());
    }else if(value == "()"){
         std::string expr = model->getExpression();

        int openCount = std::count(expr.begin(), expr.end(), '(');
        int closeCount = std::count(expr.begin(), expr.end(), ')');

        if (openCount == closeCount || expr.empty() || expr.back() == '(' || expr.back() == '+' || expr.back() == '-' || expr.back() == '*' || expr.back() == '/') {
            //handle when opencount and closecount are 0 or when last char is a number
            if (expr.back() == ')' || (!expr.empty() && expr.back() != '(')){
               expr += "*"; // implicit multiplication
            }
            model->setExpression(expr + "(");
            view->setDisplayText(model->getExpression());
            
            parenthesesClose = false;
        } else {
            model->setExpression(expr + ")");
            view->setDisplayText(model->getExpression());

            parenthesesClose = true;
        }
    } else {
        model->setExpression(model->getExpression() + value);
        view->setDisplayText(model->getExpression());
    }
    
}
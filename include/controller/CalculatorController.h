#ifndef CALCULATOR_CONTROLLER_H
#define CALCULATOR_CONTROLLER_H

#include <string>

class CalculatorModel; // Forward declaration
class CalculatorView;  // Forward declaration

class CalculatorController {
    private:
        CalculatorModel* model;
        CalculatorView* view;
    
    public:
        CalculatorController(CalculatorModel* model, CalculatorView* view);
        ~CalculatorController();
    
        void getButtonValue(const std::string& value);
};

#endif
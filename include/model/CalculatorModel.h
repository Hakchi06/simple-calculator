#ifndef CALCULATOR_MODEL_H
#define CALCULATOR_MODEL_H

#include <string>

class CalculatorModel{
    public:
        CalculatorModel();
        ~CalculatorModel();

        void setExpression(const std::string& expr);
        std::string getExpression() const;

        // void setSuffix();
        // std::string getSuffix() const;

        double calculate() const;
        void clear();

    private:
        std::string expression;
        //std::string suffix;
};

#endif
#include "model/CalculatorModel.h"
#include <stack>
#include <iostream>

// Auxiliary functions

std::stack<std::string> tokenize(std::string expr) {
    std::stack<std::string> tokens;
    std::string token = "";
    for (char c : expr) {
        if(c != ' '){
            token += c;
            continue;       // next character
        }
        tokens.push(token);
        token.clear();
    }
    tokens.push(token); // push the last token
    
    return tokens;
}

void invertStack(std::stack<std::string>& stack) {
    std::stack<std::string> tempStack;
    
    while(!stack.empty()){
  
        tempStack.push(stack.top());
        stack.pop();
    }

    stack = std::move(tempStack);
}

bool isNumber(char c) {
    return (c >= '0' && c <= '9') || c == '.';
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/' || op == '%') return 2;
    if (op == '^') return 3;
    return 0; // No es un operador válido
}


std::string toSuffix(const std::string& _expression){
    std::stack<char> operators;
    std::string output;
    std::string numberBuffer;

    for (const char& c : _expression) {
        if (isNumber(c)) {
            numberBuffer += c;        // append number directly to output

        } else{ 
            // if we have a number in the buffer, add it to the output
            if(!numberBuffer.empty()){
                output += numberBuffer + ' '; // add space to separate numbers
                numberBuffer.clear();
            }

            if(c == '('){     // left parenthesis
                operators.push(c);

            }else if(c == ')'){     // right parenthesis
                while(operators.top() != '('){
                    output += operators.top();
                    output += ' '; // add space to separate operators
                    operators.pop();
                }
                operators.pop();    // pop the left parenthesis
            } else {     // c is an operator
                while(!operators.empty() && precedence(c) <= precedence(operators.top()) && operators.top() != '(') {
                    output += operators.top();
                    output += ' ';
                    operators.pop();
                }
                operators.push(c); // push the current operator to the stack if the stack is empty or the precedence is higher than the top operator
            }
        }
    }

    // if we have a number in the buffer, add it to the output
    if(!numberBuffer.empty()){
        output += numberBuffer + ' '; // add the last number in the buffer
        numberBuffer.clear();
    }

    // if stack is not empty, pop all operators
    while(!operators.empty()){
        output += operators.top();
        output += ' ';
        operators.pop();
    }
    // Remove the trailing space if it exists
    output.pop_back();

    return output;
}



// CalculatorModel.cpp implementation

CalculatorModel::CalculatorModel() : expression("") {}
// CalculatorModel::CalculatorModel() : _expression(""), suffix("") {}
CalculatorModel::~CalculatorModel() = default;

void CalculatorModel::setExpression(const std::string& expr) {
    expression = expr;
}

std::string CalculatorModel::getExpression() const {
    return expression;
}

// void CalculatorModel::setSuffix(){
//     suffix = toSuffix(_expression);
// }

// std::string CalculatorModel::getSuffix() const {
//     return suffix;
// }

void CalculatorModel::clear() {
    expression.clear();
}

double CalculatorModel::calculate() const {
    std::stack<std::string> tokens = tokenize(toSuffix(expression));
    invertStack(tokens);

    std::stack<double> values;
    double result = 0.0;
    
    while(!tokens.empty()){
        std::string token = tokens.top();
        tokens.pop();

        if(token == "+" || token == "-" || token == "*" || token == "/"){
            double b = values.top(); values.pop();
            double a = values.top(); values.pop();

            if(token == "+") result = a + b;
            else if(token == "-") result = a - b;
            else if(token == "*") result = a * b;
            else if(token == "/") result = a / b;

            values.push(result);
        } else {
            values.push(std::stod(token));
        }
    }

    return result;
}
// #include "model/CalculatorModel.h"
// #include <iostream>
#include <FL/Fl.H>
#include "view/CalculatorView.h"

int main(){
    CalculatorView view(300, 400, "Calculadora MVC - FLTK");
    view.show();
    
    return Fl::run();
}
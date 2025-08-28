#include <FL/Fl.H>
#include "view/CalculatorView.h"
#include "model/CalculatorModel.h"
#include "controller/CalculatorController.h"

int main(){
    CalculatorView view(300, 400, "Simple Calculator");
    CalculatorModel model;
    CalculatorController controller(&model, &view);
    
    view.show();
    
    return Fl::run();
}
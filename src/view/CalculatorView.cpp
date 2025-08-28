#include "view/CalculatorView.h"
#include "controller/CalculatorController.h"


CalculatorView::CalculatorView(int width, int height, const char* title) {
    window = new Fl_Window(width, height, title);

    // field to display calculator input/output
    display = new Fl_Input(20, 20, width - 40, 40);
    display->readonly(1);
    display->value("hello world");

    // Create buttons
    int btnWidth = 60, btnHeight = 40;
    int xOffset = 20, yOffset = 80;

    const char* labels[] = {
        "AC", "()", "%", "/",
        "7", "8", "9", "*",
        "4", "5", "6", "-",
        "1", "2", "3", "+",
        "0", ".", "del", "="
    };

    for (int i = 0; i < sizeof(labels)/sizeof(labels[0]); ++i) {
        int row = i / 4;
        int col = i % 4;
        Fl_Button* btn = new Fl_Button(
            xOffset + col * (btnWidth + 10),
            yOffset + row * (btnHeight + 10),
            btnWidth, btnHeight,
            labels[i]
        );

        
        btn->labelfont(FL_HELVETICA);
        btn->labelsize(16);
        btn->callback(onButtonPressed, this); // set callback
        buttons.push_back(btn);
    }

    window->end();
}

CalculatorView::~CalculatorView() {
    delete window;
}

void CalculatorView::show() {
    window->show();
}
void CalculatorView::setDisplayText(const std::string& text) {
    display->value(text.c_str());
}

std::string CalculatorView::getDisplayText() const {
    return display->value();
}

void CalculatorView::clearDisplay() {
    display->value("");
}


// Callback for the clear button
void CalculatorView::onButtonPressed(Fl_Widget *w, void* data){
    CalculatorView* view = static_cast<CalculatorView*>(data);
    Fl_Button* button = (Fl_Button*)w;
    view->getButtonValue(button->label());
}

void CalculatorView::getButtonValue(const std::string& value){
    if(controller){
        controller->getButtonValue(value);
    }
}

void CalculatorView::setController(CalculatorController* controller){
    this->controller = controller;
}
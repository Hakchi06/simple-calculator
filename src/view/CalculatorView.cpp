#include "view/CalculatorView.h"


CalculatorView::CalculatorView(int width, int height, const char* title) {
    window = new Fl_Window(width, height, title);

    // Campo de texto para mostrar operaciones
    display = new Fl_Input(20, 20, width - 40, 40);
    display->readonly(1);
    display->value("hello world");

    // Crear botones
    int btnWidth = 60, btnHeight = 40;
    int xOffset = 20, yOffset = 80;

    const char* labels[] = {
        "7", "8", "9", "/",
        "4", "5", "6", "*",
        "1", "2", "3", "-",
        "0", ".", "=", "+"
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

        buttons.push_back(btn);
    }

    Fl_Button* clearButton = new Fl_Button(
        xOffset + 3 * (btnWidth + 10),
        yOffset + 4 * (btnHeight + 10),
        btnWidth, btnHeight,
        "C"
    );

    clearButton->callback(cb_clear, this);

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
void CalculatorView::cb_clear(Fl_Widget *w, void* data){
    CalculatorView* view = static_cast<CalculatorView*>(data);
    view->clearDisplay();
}
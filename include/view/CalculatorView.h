#ifndef VIEW_H
#define VIEW_H

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <vector>
#include <string>

class CalculatorView {
private:
    Fl_Window* window;
    Fl_Input* display;
    std::vector<Fl_Button*> buttons;

public:
    CalculatorView(int width, int height, const char* title);
    ~CalculatorView();

    void show();
    
    void setDisplayText(const std::string& text);
    std::string getDisplayText() const;
    void clearDisplay();
    static void cb_clear(Fl_Widget *w, void* data);     // call back for clear button
};

#endif

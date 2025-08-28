#ifndef CALCULATOR_VIEW_H
#define CALCULATOR_VIEW_H

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <vector>
#include <string>

class CalculatorController; // Forward declaration

class CalculatorView {
    private:
        Fl_Window* window;
        Fl_Input* display;
        std::vector<Fl_Button*> buttons;
        CalculatorController* controller;

    public:
        CalculatorView(int width, int height, const char* title);
        ~CalculatorView();

        void setController(CalculatorController* controller);
        void show();
        
        void setDisplayText(const std::string& text);
        std::string getDisplayText() const;
        void clearDisplay();
        static void onButtonPressed(Fl_Widget *w, void* data);     // call back
        void getButtonValue(const std::string& value);
};

#endif

cmake_minimum_required(VERSION 3.10)
project(CalculatorApp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_BUILD_TYPE Debug)

# Includes
include_directories(include /opt/fltk-mingw/include)

# Source files
set(SOURCES
    src/main.cpp
    src/view/CalculatorView.cpp
    src/model/CalculatorModel.cpp
    src/controller/CalculatorController.cpp
)

# Create the executable
add_executable(CalculatorApp ${SOURCES})

# Define macro for Windows
target_compile_definitions(CalculatorApp PRIVATE _WIN32_WINNT=0x0501)

# Compilation options
target_compile_options(CalculatorApp PRIVATE -g -O0)

# Libraries to link
target_link_libraries(CalculatorApp
    /opt/fltk-mingw/lib/libfltk.a
    /opt/fltk-mingw/lib/libfltk_forms.a
    /opt/fltk-mingw/lib/libfltk_images.a
    user32
    gdi32
    ws2_32
    gdiplus
    comctl32
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc -static-libstdc++")
# Vex v5 Pro BrainScreen Essentials
Adds framework for buttons and pages for the brain screen when using vex v5 and the vscode extention or older versions of vex v5 pro.

# How to Setup
* To install the code, first copy the `brain-display.cpp` file to the `\src` folder.
* Second, copy the `brain-display.h` file to the `\include` folder.
* Next, copy the `images.cpp` file to the `\src` folder.
* Lastly, make the following changes to the `main.cpp` file in the `\src` folder:
  * Paste `#include "brain-display.cpp"` and `BrainDisplay brainDisplay;` near the top.
  * add the following function near the top:
    ```
    void screenCallback() {
      brainDisplay.screenPressed();
    }
    ```
  * In the begining of the `int main() {}`, paste this line of code: `Brain.Screen.pressed(screenCallback);`
  * Put your brain screen code after that line, inside the main function.

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

# How to use

 Below is a list of the availabe functions, properties, and structures that the code provides.

## Structures

<details>
  <summary>Button Structure</summary>

  The code defines a structure for adding buttons to the brain screen.  
  Fields marked with `*` are required:

  - `Button.x`: `unsigned int` — X coordinate of the **top-left corner** of the button, relative to the screen’s top-left corner.  
    Default: `0`. Range: `0–480` (inclusive).

  - `Button.y`: `unsigned int` — Y coordinate of the **top-left corner** of the button.  
    Default: `0`. Range: `0–240` (inclusive).

  - `Button.width`: `unsigned int` — Button width (must be greater than `0`).  

  - `Button.height`: `unsigned int` — Button height (must be greater than `0`).  

  - `Button.text`: `char[20]` — Text displayed on the button.  
    Default: empty string `""`. Maximum: 20 characters.  

  - `Button.color`: `unsigned int` — Background color in hex.  
    Default: `0x000000` (black).  

  - `Button.callback*`: `void (*)(int)` — Function to call when the button is pressed.  

  - `Button.param*`: `int` — Value passed as a parameter to the callback function.  

</details>

<details>
  <summary>Page Structure</summary>
 
  This structure should never be used by the user.
  
</details>

## Functions







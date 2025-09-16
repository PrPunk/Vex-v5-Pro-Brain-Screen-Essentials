# Vex v5 Pro BrainScreen Essentials
Adds framework for buttons and pages for the brain screen when using vex v5 and the vscode extention or older versions of vex v5 pro.
Note: It helps to delete the build folder every time you download code to avid errors.

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

 Below is a list of the availabe functions and structures that the code provides that you may need to use.

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
    Defaults to clear.  

  - `Button.callback*`: `void (*)(int)` — Function to call when the button is pressed.  

  - `Button.param*`: `int` — Value passed as a parameter to the callback function.  

</details>

<details>
  <summary>Page Structure</summary>
 
  This structure should never be used by the user.
  
</details>

## Functions

<details>
  <summary>Create Button</summary>

  The `BrainDisplay.createButton()` function creates a button on a specified page.  
  Parameters:

  - `pageId` (`unsigned int`): The ID of the page the button will appear on.  
    Range: `0–5` (inclusive).  

  - `buttonId` (`unsigned int`): The ID slot for the button.  
    Each page has 10 slots (`0–9`), and each slot can only be used once.  

  - `newButton` (`Button`): The button structure to create.  
    It is recommended to define a `Button` first and then pass it into this function.  

</details>

<details>
  <summary>Switch Page</summary>

  The `BrainDisplay.switchPage()` function immediately switches the screen to a specific page.  
  Parameters:

  - `pageId` (`unsigned int`): The ID of the page to switch to.  
    Range: `0–5` (inclusive).  

</details>

<details>
  <summary>Add Image</summary>

  The `BrainDisplay.addImage()` function sets the background of a page to an image defined in `images.cpp`.  
  For more information on how to add images, see below.  
  Parameters:

  - `pageId` (`unsigned int`): The ID of the page the image will be applied to.  

</details>

<details>
  <summary>Screen Pressed</summary>

  The `BrainDisplay.screenPressed()` function subscribes to touch input on the brain screen.  
  It should be called in `main()` to register screen press events.  

</details>

# Images

To add images to the program, first follow the instructions at [this website](https://suhjae.github.io/vex-image/). Copy the code and replace the code in the `images.cpp` file with it. Note: you can only have one image and it will take up the whole page.

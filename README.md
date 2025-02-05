# AnyPrintPlugin

[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE)

**AnyPrintPlugin** is a lightweight C++ Unreal Engine 5 plugin that provides a simple and clear way to debug your project by sending your debug prints to a Print Log. Essentially, it removes the need to scroll through the Output Log to find the information you wanted by printing directly to a custom Editor Utility Widget (Print Log). This plugin is designed to be easily integrated into any Unreal Engine project.

---

## Table of Contents

- [Features](#features)
- [Usage](#usage)
- [Installation](#installation)
- [Content](#content)
- [License](#license)
- [Contact](#contact)

---

## Features

- **C++ Powered**  
  - All functionality is implemented in C++ for maximum performance and flexibility.

- **Blueprint Function Library**  
  - **Print Anything:**  
    Easily print any message along with a timestamp to a dedicated Print Log.
    
  - **Print Anything Index:**  
    Print a message with an associated index, including a timestamp, for additional context and tracking.

- **Editor Utility Widget Integration**  
  - **Real-Time Log Display:**  
    View logs directly in the Editor Utility Widget without sifting through the Output Log.
    
  - **Dynamic Log Management:**  
    - Resize the text in the Print Log for improved readability.
    - Clear the log with a single click to reset the display.

- **Persistent Logging**  
  All logs are automatically saved to a `PrintLog.txt` file (located in the `Saved/Logs` folder), which is parsed to populate the Print Log. This ensures that your logs persist even when the engine isn’t running, during design time, or even after closing the engine.

- **Always-On Logging**  
  Designed to work in all circumstances—whether in construction scripts or during runtime—so you never miss a log entry.

---

## Usage

**Blueprints**
- Right-click in the Event Graph.

- Search for PrintAnything or PrintAnythingIndex.

- Use the node to print messages to the Print Log.

**C++**
- Add the Blueprint Function Library to your header file.

- Call the SaveLogToFile() function, passing in a string to log.

**Print Log Widget**
- Right click the PrintLog Editor Utility Widget

- Click "Run Utility Widget"

---

## Content

This plugin include the following 4 files:

**C++ Files**

- DebugFunctionLibrary
  - This is the function library that provides global print functions.

- PrintLogWidget
  - This is the base C++ class for the PrintLog Blueprint. It handles the core functionality of creating and managing logs in the Editor Utility Widget.

**Blueprint Files**

- PrintLog
  - This is an editable Editor Utility Widget Blueprint, derived from the PrintLogWidget C++ class. It allows you to customize the layout and appearance of the Print Log widget to suit your needs.

  - The only requirement with this blueprint when customizing it for yourself is that you need an Editor Utility Scrollbox named LogScrollBox

---

## Installation

### Via GitHub

- **Clone or Download:**  
  Clone this repository or download the ZIP archive from GitHub.

  ```bash
  git clone https://github.com/G3N7AX/AnyPrintPlugin.git

---

## License

Standard MIT License

Credit is very much appreciated but is not required.

---

## Contact

For questions or feedback, feel free to reach out:

g3n7ax@gmail.com
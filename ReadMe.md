
# AnyPrint

[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE)

**AnyPrint** is a lightweight C++ Unreal Engine 5 plugin that provides a simple and clear way to debug your project by sending your debug prints to a Print Log. Essentially, it removes the need to scroll through the Output Log to find the information you wanted by printing directly to a custom Editor Utility Widget (Print Log). This plugin is designed to be easily integrated into any Unreal Engine project.

---

## Table of Contents

- [Features](#features)
- [Usage](#usage)
- [API Reference](#api-reference)
- [Installation](#installation)
- [Content](#content)
- [License](#license)
- [Contact](#contact)

## Features
**C++ Powered**
- All functionality is implemented in C++ for maximum functionality and flexibility

**Blueprint Function Library** 
- Provides `PrintAnything`, a function similar to `PrintString`, but logs are sent to the **PrintLog** instead of the Output Log.
    
**Customizable Logs** 
- Each log includes a message and a color, stored in a structured format.
    
**Editor Utility Widget** 
- Displays logs in an easy-to-read format, with options to clear logs, show/hide timestamps, and adjust text size.
    
**Event Dispatcher Integration** 
- Ensures real-time log updates within the widget.
    
**Timestamp Retention** 
- Logs always have timestamps, but their display can be toggled on or off. When re-enabled, all logs will show their original timestamps.

## Usage

**Blueprints**
- Right Click the Event Graph
- Search for PrintAnything

**C++**
- Include the AnyPrintFunctionLibrary.h
- Call PrintAnything(const FString& Log, FLinearColor LogColor)
```
// Example C++ usage
#include "DebugFunctionLibrary.h"
UDebugFunctionLibrary::PrintAnything(TEXT("Hello, World!"), FLinearColor(1.f, 1.f, 1.f, 1.f)));
```

**Print Log Widget**
- Right click the PrintLog Editor Utility Widget
- Click "Run Utility Widget"

## API Reference

### Modules

-   **AnyPrintLibrary (Runtime Module)**
    
    -   Contains `AnyPrintFunctionLibrary`, which provides the `PrintAnything` function.
        
    -   Logs are timestamped and stored in an array (`LogEntries[]`)
        
-   **AnyPrintEditor (Editor Module)**
    
    -   Manages the **PrintLog Editor Utility Widget**, which displays logs with formatting options.


## Content

### C++ Files
- AnyPrintFunctionLibrary (.h /.cpp)
- AnyPrintEditor (.h / .cpp)

### Blueprints
- PrintLog_L1 (Layout 1)

---

## Installation

### Via GitHub

**Clone or Download:**  
- Clone this repository or download the ZIP archive from GitHub.

```
git clone https://github.com/G3N7AX/AnyPrintPlugin.git
```

---

## License

Standard MIT License

Credit is very much appreciated but is not required.

---

## Contact

For questions or feedback, feel free to reach out:

g3n7ax@gmail.com


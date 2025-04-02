
# AnyPrint

[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE)

**AnyPrint** is a lightweight C++ Unreal Engine 5 plugin that provides a simple and clear way to debug your project by sending your debug prints to a Print Log. It eliminates the need to search through the Output Log by displaying debug prints in a dedicated Print Log Widget. This plugin is designed to be easily integrated into any Unreal Engine project.

## Table of Contents

- [Features](#features)
- [Usage](#usage)
- [API Reference](#api-reference)
- [Installation](#installation)
- [Content](#content)
- [Roadmap](#roadmap)
- [Customization & Contribution](#customization--contribution)
- [License](#license)
- [Contact](#contact)

## Features

### C++ Powered
- All functionality is implemented in C++ for maximum functionality and flexibility

### Blueprint Function Library 
- Provides `PrintAnything`, a function similar to `PrintString`, but logs are sent to the **PrintLog** instead of the Output Log.
    
### Customizable Logs 
- Each log includes a message and a color, stored in a structured format.
    
### Editor Utility Widget 
- Displays logs in an easy-to-read format, with options to clear logs, show/hide timestamps, and adjust text size.
    
### Event Dispatcher Integration 
- Ensures real-time log updates within the widget.
    
### Timestamp Retention 
- Logs always have timestamps, but their display can be toggled on or off. When re-enabled, all logs will show their original timestamps.

## Usage

### Blueprints
- Right Click the Event Graph
- Search for PrintAnything

### C++
- Include the AnyPrintFunctionLibrary.h
- Call PrintAnything(const FString& Log, FLinearColor LogColor)
```
// Example C++ usage
#include "DebugFunctionLibrary.h"
UDebugFunctionLibrary::PrintAnything(TEXT("Hello, World!"), FLinearColor(1.f, 1.f, 1.f, 1.f)));
```

### Print Log Widget
- Right click the PrintLog Editor Utility Widget
- Click "Run Utility Widget"

## API Reference

### Modules

#### AnyPrintLibrary (Runtime Module)
    
- Contains `AnyPrintFunctionLibrary`, which provides the `PrintAnything` function.
        
-   Logs are timestamped and stored in an array (`LogEntries[]`)
        
 #### AnyPrintEditor (Editor Module)
    
- Manages the **PrintLog Editor Utility Widget**, which displays logs with formatting options.


## Content

### C++ Files
- AnyPrintFunctionLibrary (.h /.cpp)
- AnyPrintEditor (.h / .cpp)

### Blueprints
- PrintLog_L1 (Layout 1)

## Installation

### Via GitHub

#### Clone or Download
 
Clone this repository or download the ZIP archive from GitHub.

```
git clone https://github.com/G3N7AX/AnyPrintPlugin.git
```
### **Unreal Engine Version Compatibility**

**AnyPrint was developed with Unreal Engine 5.5.** If you're using it in **UE 5.0 - 5.4**, the core functionality will still work, but the **PrintLog Widget Blueprint may not exist** by default.

To resolve this:

1.  **Manually create a new PrintLog Widget Blueprint** as a child (*Right-click → Create Child Blueprint Class*) of the `AnyPrintWidget` class (found in the **AnyPrintEditor module**).
    
2.  If possible, **install and open the plugin in Unreal Engine 5.5** and copy the existing PrintLog Widget Blueprint (PrintLog_L1) information over or just use it as a setup reference.

## Roadmap

### Layout

- Offer alternative PrintLog layouts, enabling users to choose their preferred format to reduce startup delays for a seamless coding upstart experience with the plugin.

### Features

#### PrintAnything Index
 - This will be similar to PrintAnything but will allow for an int input which can be used for printing the logs with indices.

#### CustomThunks
- The goal with a CustomThunk is to have a wildcard Log input pin that will figure out what information.
- This is meant to be able to better handle the outputs it to the log.
- An example of why I want to look into this can be seen with the rotation output.
- The output for the rotation has 6 decimal points which can take up unnecessary room and make it harder to read.

#### Log Sets
- Something that was in consideration was separating the logs by sets.
- Log Sets would automatically group logs into sequential sets, incrementing after periods of inactivity to make locating older logs easier without relying on timestamp gaps.

#### Saved Settings
- Something I was working on was saving the users settings (like the Text Size and Show Timestamp value) with config files.
- I had been working on this but it was failing at the time so I reverted to what I currently until I can solve the issue.

#### On-Screen Print
- Something I was looking to add was the option to send the logs to the screen when a log is created.
- This would allow PrintAnything to function more like the PrintString node by mimicking the same functionality.
- This would also (hopefully) come with more settings for better on-screen logs.
- It would be a togglable option if implemented.

#### Safety Net
- After too many logs (somewhere in the midst of 5000 logs), the engine will crash.
- I intend to work on a way to start shuffling out old logs to be overwritten by newer ones.
- This hasn't been immediately addressed because it takes so many logs for this to occur.
- As long as the user empties the logs frequently, this crashing should not occur.

**Note**: This has only been tested on my machine which is fairly high end. So, in testing, my machine crashes at about 5000 logs. It's possible that on lower end machines this number could be lower. Considering that even if I cut the number in half (2500 logs) to account for lower end machines, it's still such a significant number that this is something that will come soon in future updates. Since this was initially made for myself, this failsafe just wasn't a priority for me.

#### Requested Ideas
- Highly requested options (if any at all) may be added.

## **Customization & Contribution**

AnyPrint is fully **commented and documented** to help users understand its functionality and expand it as needed. This project is designed to be flexible—if you want to modify or extend it to fit your needs, **you are encouraged to do so!**

This plugin is released under the **MIT License**, meaning you’re free to use, modify, and distribute it. However, you **cannot reupload an unaltered version** as your own work. If you share it, **you must make a meaningful contribution** by adding your own improvements.

Whether you’re just learning Unreal Engine or an experienced developer, feel free to use the comments throughout the code as a guide. **I built this to help people, so make it your own!**

## License

AnyPrint is licensed under the **MIT License**, meaning it is **completely free to use, modify, and expand upon**.

-   You can integrate it into your own projects, modify its functionality, and even sell your own modified version if you so please.
    
-   You **will not** face copyright strikes or legal issues for using or distributing a modified version of AnyPrint.

-   The only restriction is that you **cannot** reupload or redistribute an **unaltered** version as your own—any shared version must include **meaningful modifications or improvements** (see [Customization & Contribution](#customization--contribution)).
    

While **credit is appreciated**, it is **not required**. Feel free to make AnyPrint your own!

## Contact

For questions or feedback, feel free to reach out:

g3n7ax@gmail.com


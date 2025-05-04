# Red Team Ops 2 
- This is a implementation of the labs from Red Team Ops 2 course. 

## Windows APIs
- The Windows API is a set of programming interfaces available in the Windows OS.
- They're easily available using c or C++ languages since they expose all the necessary data structures.
- WinAPI are essential for the following offensive operations on Windows:
	- Host Enumeration
	- Starting Processes
	- Process Injection
	- Token Manipulation
- The most commonly used set of WinAPIs are "Base Services"(kernel32.dll) and "Advanced Services"(advapi32.dll).

### MessageBox in C++
- We can create a C++ Console App and remove the template code. 
- Then we can add this header file `#include <Windows.h>` that contains the declarations for the main Windows API, macros and data types.
- Now in the main function we can create a MessageBox. 

### CreateProcess in C++
- We can start by creating a Function above of the main function instead of creating a new project. 
- This code will attempt to open notepad application 
- Note that `CreateProcess` is a macro for `CreateProcessW`
- If successful we'll print the PROCESS_INFORMATION struct
- It's important to close these handles when not needed to avoid handle leaks
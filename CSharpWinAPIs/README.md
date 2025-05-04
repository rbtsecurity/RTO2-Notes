# Red Team Ops 2 
- This is a implementation of the labs from Red Team Ops 2 course. 

## PInvoke
- allows access to structs and functions present in unmanaged libraries from our managed code


### Managed vs Unmanaged Code
- Application written in C/C++ compile to machine code and are unmanaged code
	- Devs must manage Memory Management Manually
- Managed Code runs on Common Language Runtime which converts to machine code durning runtime
	- CLR handles garbage collection and various runtime checking.

.Net uses P/Invoke under the hood using abstractions. 
- To start a process in .NET we can use `Start` method in System.Diagnostics.Process class.
- This method in runtime uses P/Invoke to call the Createprocess API. 
- Limits us though since we can't edit the data being passed into the STARTUPINFO struct which stops us from doing things like starting a processes in a suspended state. 

There are other WinAPIs that are not exposed in .NET and can only be accessed using P/Invoke in the code.

## MessageBox in CSharp
- We can start by creating a new C# Console App (.NET Framework) in our solution. 
- In C# we have to declare all the windows APIs and structures manually.
- In the Example below, MessageBoxW API is first declared using this DLLImport attribute, this tells the CLR that a function called MessageBoxW is exported from the user32.dll
- Not all languages share the same data type and may require Marshaling to change the data type when going in-between managed and unmanaged languages.


```
[DllImport("user32.dll", CharSet = CharSet.Unicode)]
static extern int MessageBoxW(IntPtr hWnd, string lpText, string lpCaption, uint uType);
```
# Type Marshaling
- Is the process of transforming a data type when it needs to go between managed and unmanaged code.
- Unless specified the P/Invoke subsystem tires to marshal data for you as per the last example. 
- There are times that we need to be more explicit 
	- We can use `CharSet` field in `DLLImport` attribute which defines how all string parameters should be marshalled
	- We can also us the `MarshalAs` attribute on each individual parameter. This is not limited to strings.
- We can also marshal any data returned by a P/Invoke method using the return keyword, followed by MarshalAs attribute

## Create Process in CSharp
- For Creating a process with P/Invoke signatures we need to create a class for struct and enums to make the code more readable.
- We have the code saved as Win32.cs and can access the structures using Win32.cs in the main program.
#include <Windows.h>
#include <stdio.h>
#include <tchar.h>


int RTOCreateProcess()
{
	//Variable Declaration
	LPSTARTUPINFOW si; // Stack Allocation
	PPROCESS_INFORMATION pi; // Stack Allocation 
	BOOL success;

	//Memory Allocation and Intialization
	si = new STARTUPINFO();
	si->cb = sizeof(LPSTARTUPINFOW); //Intialize STARTUPINFOW

	pi = new PROCESS_INFORMATION();

	//Command to execute setup 
	wchar_t cmd[] = L"notepad.exe";

	//Creating the Process
	success = CreateProcessW(
		NULL, //lpApplicationName: The executable name is provided in the cmd parameter, so this is NULL.
		cmd, //lpCommandLine: The command line to execute
		NULL, //lpProcessAttributes: No special security attributes for the process.
		NULL, //lpThreadAttributes: No special security attributes for the thread.
		FALSE, //bInheritHandles: Child process does not inherit handles from the parent.
		0, //dwCreationFlags): No special creation flags
		NULL, //lpEnvironment): Uses the parent's environment variables.
		NULL, //lpCurrentDirectory: Uses the parent's working directory.
		si,//lpStartupInfo): Pointer to the STARTUPINFOW structure.
		pi); //lpProcessInformation): Pointer to the PROCESS_INFORMATION structure to store process details.

	//Error handliing
	if (!success) {
		DWORD error = GetLastError(); // Had to add to help with troubleshooting 
		printf("[X] CreateProcess Failed %lu\n", error);
		return 1;
	}

	//Displaying Process Information
	printf("dwProcessId : %d\n", pi->dwProcessId);
	printf("dwThreadId : %d\n", pi->dwThreadId);
	printf("hProcess : %p\n", pi->hProcess);
	printf("hThread : %p\n", pi->hThread);

	//Cleaning UP
	CloseHandle(pi->hThread);
	CloseHandle(pi->hProcess);
}

int main()
{
	//The L denotes tge wchar_t literal needed for the function.
	MessageBox(NULL, L"You are hacked", L"Alert", 0);
	return RTOCreateProcess();
	//return 0;
}
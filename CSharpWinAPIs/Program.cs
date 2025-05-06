using System;
using System.ComponentModel;
using System.Runtime.InteropServices;
using CSharpWinAPIs.Classes;

namespace CSharpWinAPIs
{
    internal class Program
    {
        //Setting the Marshalling                           Setting error handling 
        [DllImport("user32.dll", CharSet = CharSet.Unicode, SetLastError = true)]
        static extern int MessageBox(IntPtr hWnd, string lpText, string lpCaption, uint uType);

        static void Main(string[] args)
        {
            MessageBox(IntPtr.Zero, "Hello World", "P/Invoke", 0);

            //Create Startup Info
            var startupInfo = new Win32.STARTUPINFO();
            startupInfo.cb = Marshal.SizeOf(startupInfo);

            //Create Process
            var success = Win32.CreateProcessW(
                null,
                "notepad.exe",
                IntPtr.Zero,
                IntPtr.Zero,
                false,
                0,
                IntPtr.Zero,
                null,
                ref startupInfo,
                out var processInformation);

            if (!success) 
            {
                var exception = new Win32Exception(Marshal.GetLastWin32Error()); //Error Handling 
                Console.WriteLine("Create Process Failed", exception.Message);
                return;
            }

            //Print Process info
            Console.WriteLine("dwProcessId : {0}", processInformation.dwProcessId);
            Console.WriteLine("dwThreadId : {0}", processInformation.dwThreadId);
            Console.WriteLine("hProcess    : 0x{0:X}", processInformation.hProcess);
            Console.WriteLine("hThread     : 0x{0:X}", processInformation.hThread);

            Win32.CloseHandle(processInformation.hThread);
            Win32.CloseHandle(processInformation.hProcess);
           
        }
    }
}

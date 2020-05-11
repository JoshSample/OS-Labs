// Joshua Sample
// CSCI 4300
// Lab 1

// This section includes header files the program needs
#include <iostream>
#include <windows.h>

// driver of program
int main()
{
    // variable declaration
    STARTUPINFO si; // si has access to the STARTUPINFO struct
    PROCESS_INFORMATION pi; // pi has access to the PROCESS_INFORMATION struct
    bool wait = true; // This bool keeps the process running until user wants to terminate it 

    // allocate memory
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    // create child process
    if (!CreateProcess(L"C:\\Program Files\\Internet Explorer\\iexplore.exe", // application name, opens Internet Explorer
        NULL, // command line
        NULL, // don't inherit process handle
        NULL, // don't inherit thread handle
        FALSE, // disable handle inheritance
        0, // no creation flags
        NULL, // use parent's environment block
        NULL, // use parent's existing directory
        &si, // pointer to STARTUPINFO struct
        &pi)) // pointer to PROCESS_INFORMATION struct
    {
        // error message if process fails to open
        std::cerr << "Create Process Failed";
        return -1;
    }

    // loop to keep program running until the user wants to terminate it
    do
    {
        std::cout << "Would you like to terminate the process? 1 for yes 0 for no ";
        std::cin >> wait;
    }   while (wait == false);

    // terminate the process created
    TerminateProcess(pi.hProcess, 0);

    // close process handle
    CloseHandle(pi.hProcess);
    // close thread handle
    CloseHandle(pi.hThread);

    return 0;
}

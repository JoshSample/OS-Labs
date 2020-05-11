// Joshua Sample
// ID: B01218906
// CSCI 4300 Lab 2
// Dr. Sun

// Header files required for the program
#include <windows.h>
#include <stdio.h>

DWORD Result = 1; // data is shared by the thread(s)
int exponent; // variable shared by the thread(s), the second argument from the command line

// The thread runs in this separate function
// It preforms an exponentiation of 2 numbers passed in by the command line
DWORD WINAPI Exponentiate(LPVOID Param)
{	
	DWORD Base = *(DWORD*)Param; // converts parameter into a DWORD, this is also the base number passed in

	// this loop performs the exponentiation
	while (exponent != 0)
	{
		Result *= Base;
		--exponent;
	}

	return 0;
}

// Driver of program, takes 2 arguments, a base and an exponent
// It also creates the thread
int main(int argc, char* argv[])
{
	DWORD ThreadId;
	HANDLE ThreadHandle;
	int base; // value is from the 1st argument in the command line
	// Perform some basic error checking
	if (argc != 3) {
		fprintf(stderr, "Two integer parameters are required\n");
		return -1;
	}

	base = atoi(argv[1]); // first number passed is the base
	exponent = atoi(argv[2]); // second number passed is the exponent
	int exp = exponent; // this saves the value of the exponent, used for later

	// Error checking for command line parameters
	// This program requires users to enter a number greater than 0
	if (base < 1) { // check base
		fprintf(stderr, "An integer > 0 is required\n");
		return -1;
	}
	if (exponent < 1) { // check exponent
		fprintf(stderr, "An integer > 0 is required\n");
		return -1;
	}

	// create the thread
	ThreadHandle = CreateThread(
		NULL, // default security attributes
		0, // default stack size
		Exponentiate, // thread function
		&base, // parameter to thread function
		0, // default creation flags
		&ThreadId); // returns the thread identifier

	if (ThreadHandle != NULL) {
		// now wait for the thread to finish
		WaitForSingleObject(ThreadHandle, INFINITE);

		// close the thread handle
		CloseHandle(ThreadHandle);

		// print results of exponentiation
		printf("Result of %d to the power of %d = %d", base, exp, Result);
	}
}
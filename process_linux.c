// Joshua Sample
// ID: B01218906
// CSCI 4300 Lab 3
// Dr. Sun

// Headers needed for program
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// Driver of program
int main()
{
    // process ID pointer
    pid_t pid;
    // fork a child process
    pid = fork();
    // error checking
    if (pid < 0)
    {
        fprintf(stderr, "Fork Failed"); // error occured
        exit(-1);
    }
    // start xclock process
    else if (pid == 0)
    {
        execlp("/usr/bin/xclock", "xclock", NULL); // child process
    }
    else
    {
        wait(NULL); // parent will wait for the child process to complete
        printf("Child Complete"); // let user know process has completed
        exit(0); // exit program
    }
    
}

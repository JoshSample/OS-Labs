// Joshua Sample
// ID: B01218906
// CSCI 4300 Lab 4
// Dr. Sun

// Headers required for program
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int negate; // this data is shared by the thread(s)
void *runner(void *param); // the thread

// driver of the program
int main(int argc, char *argv[])
{
    pthread_t tid; // the thread identifier
    pthread_attr_t attr; // set of thread attributes
    
    // check if arguments are passed
    if (argc != 2)
    {
	// error message if arguments are invalid
        fprintf(stderr, "usage: a.out <integer value>\n");
        return -1;
    }
    
    // code needed to start a thread
    pthread_attr_init(&attr);
    pthread_create(&tid, &attr, runner, argv[1]); // create the thread
    pthread_join(tid,NULL); // wait for the thread to exit
    printf("negation = %d\n", negate); // print results of negation
}
// the thread will begin control in this function
// the point of the thread is to negate a number
void *runner(void *param)
{
    // convert number passed from command line
    int num = atoi(param);
    // initialize negate variable
    negate = -1;
    // do the negation
    negate *= num;
    // exit the thread
    pthread_exit(0);
}

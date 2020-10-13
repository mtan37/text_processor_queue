// Authors: Marvin Tan(mtan37) (marvin.tan@wisc.edu), Joseph Martin(jrmartin4) (jrmartin4@wisc.edu)
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "queue.h"
#include "writer.h"

/*
 * Get input from queue and print out the input
 */
void printOutput(Queue *queue){
    //while queue doesn't return NULL
    char *input = DequeueString(queue);
    int inputCount = 0;
    printf("==================Output Info==================\n");
    while(input != NULL){
        inputCount++;
        //print the line
        printf("Output #%d: %s\n",inputCount, input);
        //free the input
        free(input);
        //take the next input from the queue
        input = DequeueString(queue);
    }
    //no more input
    printf("Number of strings processed: %d\n", inputCount);
}

/*
 * Function wrapper for printOutput
 */
void *printOutputWrapper(void *data){
    Queue *queue = (Queue *)data;
    printOutput(queue);
    pthread_exit(NULL);
}

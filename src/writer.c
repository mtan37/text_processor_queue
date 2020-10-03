#include "writer.h"

void printOutput(Queue *queue){
    //while queue doesn't return NULL
    char *input = DequeueString(queue);
    int inputCount = 0;
    while(input != NULL){
        inputCount++;
        //print the line
        printf("%s\n",input);
        //free the input
        free(input);
        //take the next input from the queue
        input = DequeueString(queue);
    }
    //no more input
    printf("INFO: Numer of string processed: %d", inputCount);
}

void *printOutputWrapper(void *data){
    Queue *queue = (Queue *)data;
    printOutput(queue);
    pthread_exit(NULL);
}

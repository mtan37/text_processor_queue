#include "writer.h"

void printOutput(Queue *queue){
    //while queue doesn't return NULL
    char *input = DequeueString(queue);
    while(input != NULL){
        //print the line
        printf("%s\n",input);
        //free the input
        free(input);
        //take the next input from the queue
        input = DequeueString(queue);
    }
}

void *printOutputWrapper(void *data){
    Queue *queue = (Queue *)data;
    printOutput(queue);
    pthread_exit(NULL);
}

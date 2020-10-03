#include "writer.h"

void printOutput(Queue *queue){
    //TODO while queue doesn't return NULL
    char *input = DequeueString(queue);
    while(input != NULL){
        //print the line
        printf("%s\n",input);
        input = DequeueString(queue);
    }
}

void *printOutputWrapper(void *data){
    Queue *queue = (Queue *)data;
    printOutput(queue);
    pthread_exit(NULL);
}

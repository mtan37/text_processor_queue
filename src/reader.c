#include "reader.h"
const int BUFFS = 100;


/*
 * read input line by line from standard input
 * pass the result to the queue
 */
void startRead(Queue *queue){
    char buff[BUFFS];   
    //keep reading until the end of the line 
    while(fgets(buff, BUFFS , stdin)!=NULL){
        int inputLength = strlen(buff);
        //check if the last character is the new line symbol
        //if the new line char is included, pass the string to queue
        if(buff[inputLength - 1] == '\n'){
            //allocate mem for the string
            //pass the string into the queue
        }
        //if the input line exceeds the buffer size
        else{
            //do whatever you need to do....
        }
    }
    //TODO queue a NULL string as the last input to indicate completion
}

void *startReadWrapper(void *data){
    Queue *queue = (Queue *)data;
    startRead(queue);
    pthread_exit(NULL);
}

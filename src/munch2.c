#include <string.h>
#include <pthread.h>
#include <ctype.h>
#include "munch2.h"

/*
 * read input from q1. Convert all lower case char in input to capitalized
 * letters, then pass it to q2
 */
void munch2Read(Queue *q1, Queue *q2){
    //while the queue didn't pass in NULL
    char *input = DequeueString(q1);
    while(NULL != input){
        //loop through the char in the input
        int inputLen = strlen(input);
        for(int i = 0; i < inputLen;i++){
            char currChar = input[i];
            //if the curr char is a lower case letter, capitalize it
            if(0 != islower(currChar)){
                input[i] = toupper(currChar);
            }
        }
        //enqueue the modified string to q2
        EnqueueString(q2,input);
        //take the next input from the queue
        input = DequeueString(q1);
    }    
    //enqueue NULL to q2
    EnqueueString(q2,NULL);
}

/*
 * Function wrapper for munch2Read
 */
void *munch2ReadWrapper(void *data){
    Munch2Params *queues = (Munch2Params *)data;
    munch2Read(queues->queue1,queues->queue2);
    pthread_exit(NULL);
}

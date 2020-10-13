// Authors: Marvin Tan (marvin.tan@wisc.edu), Joseph Martin (jrmartin4@wisc.edu)
#include <string.h>
#include <pthread.h>
#include "munch1.h"


/*
 * get input from q1. Replace all spaces with *. And pass it to q2
 */
void munch1Read(Queue *q1, Queue *q2){
    //while the queue didn't pass in NULL(the end of stdin)
    char *input = DequeueString(q1);
    while(NULL != input){
        //loop through the char in the input
        int inputLen = strlen(input);
        for(int i = 0; i < inputLen;i++){
            //if the curr char is a space, replace it with '*'
            if(' ' == input[i]){
                input[i] = '*';
            } 
        } 
        //enqueue the modified string to q2
        EnqueueString(q2, input);
        //take the next input from q1
        input = DequeueString(q1);
    }    
    //enqueue NULL to q2
    EnqueueString(q2, NULL);
}
/*
 * Wrapper for the munch1Read function
 */
void *munch1ReadWrapper(void *data){
    Munch1Params *queues = (Munch1Params *)data;
    munch1Read(queues->queue1, queues->queue2);
    pthread_exit(NULL); 
}

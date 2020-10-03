#include "munch2.h"


void munch2Read(Queue *q1, Queue *q2){
    //while the queue didn't pass in NULL
    char *input = DequeueString(q1);
    while(input != NULL){
        //TODO loop through the char in the input
            //if the curr char is a lower case letter, capitalize it
            //TODO
            //enqueue the modified string to q2
            //TODO
        input = DequeueString(q1);
    }    
    //enqueue NULL to q2 TODO
}

void *munch2ReadWrapper(void *data){
    Munch2Params *queues = (Munch2Params *)data;
    munch2Read(queues->queue1,queues->queue2);
    pthread_exit(NULL);
}

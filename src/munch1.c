#include "munch1.h"


/*
 * get input from q1. Replace all spaces with *. And pass it to q2
 */
void munch1Read(Queue *q1, Queue *q2){
    //while the queue didn't pass in NULL(the end of stdin)
    char *input = DequeueString(q1);
    while(input != NULL){
        //TODO loop through the char in the input
            //if the curr char is a space, replace it with '*'
            //TODO
            //enqueue the modified string to q2
            //TODO
        input = DequeueString(q1);
    }    
    //enqueue NULL to q2 TODO
}

void *munch1ReadWrapper(void *data){
    Munch1Params *queues = (Munch1Params *)data;
    munch1Read(queues->queue1, queues->queue2);
    pthread_exit(NULL); 
}

#include "reader.h"
#include "munch1.h"
#include "munch2.h"
#include "writer.h"
#include "util.h"
int main(){
    //create the three queues
    //use size 10 for testing purposes
    Queue *readerToMunch1 = CreateStringQueue(10);
    Queue *munch1ToMunch2 = CreateStringQueue(10);
    Queue *munch2ToWriter = CreateStringQueue(10);  
    //initialize args
    Munch1Params *munch1Args = calloc_w(1,sizeof(Munch1Params));
    munch1Args->queue1 = readerToMunch1;
    munch1Args->queue2 = munch1ToMunch2;
    Munch2Params *munch2Args = calloc_w(1,sizeof(Munch2Params));
    munch2Args->queue1 = munch1ToMunch2;
    munch2Args->queue2 = munch2ToWriter;
    //create four new threads
    //create the reader
    pthread_t reader; 
    pthread_create_w(&reader, NULL, startReadWrapper,readerToMunch1);
    //create munch1
    pthread_t munch1;
    pthread_create_w(&munch1, NULL, munch1ReadWrapper,munch1Args);
    //create munch2
    pthread_t munch2;
    pthread_create_w(&munch2, NULL, munch2ReadWrapper,munch2Args);
    //create writer
    pthread_t writer;
    pthread_create_w(&writer, NULL, printOutputWrapper,munch2ToWriter);
    //wait for those threads to finish
    pthread_join_w(reader, NULL);
    pthread_join_w(munch1, NULL);
    pthread_join_w(munch2, NULL);
    pthread_join_w(writer, NULL);
    //print the queue stats
    printf("==========Reader->Munch1 queue status==========\n");//may want to think of a different name... TODO
    PrintQueueStats(readerToMunch1);
    printf("==========Munch1->Munch2 queue status==========\n");
    PrintQueueStats(munch1ToMunch2); 
    printf("==========Munch2->Writer queue status==========\n");
    PrintQueueStats(munch2ToWriter);
}

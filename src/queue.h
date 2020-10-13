#ifndef QUEUE_H
#define QUEUE_H
#include <semaphore.h>
typedef struct Queue {
    sem_t *isBusy;
    sem_t *filledSpace;
    sem_t *emptySpace;
    sem_t *recordTime;
    char **queueLine;
    int size;
    int head;
    int end;
    //a count of the number of strings enqueued on this queue
    int enqueueCount;
    //a count of the number of strings dequeued on this queue
    int dequeueCount;
    //The amount of elapsed (wallclock) time that a thread spent trying to do an enqueue
    double enqueueTime;
    //The amount of elapsed (wallclock) time that a thread spent trying to do an dequeue
    double dequeueTime;
} Queue;

Queue *CreateStringQueue(int size);
void EnqueueString(Queue *q, char *string);
char *DequeueString(Queue *q);
void PrintQueueStats(Queue *q);

#endif

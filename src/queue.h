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

/*
 * Allocate and initialize a new Queue struct in the mem
 * the size of the queue equals to the pass in size
 */
//DELET: test size is 10;
Queue *CreateStringQueue(int size);

/*
 * Places the pointer to the last string of the queue
 * If the queue is full, it will wait until it has space
 */
void EnqueueString(Queue *q, char *string);

/*
 * Remove the first string of the queue
 */
char *DequeueString(Queue *q);

/*
 * Prints the statistics for the queue
 */
void PrintQueueStats(Queue *q);

#endif

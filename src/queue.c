#include "queue.h"

/*
 * Allocate and initialize a new Queue struct in the mem
 * the size of the queue equals to the pass in size
 */
Queue *CreateStringQueue(int size){
    Queue *queue = calloc(1,sizeof(Queue));
    queue->enqueueCount = 0;
    queue->dequeueCount = 0;
    queue->enqueueTime = 0;
    queue->dequeueTime = 0;
    queue->queueLine = calloc(size,sizeof(char*));
    sem_init(&(queue->isBusy), 0, 1);
    sem_init(&(queue->filledSpace), 0, 0);
    sem_init(&(queue->emptySpace), 0, 10);
    return queue;
}

/*
 * Places the pointer to the end of the queue
 * If another thread is doing dequeue, will wait
 * If the queue is full, it will wait until it has space
 */
void EnqueueString(Queue *q, char *string){
    //start a time count enqueueTime TODO
    //wait if the queue is full(has no empty space)
    sem_wait(&(q->emptySpace));
    //wait if there is another process trying to enqueue or dequeue
    sem_wait(&(q->isBusy));
    //critical section
    //TODO 
    //increment enqueueCount
    //record enqueueTime
    sem_post(&(q->isBusy));
    sem_post(&(q->filledSpace)); 
}

/*
 * Remove the first string of the queue
 * If another thread is doing enqueue, will wait
 */
char *DequeueString(Queue *q){
    //start a time count dequeueTime TODO
    //check if the queue is empty
    sem_wait(&(q->filledSpace));
    //wait if there is another process trying to enqueue or dequeue
    sem_wait(&(q->isBusy));
    //critical section
    //TODO
    //increment dequeueCount
    //record dequeueTime
    sem_post(&(q->isBusy));
    sem_post(&(q->emptySpace)); 
    return NULL;//TODO
}

/*
 * Prints the statistics for the queue
 */
void PrintQueueStats(Queue *q){
    //TODO
}

#include "queue.h"
#include <stdio.h> 
#include <sys/time.h>

/*
 * Allocate and initialize a new Queue struct in the mem
 * the size of the queue equals to the pass in size
 */
Queue *CreateStringQueue(int size) {
    // TODO: allocated memory
    // Queue *queue = ??
    if (queue == NULL) {
	    printf("Problem allocating queue.\n");
	    exit(1);
    }

    queue->enqueueCount = 0;
    queue->dequeueCount = 0;
    queue->enqueueTime = 0;
    queue->dequeueTime = 0;
    // TODO: allocated memory
    // queue->queueLine = ??
    queue->size = 0;
    queue->head = 0;
    queue->end = 0;
    sem_init(queue->isBusy, 0, 1);
    sem_init(queue->filledSpace, 0, 0);
    sem_init(queue->emptySpace, 0, 10);
    return queue;
}

/*
 * Places the pointer to the end of the queue
 * If another thread is doing dequeue, will wait
 * If the queue is full, it will wait until it has space
 */
void EnqueueString(Queue *q, char *string) {
    //start a time count enqueueTime
    int startTime, endTime;
    struct timeval currentTime; //sec is seconds, usec is microseconds - declared in time.h
    if (q->size >= 10) {
	    gettimeofday(&currentTime, NULL);
    	    startTime = (currentTime.tv_sec * 1000) + (currentTime.tv_usec / 1000);
    }
    //wait if the queue is full(has no empty space)
    sem_wait(q->emptySpace);
    //wait if there is another process trying to enqueue or dequeue
    sem_wait(q->isBusy);
    //critical section
    queue->size++;
    q->end = (q->end + 1) % 10;
    q->queueLine[q->end] = string;
    //increment enqueueCount
    q->enqueueCount++;
    //record enqueueTime
    gettimeofday(&currentTime, NULL);
    endTime = (currentTime.tv_sec * 1000) + (currentTime.tv_usec / 1000);
    q->enqueueTime = endTime - startTime;
	
    sem_post(q->isBusy);
    sem_post(q->filledSpace);
}

/*
 * Remove the first string of the queue
 * If another thread is doing enqueue, will wait
 */
char *DequeueString(Queue *q) {
    //start a time count dequeueTime
    int startTime, endTime;
    if (q->size <= 0) {
	    gettimeofday(&currentTime, NULL);
    	    startTime = (currentTime.tv_sec * 1000) + (currentTime.tv_usec / 1000);
    }
    //check if the queue is empty
    sem_wait(q->filledSpace);
    //wait if there is another process trying to enqueue or dequeue
    sem_wait(q->isBusy);
    //critical section
    q->size--;
	char *string;
    string = *(q->queueLine + q->head);
    q->head = (q->head + 1) % 10;
    //increment dequeueCount
    q->dequeueCount++;
    //record dequeueTime
    gettimeofday(&currentTime, NULL);
    endTime = (currentTime.tv_sec * 1000) + (currentTime.tv_usec / 1000);
    q->dequeueTime = endTime - startTime
	
    sem_post(q->isBusy);
    sem_post(q->emptySpace); 
    return string;
}

/*
 * Prints the statistics for the queue
 */
void PrintQueueStats(Queue *q) {
    printf("enqueueCount: %d\ndequeueCount: %d\nenqueueTime: %d\ndequeueTime: %d\n", q->enqueueCount, q->dequeueCount, q->enqueueTime, q->dequeueTime);
}

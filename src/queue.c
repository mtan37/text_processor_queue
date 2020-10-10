#include "queue.h"
#include <stdio.h> 
#include <sys/time.h>

/*
 * Allocate and initialize a new Queue struct in the mem
 * the size of the queue equals to the pass in size
 */
Queue *CreateStringQueue(int size) {
    Queue *queue = calloc(1, sizeof(Queue));
    queue->recordTime = calloc(1,sizeof(sem_t));
    queue->isBusy = calloc(1,sizeof(sem_t));
    queue->filledSpace = calloc(1,sizeof(sem_t));
    queue->emptySpace = calloc(1,sizeof(sem_t));
    if (queue == NULL) {
	    printf("Problem allocating queue.\n");
	    exit(1);
    }
    queue->enqueueCount = 0;
    queue->dequeueCount = 0;
    queue->enqueueTime = 0;
    queue->dequeueTime = 0;
    queue->queueLine = calloc(size,sizeof(char*));
    sem_init(queue->recordTime,0,1);
    sem_init(queue->isBusy, 0, 1);
    sem_init(queue->filledSpace, 0, 0);
    sem_init(queue->emptySpace, 0, 10);
    queue->size = size;
    queue->head = 0;
    queue->end = 0;
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
    gettimeofday(&currentTime, NULL);
    startTime = (currentTime.tv_sec * 1000) + (currentTime.tv_usec / 1000);
    //wait if the queue is full(has no empty space)
    sem_wait(q->emptySpace);
    //wait if there is another process trying to enqueue or dequeue
    sem_wait(q->isBusy);
    printf("before enqueue. queue->end = %d\n",q->end);
    //critical section
    q->queueLine[q->end] = string;
    //DELETE
    printf("after enqueue\n");
    printf("string enqueued at index: %d, value: %s\n", q->end,string);
    q->end = (q->end + 1) % (q->size);
    //increment enqueueCount
    q->enqueueCount++;
    
    sem_post(q->isBusy);
    sem_post(q->filledSpace);
    
    sem_wait(q->recordTime);
    //record enqueueTime
    gettimeofday(&currentTime, NULL);
    endTime = (currentTime.tv_sec * 1000) + (currentTime.tv_usec / 1000);
    q->enqueueTime += (endTime - startTime);
	printf("curr enqueueTime: %d\n", q->enqueueTime);//DELETE
    sem_post(q->recordTime);
}

/*
 * Remove the first string of the queue
 * If another thread is doing enqueue, will wait
 */
char *DequeueString(Queue *q) {
    //start a time count dequeueTime
    int startTime, endTime;
    struct timeval currentTime; //sec is seconds, usec is microseconds - declared in time.h
    gettimeofday(&currentTime, NULL);
    startTime = (currentTime.tv_sec * 1000) + (currentTime.tv_usec / 1000);
    //check if the queue is empty
    sem_wait(q->filledSpace);
    //wait if there is another process trying to enqueue or dequeue
    sem_wait(q->isBusy);
    //critical section
	char *string = (q->queueLine)[q->head];
    //DELETE
    printf("string dequeued at index: %d, value: %s\n", q->head,string);
    q->head = (q->head + 1) % 10;
    //increment dequeueCount
    q->dequeueCount++;
    sem_post(q->isBusy);
    sem_post(q->emptySpace);
 
    sem_wait(q->recordTime);
    //record dequeueTime
    gettimeofday(&currentTime, NULL);
    endTime = (currentTime.tv_sec * 1000) + (currentTime.tv_usec / 1000);
    q->dequeueTime += (endTime - startTime);
	printf("curr dequeueTime: %d\n", q->dequeueTime);//DELETE
    sem_post(q->recordTime);
	
    return string;
}

/*
 * Prints the statistics for the queue
 */
void PrintQueueStats(Queue *q) {
    printf("enqueueCount: %d\ndequeueCount: %d\nenqueueTime: %d\ndequeueTime: %d\n", q->enqueueCount, q->dequeueCount, q->enqueueTime, q->dequeueTime);
}

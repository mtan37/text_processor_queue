#include <string.h>
#include <sys/time.h>
#include "queue.h"
#include "util.h"

/*
 * Allocate and initialize a new Queue struct in the mem
 * the size of the queue equals to the pass in size
 */
Queue *CreateStringQueue(int size) {
    Queue *queue = calloc_w(1, sizeof(Queue));
    queue->recordTime = calloc_w(1,sizeof(sem_t));
    queue->isBusy = calloc_w(1,sizeof(sem_t));
    queue->filledSpace = calloc_w(1,sizeof(sem_t));
    queue->emptySpace = calloc_w(1,sizeof(sem_t));
    queue->enqueueCount = 0;
    queue->dequeueCount = 0;
    queue->enqueueTime = 0;
    queue->dequeueTime = 0;
    queue->queueLine = calloc_w(size,sizeof(char*));
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
    double startTime, endTime;
    struct timeval currentTime; //sec is seconds, usec is microseconds - declared in time.h
    gettimeofday(&currentTime, NULL);
    //in sec
    startTime = (currentTime.tv_sec) + (currentTime.tv_usec / 1e6);
    sem_wait(q->emptySpace);
    //wait if there is another process trying to enqueue or dequeue
    sem_wait(q->isBusy);
    //critical section
    q->queueLine[q->end] = string;
    q->end = (q->end + 1) % (q->size);
    //increment enqueueCount
    q->enqueueCount++;
    
    sem_post(q->isBusy);
    sem_post(q->filledSpace);
    
    sem_wait(q->recordTime);
    //record enqueueTime
    gettimeofday(&currentTime, NULL);
    endTime = (currentTime.tv_sec) + (currentTime.tv_usec / 1e6);
    q->enqueueTime += (endTime - startTime);
    sem_post(q->recordTime);
}

/*
 * Remove the first string of the queue
 * If another thread is doing enqueue, will wait
 */
char *DequeueString(Queue *q) {
    //start a time count dequeueTime
    double startTime, endTime;
    struct timeval currentTime; //sec is seconds, usec is microseconds - declared in time.h
    gettimeofday(&currentTime, NULL);
    startTime = (currentTime.tv_sec) + (currentTime.tv_usec / 1e6);
    //check if the queue is empty
    sem_wait(q->filledSpace);
    //wait if there is another process trying to enqueue or dequeue
    sem_wait(q->isBusy);
    //critical section
	char *string = (q->queueLine)[q->head];
    q->head = (q->head + 1) % 10;
    //increment dequeueCount
    q->dequeueCount++;
    sem_post(q->isBusy);
    sem_post(q->emptySpace);
 
    sem_wait(q->recordTime);
    //record dequeueTime
    gettimeofday(&currentTime, NULL);
    endTime = (currentTime.tv_sec) + (currentTime.tv_usec / 1e6);
    q->dequeueTime += (endTime - startTime);
    sem_post(q->recordTime);
	
    return string;
}

/*
 * Prints the statistics for the queue
 */
void PrintQueueStats(Queue *q) {
    printf("enqueueCount: %d\ndequeueCount: %d\nenqueueTime: %f\ndequeueTime: %f\n", q->enqueueCount, q->dequeueCount, q->enqueueTime, q->dequeueTime);
}

#ifndef MEMREADER_H
#define MEMREADER_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

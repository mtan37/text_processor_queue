The program is consist of four modules
1. Reader
2. Munch1
3. Munch2
4. Writer

## Queue Class

There is a queue between each module that awaits processing. There will be a total of three queues
The header file of the queue class should include the following:
    - Queue *CreateStringQueue(int size)
    - void EnqueueString(Queue *q, char *string)
        This function places the pointer to the string at the end of queue q. If the queue is full, then this function blocks until there is space available.
    - char * DequeueString(Queue *q)
        This function removes a pointer to a string from the beginning of queue q. If the queue is empty, then this function blocks until there is a string placed into the queue. This function returns the pointer that was removed from the queue.
    - void PrintQueueStats(Queue *q)
        This function prints the statistics for this queue (see the next section for details).
    - enqueueCount
        A count of the number of strings enqueued on this queue
    - dequeueCount
        A count of the number of strings dequeued on this queue. We would expect that when the program exits, the two count values are equal.
    - enqueueBlockCount
        A count of the number of times that an enqueue was attempted but blocked.
    - dequeueBlockCount
        A count of the number of times that a dequeue was attempted but blocked.


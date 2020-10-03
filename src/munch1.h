#ifndef MUNCH1_H
#define MUNCH1_H
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "queue.h"

typedef struct Munch1Params {
    Queue *queue1;
    Queue *queue2;
} Munch1Params;

void *munch1ReadWrapper(void *data);

#endif

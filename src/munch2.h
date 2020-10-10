#ifndef MUNCH2_H
#define MUNCH2_H
#include "queue.h"

typedef struct Munch2Params {
    Queue *queue1;
    Queue *queue2;
} Munch2Params;

void *munch2ReadWrapper(void *data);
#endif

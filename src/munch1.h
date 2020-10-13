// Authors: Marvin Tan(mtan37) (marvin.tan@wisc.edu), Joseph Martin(jrmartin4) (jrmartin4@wisc.edu)
#ifndef MUNCH1_H
#define MUNCH1_H
#include "queue.h"

typedef struct Munch1Params {
    Queue *queue1;
    Queue *queue2;
} Munch1Params;

void *munch1ReadWrapper(void *data);

#endif

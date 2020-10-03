#ifndef READER_H
#define READER_H
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "queue.h"
void *startReadWrapper(void *data);
#endif

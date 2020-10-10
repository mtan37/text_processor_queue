#ifndef UTIL_H
#define UTIL_H
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
//defining error check function wrappers for library functions


void *calloc_w(size_t num, size_t size);

void pthread_create_w(pthread_t *thread, const pthread_attr_t *attr,
                   void *(*start_routine) (void *), void *arg);
void pthread_join_w(pthread_t thread, void **retval);

#endif

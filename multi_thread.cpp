//
// Created by ahmad on 11/12/17.
//

#include <pthread.h>
#include <cmath>
#include <pthread.h>
#include <malloc.h>
#include "multi_thread.h"
#include "eratosthenes.h"

pthread_t *tids;
unsigned int max_tids_size;
unsigned int tids_size;

void *thread_handler(void *arg)
{
    long coefficient = (*(int *)arg);
    free(arg);
    remove_coefficients(coefficient);

    pthread_exit(0);
}

void start_multi_thread(long long size)
{
    init_array(size + 1);
    tids_size = 0;
    max_tids_size = sqrt(size) + 1;

    tids = (pthread_t *)malloc(tids_size * sizeof(pthread_t));

    for(size_t i = 2; i < size; ++i)
    {
        if (check_is_prime(i) && is_prime(i))
        {
            auto *tid = (pthread_t *)malloc(sizeof (pthread_t));

            auto *num = (long *)malloc(sizeof(long));
            (*num) = i;
            tids[tids_size++] = (*tid);
            pthread_create(tid, NULL, thread_handler, num);
        }
    }


    for(unsigned int i = 0; i < tids_size; ++i)
    {
        pthread_join(tids[i], NULL);
    }
}
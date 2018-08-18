//
// Created by ahmad on 11/12/17.
//

#include "multi_process.h"
#include "eratosthenes.h"
#include <math.h>
#include <iostream>
#include  <zconf.h>
#include  <sys/ipc.h>
#include  <sys/shm.h>
#include <sys/wait.h>


key_t  ShmKEY;          // Shared memory key
void process_handle();
long long size;
pid_t *pids;
size_t pids_size;
size_t pids_last_index;

void process_handle(long long coefficient);

void start_multi_process(long long psize)
{
    using namespace std;
    int   ShmID;

    size = psize + 1;
    pids_size = sqrt(size);
    pids_last_index = 0;

    // Init the shared memory
    ShmKEY = ftok(".", 'x');        // Get the shared memory key
    ShmID = shmget(ShmKEY, size * sizeof(bool), IPC_CREAT | 0666);
    if (ShmID < 0) {
        printf("*** shmget error (server) ***\n");
        exit(1);
    }

    pids = (pid_t *)malloc(pids_size * sizeof(pid_t));

    bool *arr = (bool *) shmat(ShmID, NULL, 0);

    init_array(size, arr);



    for(long long i = 2; i < size; ++i)
    {
        if (check_is_prime(i, arr))
        {
            pid_t pid;
            if ((pid = fork()) == 0)
            {
                pids[pids_last_index ++] = getpid();
                process_handle(i);
            }
        }
    }

    while (wait(NULL) > 0);
}

void process_handle(long long coefficient)
{
    int   ShmID = shmget(ShmKEY, size * sizeof(bool), 0666);
    auto *arr = (bool *) shmat(ShmID, NULL, 0);
    remove_coefficients(coefficient, arr);
    exit(0);
}
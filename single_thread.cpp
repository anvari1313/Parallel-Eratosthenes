//
// Created by ahmad on 11/12/17.
//

#include "single_thread.h"
#include "eratosthenes.h"

void start_single_thread(long long size)
{
    init_array(size);
    for (long long i = 2; i < size + 1; ++i)
    {
        if (check_is_prime(i))
            if (is_prime(i))
                remove_coefficients(i);
    }

//    print();

}
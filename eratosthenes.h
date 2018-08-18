#pragma once

#include <cstddef>

void init_array(size_t);
void init_array(size_t, bool *);                // Used for multi process
bool check_is_prime(size_t);
bool check_is_prime(size_t, bool *);            // Used for multi process
bool is_prime(long long);
void mark_as_prime(size_t);
void mark_as_prime(size_t, bool *);             // Used for multi process
void mark_as_not_prime(size_t);
void mark_as_not_prime(size_t, bool *);         // Used for multi process
void remove_coefficients(size_t);
void remove_coefficients(size_t, bool *);       // Used for multi process
void print();
void print(bool *);                             // Used for multi process
void free_resource();
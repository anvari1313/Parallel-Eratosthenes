#include "eratosthenes.h"
#include <malloc.h>
#include <math.h>
#include <cstdio>

size_t arr_size;
bool *arr;

void init_array(size_t size)
{
	arr_size = size + 1;	// For including 0
	arr = static_cast<bool *>(malloc(arr_size * sizeof(bool)));
	for (size_t i = 0; i < arr_size; ++i)
	{
		arr[i] = true;
	}
}

void init_array(size_t size, bool *arr_ptr)		// Used for multi process
{
	arr_size = size;	// For including 0
	arr = arr_ptr;
	for (size_t i = 0; i < arr_size; ++i)
	{
		arr[i] = true;
	}
}

bool check_is_prime(size_t index)
{
	return arr[index];
}

bool check_is_prime(size_t index, bool *_arr)
{
	return _arr[index];
}

bool is_prime(long long num)
{
	for (int i = 2; i <= sqrt(num); ++i)
	{
		if (num % i == 0) return false;
	}

	return true;
}

void mark_as_prime(size_t index)
{
	arr[index] = true;
}

void mark_as_prime(size_t index, bool *_arr)
{
	_arr[index] = true;
}

void mark_as_not_prime(size_t index)
{
	arr[index] = false;
}

void mark_as_not_prime(size_t index, bool *_arr)
{
	_arr[index] = false;
}

void remove_coefficients(size_t prime_num)
{
	for (int i = 2 * prime_num; i < arr_size; i += prime_num)
	{
		arr[i] = false;
	}
}

void remove_coefficients(size_t prime_num, bool * _arr)
{
	for (int i = 2 * prime_num; i < arr_size; i += prime_num)
	{
		_arr[i] = false;
	}
}

void free_resource()
{
	free(arr);
}

void print()
{
	for (size_t i = 0; i < arr_size; ++i)
	{
		printf("%u -> %s\n", i, (arr[i] == true)? "true":"false");
	}
}

void print(bool * _arr)
{
	for (size_t i = 0; i < arr_size; ++i)
	{
		printf("%u -> %s\n", i, (_arr[i] == true)? "true":"false");
	}
}
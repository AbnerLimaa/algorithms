#include "prime.h"

int is_prime(unsigned long long int number, int square_root)
{
    if (number == 2)
        return 1;
    if (number < 2 || number % 2 == 0)
        return 0;
    int i = 3;
    while(i <= square_root)
    {
        if (number % i == 0)
            return 0;
        i += 2;
    }
    return 1;
}

int is_prime_naive(unsigned long long int number)
{
    if (number < 2)
        return 0;
    int i = 2;
    while (i < number)
    {
        if (number % i == 0)
            return 0;
        i++;
    }
    return 1;
}
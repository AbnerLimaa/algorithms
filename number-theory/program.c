#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "prime.h"

enum { NS_PER_SECOND = 1000000000 };

void sub_timespec(struct timespec t1, struct timespec t2, struct timespec *td)
{
    td->tv_nsec = t2.tv_nsec - t1.tv_nsec;
    td->tv_sec  = t2.tv_sec - t1.tv_sec;
    if (td->tv_sec > 0 && td->tv_nsec < 0)
    {
        td->tv_nsec += NS_PER_SECOND;
        td->tv_sec--;
    }
    else if (td->tv_sec < 0 && td->tv_nsec > 0)
    {
        td->tv_nsec -= NS_PER_SECOND;
        td->tv_sec++;
    }
}

void test_prime_algorithm(unsigned long long int number)
{
    struct timespec start;
    struct timespec end;
    struct timespec spent_time;
    int square_root = sqrt(number);
    
    clock_gettime(CLOCK_MONOTONIC, &start);
    int result = is_prime(number, square_root);
    clock_gettime(CLOCK_MONOTONIC, &end);

    sub_timespec(start, end, &spent_time);
    printf("\nPrime algorithm result: %d\nSpent time: %d.%.9ld s\n", result, (int)spent_time.tv_sec, spent_time.tv_nsec);
}

void test_naive_prime_algorithm(unsigned long long int number)
{
    struct timespec start;
    struct timespec end;
    struct timespec spent_time;

    clock_gettime(CLOCK_MONOTONIC, &start);
    int result = is_prime_naive(number);
    clock_gettime(CLOCK_MONOTONIC, &end);

    sub_timespec(start, end, &spent_time);
    printf("\nNaive prime algorithm result: %d\nSpent time: %d.%.9ld s\n", result, (int)spent_time.tv_sec, spent_time.tv_nsec);
}

int main(void) 
{
    //you could test for 2305843009213693951
    system("clear");
    signed long long int number;
    do
    {
        printf("please input a number thats positive\n");
        scanf("%lli", &number);
    } while (number < 0);

    test_prime_algorithm(number);
    test_naive_prime_algorithm(number);

    return 0;
}
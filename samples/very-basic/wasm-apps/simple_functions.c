// 
//
// 

double calculate_e(int N) {
    double fac = 1.0;
    double e = 1.0;

    for (int n = 1; n <= N; n++) {
        fac *= n;
        e += 1.0 / fac;
    }

    return e;
}

#define declare_simple_sum(type) type simple_sum_##type(type a, type b, type c) { return a + b + c; }

typedef long long int64;
declare_simple_sum(int)
declare_simple_sum(int64)
declare_simple_sum(float)
declare_simple_sum(double)

typedef int bool;
#define true 1
#define false 0

bool is_prime(int num) {
    if (num < 2) return false;

    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

int count_primes(int n) {
    int primeCount = 0;
    
    for (int i = 0; i <= n; i++) {
        if (is_prime(i)) primeCount++;
    }
    
    return primeCount;
}

void void_return(int a, float b) { double c = a + b; }

#include <stdio.h>

void hello_world() { printf("Hello, world!\n"); }

void print_prime_numbers(int limit, int interval, int offset) {
    int counter = 0;
    
    for (int i = 0; i <= limit; i++) {
        if (is_prime(i)) {
            counter++;

            if ((counter + offset) % interval == 0) {
                printf("Prime number #%d: %d\n", counter, i);
            }
        }
    }
}

int calculate_percentage(long long num, long long den) {
    return (int)(100 * num / den);
}

long long long_sum_test(long long iter_count, int interval, long long start) {
    long long sum = 0;
    long long step = start;

    printf("long_sum_test(): starting calculation...\n");

    int last_perc = 0;

    for (long long i = 0; i < iter_count; i += 10) {
        sum += step;
        step += interval;

        int new_perc = calculate_percentage(i + 1, iter_count);
        if (new_perc > last_perc) {
            last_perc = new_perc;
            printf("Calculating... %2d%%\n", new_perc);
        }
    }

    printf("long_sum_test() complete: %lld\n", sum);

    return sum;
}


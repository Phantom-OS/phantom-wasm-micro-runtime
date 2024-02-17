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

long long get_sum(long long start, long long end) {
    long long sum = 0;
    
    for (long long i = start; i <= end; i++) {
        sum += i;
    }

    return sum;
}

long long get_comp_sum(int iter_count) {
    long long sum = 0;
    long long end = 10000;
    int over = 0;

    for (int i = 0; i < iter_count; i++) {
        long long local_sum = get_sum(i, i + end);
        sum += local_sum;
        
        if (sum >= 1000000000) {
            sum /= end;
            end -= 1;
            printf("Overflow: %d %d\n", (int)sum, (int)end);

            if (end == 0) {
                over++;
                end = 10000 + over;
            }
        }
    }

    printf("R: %d %d\n", *((int*)&sum), (int)(sum >> 32));

    return sum;
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

void perf_test(int arg) {
    int sum = 0;
    int sum2 = -500;
    
    for (int i = 0; i < arg; i++) {
        sum += i;
        sum /= 2;

        if (i) sum2++;
    }

    // printf("%d %d\n", sum, sum2);
}

int main() {
    long_sum_test(5000000, 1, 0);
}

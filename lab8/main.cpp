#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void swap (int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void randomize (int* arr, int n) {
    srand (time(NULL));

    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);

        swap(&arr[i], &arr[j]);
    }
}

void create_array(int* array, int N) {
    for (int i = 0; i < N - 1; i++) {
        array[i] = i + 1;
    }
    array[N - 1] = 0;
}

void create_reversed_array(int* array, int N) {
    array[0] = N - 1;
    for (int i = 1; i < N; i++) {
        array[i] = i - 1;
    }
}

void create_randomized_array(int* array, int N) {
    create_array(array, N);
    randomize(array, N);
}

int main() {
    double total_time_normal;
    double total_time_reversed;
    double total_time_randomized;

    int K = 128;

    int N_min = 256;
    int N_max = 8500000;
    for(int N = N_min; N < N_max; N *= 2) {
        int* array = (int*)calloc(sizeof(int), N);
        create_array(array, N);
        for (volatile int k = 0, i = 0; i < N; i++) {
            k = array[k];
        }

        unsigned long long start = __builtin_ia32_rdtsc();
        for (volatile int k = 0, i = 0; i < N*K; i++) {
            k = array[k];
        }
        unsigned long long finish = __builtin_ia32_rdtsc();

        total_time_normal = (finish - start) * 1.0 / (N * 1.0 * K);


        create_reversed_array(array, N);
        for (volatile int k = 0, i = 0; i < N; i++) {
            k = array[k];
        }
        start = __builtin_ia32_rdtsc();
        for (volatile int k = 0, i = 0; i < N*K; i++) {
            k = array[k];
        }
        finish = __builtin_ia32_rdtsc();
        total_time_reversed = (finish - start) * 1.0 / (N * 1.0 * K);

        create_randomized_array(array, N);
        for (volatile int k = 0, i = 0; i < N; i++) {
            k = array[k];
        }
        start = __builtin_ia32_rdtsc();
        for (volatile int k = 0, i = 0; i < N*K; i++) {
            k = array[k];
        }
        finish = __builtin_ia32_rdtsc();
        total_time_randomized = (finish - start) * 1.0 / (N * 1.0 * K);
        free(array);

        //cout << "N = "<< N << " ";
        cout << (double) total_time_normal << " ";
        cout << (double) total_time_reversed << " ";
        cout << (double) total_time_randomized << " ";
        cout << endl;
    }
    return 0;
}

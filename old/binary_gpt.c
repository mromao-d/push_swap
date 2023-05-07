#include <stdio.h>
#include <stdlib.h>

int rank(int x, int k) {
    int count = 0;
    int i = 0;
    while (i < 32 && count < k) {
        if ((x & 1) == 1) {
            count++;
            if (count == k) {
                return i;
            }
        }
        x = x >> 1;
        i++;
    }
    return -1;
}

void rank_numbers(int argc, char *argv[]) {
    int num_array[argc-1];
    int order_array[argc-1]; // added to store the order of the numbers
    int i = 0;
    while (i < argc-1) {
        num_array[i] = atoi(argv[i+1]);
        order_array[i] = i; // initialize order array with original index
        i++;
    }
    int j = 0;
    while (j < argc-1) {
        int min_index = j;
        int k = j + 1;
        while (k < argc-1) {
            if (num_array[k] < num_array[min_index]) {
                min_index = k;
            }
            k++;
        }
        int tmp = num_array[j];
        num_array[j] = num_array[min_index];
        num_array[min_index] = tmp;
        // update order array based on the current order of the sorted numbers
        tmp = order_array[j];
        order_array[j] = order_array[min_index];
        order_array[min_index] = tmp;
        j++;
    }
    // print the order of the original numbers
    for (i = 0; i < argc-1; i++) {
        printf("%d: %d\n", rank(num_array[i], order_array[i]), num_array[i]);
    }
}


int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <num1> <num2> ... <numN>\n", argv[0]);
        return 1;
    }
    rank_numbers(argc, argv);
    return 0;
}

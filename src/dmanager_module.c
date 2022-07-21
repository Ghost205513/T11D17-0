#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "door_struct.h"

#define DOORS_COUNT 15
#define MAX_ID_SEED 10000

void initialize_doors(struct door* doors);
void sort(door *array);
void qs(door *array, int left, int right);

int main() {
    door doors[DOORS_COUNT];

    initialize_doors(doors);

    #ifdef doors_sort
        for (int i = 0; i < DOORS_COUNT; i++)
            doors[i].status = 0;

        sort(doors);

        for (int i = 0; i < DOORS_COUNT; i++)
            printf("%d, %d\n", doors[i].id, doors[i].status);
    #endif

    return 0;
}

// Doors initialization function
// ATTENTION!!!
// DO NOT CHANGE!
void initialize_doors(struct door* doors) {
    srand(time(0));

    int seed = rand() % MAX_ID_SEED;

    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].id = (i + seed) % DOORS_COUNT;
        doors[i].status = rand() % 2;
    }
}

void sort(door *array) {
    qs(array, 0, DOORS_COUNT - 1);
}

void qs(door *array, int left, int right) {
    int i, j;
    int x;

    i = left;
    j = right;
    x = array[(left + right) / 2].id;

    do {
        while (i < right && array[i].id < x)
            i++;

        while (j > left && x < array[j].id)
            j--;

        if (i <= j) {
            int temp_id = array[i].id;
            int temp_status = array[i].status;
            array[i].id = array[j].id;
            array[i].status = array[j].status;
            array[j].id = temp_id;
            array[j].status = temp_status;
            i++;
            j--;
        }
    } while (i <= j);

    if (left < j)
        qs(array, left, j);

    if (i < right)
        qs(array, i, right);
}

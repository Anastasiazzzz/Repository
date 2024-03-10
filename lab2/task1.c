#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_mass(int mass[], int size) {
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", mass[i]);
    }
}


void main() {
    int size = 10;
    int mass[size];

    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        mass[i] = 1 + rand()%100;
    }
    
    print_mass(mass, size);
}
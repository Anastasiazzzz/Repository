//Написать программу, которая генерирует массив из псевдослучайных целых чисел и записывает в файл в обратном порядке.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, char *argv[]) {
    int size = atoi(argv[1]);
    int mass[size];

    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        mass[i] = 1 + rand()%100;
    }


    FILE *file = fopen(argv[1], "w");

    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    for (int i = size-1; i >= 0; i--) {
        fprintf(file, "%d ", mass[i]);
    }

    fclose(file);

    return 0;
}
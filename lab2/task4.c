/*Написать программу, которая в качестве аргумента принимает размер произвольного массива, создает его, заполняет случайными числами с плавающей точкой в интервале (arg1, arg2), где arg1 и arg2 - также аргументы, вводимые при запуске программы, и выводит массив в консоль. Далее программа записывает массив в файл в отсортированном виде.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int compare_mass(const void* a, const void* b){
    float elem1 = *(const float*)a;
    float elem2 = *(const float*)b;

    if (elem1 > elem2) {
        return 1;
    }
    else if (elem1 < elem2)
    {
        return -1;
    }
    else {
        return 0;
    }
}


void print_mass(float mass[], int size) {
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", mass[i]);
    }
}


int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Error: you need to enter the size of the array and arguments");
        return 1;
    }
    
    int size = atoi(argv[1]);
    float arg1 = atof(argv[2]);
    float arg2 = atof(argv[3]);

    if (size <= 0) {
        printf("Error: array size must be greater than 0\n");
        return 1;
    }

    float mass[size];

    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        mass[i] = ((float)rand() / RAND_MAX) * (arg2-arg1) + arg1;
    }


    print_mass(mass, size);


    qsort(mass, size, sizeof(float), compare_mass);


    FILE *file = fopen(argv[1], "w");

    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    for (int i = 0; i < size; i++) {
        fprintf(file, "%d ", mass[i]);
    }

    fclose(file);

    return 0;
}
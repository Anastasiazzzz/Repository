//Написать программу, которая в качестве аргумента принимает размер произвольного массива, создает его, заполняет случайными числами с плавающей точкой в интервале (0, 1) и выводит этот массив в консоль.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Error: you need to enter the size of the array");
        return 1;
    }
    
    int size = atoi(argv[1]);
    
    if (size <= 0) {
        printf("Error: array size must be greater than 0\n");
        return 1;
    }

    float mass[size];

    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        mass[i] = (float)rand() / RAND_MAX;
    }

    for (int i = 0; i < size; i++) {
        printf("%.1f ", mass[i]);
    }
    

    return 0;
}
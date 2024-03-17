// Создать структуру для хранения данных о названии и цене товара. Считать из входного файла данные о товарах. Написать функцию для сортировки товаров по цене. Вывести отсортированные данные в выходной файл.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// структура для хранения данных о товарах
struct List { 
    char name[10];
    float price;
};


void insertionSort(struct List arr[], int n) {
    for (int i = 1; i < n; i++) {
        struct List key = arr[i]; // копия структуры массива под индексом
        int j = i - 1;
        while (j >= 0 && arr[j].price > key.price) { // [3, 6, 4] -> [3, 6, 6] -> [3, 4, 6]
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


int main(int argc, char *argv[]) {
    FILE *inputFile = fopen(argv[1], "r");
    FILE *outputFile = fopen("output.txt", "w");

      if (inputFile == NULL || outputFile == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    int n = 10;
    struct List products[n];

    // считать данные из файла
    for (int i = 0; i < n; i++) {
        fscanf(inputFile, "%s%f", products[i].name, &products[i].price);
    }

    insertionSort(products, n);

    // запись отсортированных данных в файл
    for (int i = 0; i < n; i++) {
        fprintf(outputFile, "%s %.2f\n", products[i].name, products[i].price);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
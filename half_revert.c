
/*Дана последовательность чисел.Конец последовательности - 1.
Вывести в порядке Вывести x1 xn x2 xn-1 x3 xn-2 и так далее
Реализация через динамический массив */

#include <stdio.h>
#include <stdlib.h>

void input_array(int*, int*, int*);
void output_array(int*, int);

int main() {
    int error = 0, count = 0;
    int* array = (int*)malloc(sizeof(int));
    if (array == NULL)
        printf("n/a");
    else {
        input_array(array, &error, &count);
        if (error == 1)
            printf("n/a");
        else {
            output_array(array, count);
        }
        free(array);
    }
    return 0;
}

void input_array(int* array, int* error, int* count) {
    int value;
    do {
        value = 0;
        if (!scanf("%d", &value))
            *error = 1;
        else {
            if (value != -1) {
                array[*count] = value;
                if (array == NULL) {
                    *error = 2;
                } else {
                    *count = *count + 1;
                }
            }
        }
    } while (value != -1 && *error == 0);
}

void output_array(int* array, int count) {
    for (int i = 0; i < count / 2; i++) {
        printf("%d ", array[i]);
        if (i == count / 2 - 1)
            printf("%d", array[count - i - 1]);
        else
            printf("%d ", array[count - i - 1]);
    }
    if (count % 2 != 0) printf(" %d", array[count / 2]);
}

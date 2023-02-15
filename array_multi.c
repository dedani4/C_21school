#include <stdio.h>
#include <stdlib.h>

// void input_size(int *, int *);
// void input_array(int **, int, int *);
// void multi_array(int **, int **, int **, int);
// void output_array(int **, int);

void input_size(int *, int *);
void input_array(int array[20][20], int, int *);
void multi_array(int array1[20][20], int array2[20][20], int array_res[20][20], int);
void output_array(int array[20][20], int);

int main() {
    int n, error = 0;
    input_size(&n, &error);
    if (error == 1)
        printf("n/a");
    else {
        int array1[20][20] = {0}, array2[20][20] = {0}, array_res[20][20] = {0};

        // int **array1 = (int **)malloc(sizeof(int *) * n + sizeof(int) * n * n);
        // int **array2 = (int **)malloc(sizeof(int *) * n + sizeof(int) * n * n);

        // if (array1 == NULL || array2 == NULL)
        //     printf("n/a");
        // else {
        // int *prow1 = (int *)(array1 + n);
        // int *prow2 = (int *)(array2 + n);
        // for (int i = 0; i < n; i++) {
        //     array1[i] = prow1 + i * n;
        //     array2[i] = prow2 + i * n;
        // }
        input_array(array1, n, &error);
        // output_array(array1, n);
        input_array(array2, n, &error);
        // output_array(array2, n);
        if (error == 1)
            printf("n/a");
        else {
            // int **array_res = (int **)malloc(sizeof(int *) * n + sizeof(int) * n * n);
            // if (array_res == NULL)
            //     printf("n/a");
            // else {
            multi_array(array1, array2, array_res, n);
            output_array(array_res, n);
            // free(array_res);
            // }
            // }
        }
        // if (array1 != NULL) free(array1);
        // if (array2 != NULL) free(array2);
    }
    return 0;
}

void input_size(int *n, int *error) {
    if (!scanf("%d", n))
        *error = 1;
    else if (getchar() != '\n')
        *error = 1;
}

// void input_array(int **array, int n, int *error) {
void input_array(int array[20][20], int n, int *error) {
    char sep;
    for (int i = 0; i < n && *error == 0; i++) {
        for (int j = 0; j < n && *error == 0; j++) {
            // printf("check 1");
            if (!scanf("%d", &array[i][j]))
                *error = 1;
            else if ((sep = getchar()) != ' ' && sep != '\n')
                *error = 1;
        }
    }
    // printf("check**");
}

void multi_array(int array1[20][20], int array2[20][20], int array_res[20][20], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int temp = 0;
            for (int k = 0; k < n; k++) {
                temp += array1[i][k] * array2[k][j];
            }
            array_res[i][j] = temp;
        }
    }
}

// void output_array(int **array, int n) {
void output_array(int array[20][20], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", array[i][0]);
        for (int j = 1; j < n; j++) {
            printf(" %d", array[i][j]);
        }
        if (i != n - 1) printf("\n");
    }
}

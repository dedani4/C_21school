#include <stdio.h>
#include <stdlib.h>

void input_size(int *, int *, int *);
void input_array(int **, int, int, int *);
void output_array(int **, int, int);

int main() {
    int m, n, error = 0;
    input_size(&m, &n, &error);
    if (error == 1)
        printf("n/a");
    else {
        int **array = (int **)malloc(sizeof(int *) * m + sizeof(int) * m * n);
        if (array == NULL)
            printf("n/a");
        else {
            int *prow = (int *)(array + m);
            for (int i = 0; i < m; i++) {
                array[i] = prow + i * n;
            }
            input_array(array, m, n, &error);
            if (error == 1)
                printf("n/a");
            else {
                output_array(array, m, n);
            }
        }
        free(array);
    }
}

void input_size(int *m, int *n, int *error) {
    if (scanf("%d%d", m, n) != 2)
        *error = 1;
    else if (getchar() != '\n')
        *error = 1;
}

void input_array(int **array, int m, int n, int *error) {
    char sep;
    for (int i = 0; i < m && *error == 0; i++) {
        for (int j = 0; j < n && *error == 0; j++) {
            if (!scanf("%d", &array[i][j]))
                *error = 1;
            else if ((sep = getchar()) != ' ' && sep != '\n')
                *error = 1;
        }
    }
}

void output_array(int **array, int m, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", array[m - 1][i]);
        for (int j = 1; j < m; j++) {
            printf(" %d", array[m - j - 1][i]);
        }
        if (i != n - 1) printf("\n");
    }
}
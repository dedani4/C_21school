#include <stdio.h>
#include <stdlib.h>

void input_size(int *, int *);
void input_array(int **, int);
void output_array(int **, int);

int main()
{
    int n, error = 0;
    input_size(&n, &error);
    if (error == 1)
        printf("n/a");
    else
    {
        int **array = (int **)malloc(sizeof(int *) * n + sizeof(int) * n * n);
        if (array == NULL)
            printf("n/a");
        else
        {
            int *prow = (int *)(array + n);
            for (int i = 0; i < n; i++)
            {
                array[i] = prow + i * n;
            }
            input_array(array, n);
            output_array(array, n);
            free(array);
        }
    }
    return 0;
}

void input_size(int *n, int *error)
{
    if (!scanf("%d", n))
        *error = 1;
    else if (getchar() != '\n')
        *error = 1;
}

void input_array(int **array, int n)
{
    int value = 1;
    int r_max = 0, r_min = 0, c_max = 0, c_min = 0;
    int i = 0, j = 0;

    while (value <= n * n)
    {
        array[i][j] = value;
        if (i == r_min && j < n - c_max - 1)
            ++j;
        else if (j == n - c_max - 1 && i < n - r_max - 1)
            ++i;
        else if (i == n - r_max - 1 && j > c_min)
            --j;
        else
            --i;

        if ((i == r_min + 1) && (j == c_min) && (c_min != n - c_max - 1))
        {
            ++r_min;
            ++r_max;
            ++c_min;
            ++c_max;
        }
        value++;
    }
}

void output_array(int **array, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%3d", array[i][0]);
        for (int j = 1; j < n; j++)
        {
            printf(" %3d", array[i][j]);
        }
        if (i != n - 1)
            printf("\n");
    }
}

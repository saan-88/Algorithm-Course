#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPower2(int n)
{
    int q = 1, r = 0;
    while(q!=0 && n > 1)
    {
        r = n % 2;
        q = n / 2;
        n = n / 2;
        if (r != 0)
        {
            return false;
        }
    }
    return true;
}

// fillz function
void fillz(int **matrix, int i, int j, int n, int x)
{
    // Base case
    if (n == 1)
    {
        matrix[i][j] = x;
    }
    else
    {
        fillz(matrix, i, j, n/2, x);
        x = x + (n * n) / 4;
        fillz(matrix, i, j + n / 2, n / 2, x);
        x = x + (n * n) / 4;
        fillz(matrix, i + n / 2, j, n / 2, x);
        x = x + (n * n) / 4;
        fillz(matrix, i + n / 2, j + n / 2, n / 2, x);
    }
}

int main()
{
    int n;
    printf("Input size (power of 2) of the matrix: ");
    scanf("%d", &n); 
    while (!isPower2(n))
    {
        printf("size must be a power of 2, input size: ");
        scanf("%d", &n);
    }

    int **matrix = (int **) malloc (n * sizeof(int*));

    // Allocating space for the rows
    for (int i = 0; i < n; i++)
    {
        matrix[i] = (int *) malloc (n * sizeof(int));
    }
     
    fillz(matrix, 0, 0, n, 1); // Just calling fillz function

    // Printing the matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("% 4d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    // Freeing all the row of the matrix
    for(int i = 0; i < n; i++)
    {
        free(matrix[i]);
    }

    //freeing the matrix itself
    free(matrix);
    
    
}
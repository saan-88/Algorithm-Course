#include <stdio.h>
#include <stdlib.h>

int i = 0, j = 0, di = 0, dj = 1;
int row, col, up, down, left, right;

// changepath function changes the direction whenever required
void changepath()
{
    if (di == 0 && dj == 1) // If it was going right, then we change the direction downwards
    {
        di = 1;
        dj = 0;
        up++;
    }
    else if (di == 1 && dj == 0) // If it was going downwards, then we change the direction towards left
    {
        di = 0;
        dj = -1;
        right--;
    }
    else if (di == 0 && dj == -1) // If it was going towards left, then we change the direction upwards
    {
        di = -1;
        dj = 0;
        down--;
    }
    else if (di == -1 && dj == 0) // If it was going upwards, we change the direction towards right
    {
        di = 0;
        dj = 1;
        left++;
    }
}

int main()
{
    
    printf("Input the size of the matrix: \n");

    printf("Number of rows: ");
    scanf("%d", &row);

    printf("Number of columns: ");
    scanf("%d", &col);


    up = 0;
    down = row - 1;
    left = 0;
    right = col - 1;


    // Allocating memory for storing the matrix
    int **matrix = (int **) malloc (row * sizeof(int*));
    for(int index = 0; index < row; index++)
    {
        matrix[index] = (int *) malloc (col * sizeof(int));
    }


    // Read the values of the matrix
    for (int rowindex = 0; rowindex < row; rowindex++)
    {
        for (int colindex = 0; colindex < col; colindex++)
        {
            scanf("%d", &matrix[rowindex][colindex]);
        }
    }

    
    // Printing the matrix in spiral shape
    for (int k = 0, matrixsize = row * col; k < matrixsize; k++)
    {
        printf("%d ", matrix[i][j]);

        if ((dj == 1 && j == right) || (di == 1 && i == down) || (dj == -1 && j == left) || (di == -1 && i == up))  // Checking whether we should change direction
        {
            changepath();
        }
        i = i + di;
        j = j + dj;
    }


    // Freeing the allocated memory
    for(int index = 0; index < row; index++)
    {
        free(matrix[index]);
    }

    free(matrix);
    
}
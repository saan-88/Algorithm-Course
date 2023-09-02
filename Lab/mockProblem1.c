#include <stdio.h>
#include <stdlib.h>

int main()
{
    int dimension;
    scanf("%d", &dimension);

    // Assign the n * n matrix
    int matrix[dimension][dimension];

    // Taking input for the matrix
    for (int i = 0; i < dimension; i++)
    {
        for (int j = 0; j < dimension; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    
    int totalSpace = dimension - 1, numSpace;
    for (int i = 0, height = 2 * dimension - 2; i <= height; i++)
    {
        
        numSpace = abs(totalSpace - i);
        //printf("%d", numSpace);
        if (numSpace > 0)
        {
            printf("%*c", numSpace, ' ');
        }
        
        for (int row = dimension - 1; row >= 0; row--)
        {
            for (int col = 0; col < dimension; col++)
            {
                if ((row + col) == i)
                {
                    printf("%d ", matrix[row][col]);
                }
            }
        }
        printf("\n");
    }
}

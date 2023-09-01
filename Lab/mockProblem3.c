#include <stdio.h>
#include <stdlib.h>

int myIndex(int *A, int x, int len)
{
    for(int i = 0; i < len; i++)
    {
        if (A[i] == x)
        {
            return i;
            break;
        }
    }
}

int main()
{
    int number;
    scanf ("%d", & number);
    int A[number], B[number];

    for (int i = 0; i < number; i++)
    {
        scanf("%d", &A[i]);
    }

    for (int i = 0; i < number; i++)
    {
        scanf("%d", &B[i]);
    }

    int value, candidate, max = -1, index_A, index_B;

    for (int i = 0; i < number; i++)
    {
        value = abs(myIndex(A, A[i], number) - myIndex(B, A[i], number));
        if (value > max)
        {
            max = value;
            candidate = A[i];
            index_A = myIndex(A, A[i], number);
            index_B = myIndex(B, A[i], number);
        }
    }
    //printf("%d %d", max, candidate);
    printf("%d %d %d", candidate, index_A, index_B);
    
}

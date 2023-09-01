#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    scanf("%d", &n);
    //int sqrt_n = sqrt(n);
    //printf("%d", sqrt_n);
    int divisors[n];

    int number = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            divisors[number] = i;
            number++;
        }
    }

    
    int c_divisors[number];
    for (int i = 0; i < number; i++)
    {
        c_divisors[i] = n / divisors[i];
    }
    

    /*
    for(int i = 0; i < number; i++)
    {
        printf("%d %d\n", divisors[i], c_divisors[i]);
    }
    */

    int array[n], myindex = 0;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[myindex]);
        myindex++;
    }

    for (int i = 0; i < number; i++)
    {
        myindex = 0;
        for (int row = 0; row < divisors[i]; row++)
        {
            for (int col = 0; col < c_divisors[i]; col++)
            {
                printf("%d ", array[myindex]);
                myindex++;
            }
            printf("\n");
        }
        printf("\n");
    }
}

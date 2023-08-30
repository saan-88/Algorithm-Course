#include <stdio.h>

int main()
{
    int array[10];
    char c;
    int x;

    // Initialization of array
    for (int i = 0; i < 10; i++) 
    {
        array[i] = 0;
    }

    while ('\n' != (c = getchar())) 
    {
        x = c - '0';
        array[x]++;
    }

    for (int i = 0; i < 10; i++) 
    {
        printf("%d ", array[i]);
    }

    // Making the sum
    int sum = 0;
    for (int i = 1; i < 10; i++) 
    {
        sum = sum + array[i] * i;
    }

    // Print sum
    printf("%d ", sum);

    if (sum % 3 == 0)
    {
        for (int i = 9; i >= 0; i--)
        {
            for (int j = 0; j < array[i]; j++)
            {
                printf("%c", i + '0');
            }
        }
    }

    else if (sum % 3 == 1)
    {
        if (array[1] >= 1)
        {
            array[1]--;
        }
        else if (array[4] >= 1)
        {
            array[4]--;
        }
        else if (array[7] >= 1)
        {
            array[7]--;
        }
        for (int i = 9; i >= 0; i--)
        {
            for (int j = 0; j < array[i]; j++)
            {
                printf("%c", i + '0');
            }
        }
    }

    else if (sum % 3 == 2)
    {
        if (array[2] >= 1)
        {
            array[2]--;
        }
        else if (array[5] >= 1)
        {
            array[5]--;
        }
        else if (array[8] >= 1)
        {
            array[8]--;
        }
        for (int i = 9; i >= 0; i--)
        {
            for (int j = 0; j < array[i]; j++)
            {
                printf("%c", i + '0');
            }
        }
    }
}
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Calculating the entropy function H
float H(int x, int y)
{
    // Taking separely the case x = 0 or y = 0 because log(0) is not defined
    if (x == 0 || y == 0 || x + y == 0)
    {
        return 0.0;
    }

    float result = -(((x * 1.0) / ( x + y)) * log2((x * 1.0) / ( x + y)) + ((y * 1.0) / ( x + y)) * log2((y * 1.0) / ( x + y)));
    return result;
}


int main()
{
    int number_0 = 0, number_1 = 0, number_q = 0;
    char c;
    
    // Taking Input and update the number of occurence of 0 and 1
    while ('\n' != (c = getchar()))
    {
        if (c == '0') number_0++;
        else if (c == '1') number_1++;
        else if (c == '?') number_q++;
    }

    // Calculating the maximum and minimum between the number_1 and number_0
    int max = number_1, min = number_0;
    if (number_0 > number_1)
    {
        max = number_0;
        min = number_1;
    }


    float min_value, max_value;
    if (number_q >= (max - min))
    {
        max_value = 1.0;
        min_value = H(max + number_q, min);
    }
    else
    {
        max_value = H(min + number_q, max);
        min_value = H(max + number_q, min);
    }
    
    printf("%.3f %.3f", min_value, max_value);
}
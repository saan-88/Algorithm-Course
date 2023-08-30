#include <stdio.h>

int main()
{
    float xMinRed, xMaxRed, yMinRed, yMaxRed, xMinBlue, xMaxBlue, yMinBlue, yMaxBlue;
    float x, y;
    char c;
    int initialRed = 0, initialBlue = 0;

    int n;
    scanf("%d", &n);


    // Taking input
    for(int i = 0; i < n; i++)
    {
        scanf("%f %f %c", &x, &y, &c);
        if (c == 'R')
        {
            // Initialize the Red Variables
            if (initialRed == 0)
            {
                xMinRed = x;
                xMaxRed = x;
                yMinRed = y;
                yMaxRed = y;
                initialRed++;
            }

            // Update x co-ordinate of Red
            if (x < xMinRed)
            {
                xMinRed = x;
            }
            else if (x > xMaxRed)
            {
                xMaxRed = x;
            }

            // Update y co-ordinate of Red
            if (y < yMinRed)
            {
                yMinRed = y;
            }
            else if (y > yMaxRed)
            {
                yMaxRed = y;
            }

        }
        else if (c == 'B')
        {
            // Initialize the y variables
            if (initialBlue == 0)
            {
                xMinBlue = x;
                xMaxBlue = x;
                yMinBlue = y;
                yMaxBlue = y;
                initialBlue++;
            }

            //Update x co-ordinate of Blue
            if (x < xMinBlue)
            {
                xMinBlue = x;
            }
            else if (x > xMaxBlue)
            {
                xMaxBlue = x;
            }

            // Update y co-ordinate of Blue
            if (y < yMinBlue)
            {
                yMinBlue = y;
            }
            else if (y > yMaxBlue)
            {
                yMaxBlue = y;
            }
        }
    }


    int isPossible = 0;

    // Check whether it is possible to divide them with line parallal to X axis
    if ((yMinRed > yMaxBlue) || (yMinBlue > yMaxRed))
    {
        printf("X");
        isPossible++;
    }

    // Check whether it is possible to divide them with line parallal to y axis
    if ((xMaxRed < xMinBlue) || (xMaxBlue < xMinRed))
    {
        printf("Y");
        isPossible++;
    }
    
    if (isPossible == 0){
        printf("Not possible");
    }
     
}
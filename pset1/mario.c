/***************************************************************************************************
Jay Usdonvudhikai
cs50 pset1 mario
5/23/2013
*****************************************************************************************************/

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        printf("Height: ");
        scanf("%i", &height);
        if (height == 0)
        {
            return 0;
        }
    }
    while (height < 1 | height > 23);

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < height - i - 1; j++)
        {
            printf(" ");
        }

        for (int k = 0; k < i + 2; k++)
        {
            printf("#");
        }
        printf("\n");
    } 
    return 0;
}

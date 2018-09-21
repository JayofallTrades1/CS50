/*****************************************************************************************************
Jay Usdonvudhikai
CS50 Pset 1 Greedy
5/23/2013
*****************************************************************************************************/

#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{

    float change;                                                       //declare variables
    int coins = 0;
    do
    {
        printf("How much change do you have: ");
        change = GetFloat();
    }
    while (change <= .00);

    change = (round)(change * 100);                                       //convert floats to integers

    if (change >= 25)                                                       //loop to add up coins
    {
        do
        {
            change = change - 25;
            coins++ ;
        }
        while (change >= 25);
    }
    if (change >= 10)
    {
        do
        {
            change = change - 10;
            coins++;
        }
        while (change >= 10);
    }
    if (change >= 5)
    {
        do
        {
            change = change - 5;
            coins++;
        }
        while (change >= 5);
    }
    if (change >= 1)
    {
        change = change - 1;
        coins++;
    }
    printf("%i\n", coins);

    return 0;
}


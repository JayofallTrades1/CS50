/******************************************************************************************
*Jay Usdonvudhikai
*
*5/26/2013
*
*vigenere.c
*
*accepts a keyword and converts the plain text to cipher text
*
*****************************************************************************************/
#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2)                                          //makes sure that user inputs 2 arguments
    {
        //if not, it exits and returns 1
        printf("Usage: Keyword not detected\n");
        return 1;
    }

    for (int i = 0, n = strlen(argv[1]); i < n; i++)       //checks that the keyword is only alpha characters
    {
        if (!isalpha(argv[1][i]))                           //exits and returns 1 if not
        {
            printf("Keyword must only have alphabetical letters.\n");
            return 1;
        }
    }

    string keyword = argv[1];                                   //converts argument into string

    int keylen = strlen(keyword);

    for (int i = 0; i < keylen; i++)                            //converts each letter in keyword to an int
    {
        if (isupper(keyword[i]))
        {
            keyword[i] = keyword[i] - 'A';
        }

        else if (islower(keyword[i]))
        {
            keyword[i] = keyword[i] - 'a';
        }

        else
        {
            return 0;
        }
    }

    string text;
    do
    {
        text = GetString();                                           //user input for plaiin text
    }
    while (text == NULL);

    for (int i = 0, j = 0, len = strlen(text); i < len; i++)             //loop to convert plain text into cipher text
    {

        if (isupper(text[i]))
        {
            int cipher = (text[i] - 'A' + keyword[j]) % 26 + 'A';     //algorithm to convert
            j++;                                                      //increments next char in keyword
            j %= keylen;                                              //wrap around
            printf("%c", cipher);

        }
        else if (islower(text[i]))
        {
            int cipher = (text[i] - 'a' + keyword[j]) % 26 + 'a';
            j++;
            j %= keylen;
            printf("%c", cipher);
        }
        else
        {
            printf("%c", text[i]);
        }

    }
    printf("\n");
    return 0;
}

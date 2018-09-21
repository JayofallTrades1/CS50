/*************************************************************************************************************
*Jay Usdonvudhikai
*caesar.c
*5/25/2013
*
*Takes and input string from user and converts it to cipher text sing a key as an argument
*
*************************************************************************************************************/
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2 | argv[1] < 0)                                                   //makes sure that they are 2 arguments
    {
        printf("Usage: invalid arguments\n");
        return 1;
    }


    int key = atoi(argv[1]);
    string message;                                            //converts the string to an integer

    do
    {
        message = GetString();
    }
    while (message == NULL);                                                 //user input for string

    for (int i = 0, n = strlen(message); i < n; i++)                          //loop to convert each character in string
    {
        if (isalpha(message[i]))
        {
            if(isupper(message[i]))                                          //check conditions and convert to cipher text
            {
                message[i] = (message[i] - 'A' + key) % ('Z' - 'A') + 'A';                 //algorithm to convert to cipher text
                printf("%c", message[i]);
                

            }
            else
            {
                message[i] = (message[i] - 'a' + key) % ('Z' - 'A') + 'a';
                printf("%c", message[i]);
            }
        }
        else
        {
            printf("%c", message[i]);
        }

    }
    printf("\n");
    return 0;
}

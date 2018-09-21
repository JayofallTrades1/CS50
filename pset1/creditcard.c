#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
long long input;
do
{
    printf("Credit Card Number: ");
    input = GetLongLong();
    printf("%lld\n" , input);  
}
while(input < 10000000000);

}

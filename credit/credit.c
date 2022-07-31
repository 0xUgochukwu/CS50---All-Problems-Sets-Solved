#include <cs50.h>
#include <stdio.h>

int main(void)
{

    // Asking User for Card Number
    long cardNumber = get_long("Number: ");

    // declaring variables I will need
    int mod1;
    int mod2;
    int sum1;
    int sum2;

    // Getting Every other digit
    while(cardNumber)
    {
        mod1 = cardNumber % 10;
        cardNumber /= 10;

    }
}
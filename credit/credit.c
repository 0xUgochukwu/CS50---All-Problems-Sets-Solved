#include <cs50.h>
#include <stdio.h>

int main(void)
{

    // Asking User for Card Number
    long cardNumber = get_long("Number: ");

    // declaring variables I will need
    int mod1;
    int mod2;
    int sum1 = 0;
    int sum2 = 0;

    // Breaking the Card Number
    while(cardNumber)
    {
        // Getting the last digit and other digits
        mod1 = cardNumber % 10;
        cardNumber /= 10; // reducing the number
        sum1 = sum1 + mod1;

        // Getting every other digit in the card and
        mod2 = cardNumber % 10;
        cardNumber /= 10;
        sum2 = sum2 + (mod2 * 2);


    }
}
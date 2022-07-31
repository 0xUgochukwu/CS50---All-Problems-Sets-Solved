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
    int d1;
    int d2;
    int total;

    // Breaking the Card Number
    while(cardNumber)
    {
        // Getting the last digit and other digits
        mod1 = cardNumber % 10;
        cardNumber /= 10; // reducing the number
        sum1 = sum1 + mod1;

        // Getting every other digit in the card
        mod2 = cardNumber % 10;
        cardNumber /= 10;

        // Multiplying every other digit by two and adding each digit together
        mod2 = mod2 * 2;
        d1 = mod2 / 2;
        d2 = mod2 % 2;
        sum2 = sum2 + d1 + d2;
    }

    // Check Luhn Algorithm

    if ((total % 10) != 0)
    {
        printf("INVALID\n");
    } else {
        // Getting the first Digits

        long start = cardNumber;

        do
        {
            start /= 10;
        }
        while (start > 100);

        // Checking starting Digits for card type

        if ((start / 10 == 5) && ((0 > start % 10) && (start % 10 < 6)))
        {
            printf("MASTERCARD\n");
        } else if ((start / 10 == 3) && ((start % 10 == 4) || (start % 10 == 7)))
        {
            printf("AMEX\n");
        } else if (start / 10 == 4)
        {
            printf("VISA\n");
        } else
        {
            printf("INVALID\n");
        }
    }
}
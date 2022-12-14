#include <cs50.h>
#include <stdio.h>

int main(void)
{

    // Asking User for Card Number
    long cardNumber = get_long("Number: ");

    // declaring variables I will need
    int mod1;
    int mod2;
    long x = cardNumber;
    int sum1 = 0;
    int sum2 = 0;
    int d1;
    int d2;
    int total;

    // Breaking the Card Number
    do
    {
        // Getting the last digit and other digits
        mod1 = x % 10;
        x /= 10; // reducing the number
        sum1 += mod1;

        // Getting every other digit in the card
        mod2 = x % 10;
        x /= 10;

        // Multiplying every other digit by two and adding each digit together
        mod2 = mod2 * 2;
        d1 = mod2 % 10;
        d2 = mod2 / 10;
        sum2 += d1 + d2;
    }
    while(x > 0);

    // Totaling the two sums
    total = sum1 + sum2;

    // Check Luhn Algorithm

    // Count length
    int i = 0;
    long cc = cardNumber;
    while (cc > 0)
    {
        cc /= 10;
        i++;
    }

    // Check if length is valid
    if (i != 13 && i != 15 && i != 16)
    {
        printf("INVALID\n");
    } else {
            if ((total % 10) != 0)
            {
                printf("INVALID\n");
            }
            else
            {
                // Getting the first Digits

                long start = cardNumber;

                do
                {
                    start /= 10;
                }
                while (start > 100);

                // Checking starting Digits for card type

                if ((start / 10 == 5) && ((0 < start % 10) && (start % 10 < 6)))
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
}
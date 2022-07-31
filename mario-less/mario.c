#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Defining the input
    int n;

    // Getting an input and checking if it is between 1 and 8
    do
    {
        n = get_int("Input a Number (1 - 8): ");
    }
    while (!(n >= 1 && n <= 8));



    for (int i = 1; i <= n; i++)
    {
        // Printing a particular number of Spaces before th hash based on the current value of i(column)
        for (int y = n - 1; y >= i; y--)
        {
            printf(" ");
        }

        // Printing a particular number of Hashes based on the current value of i(column)

        for (int x = 1; x <= i; x++)
        {
            printf("#");
        }

        // Moving to the next line after each column
        printf("\n");
    }
}
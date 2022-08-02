#include <cs50.h>
#include <stdio.h>
#include <string.h>

int only_digits(string number);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        printf("%i\n", only_digits(argv[1]));
    }
}

int only_digits(string number)
{
    bool is_only_digits = true;
    int n = strlen(number);


    for (int i = 0; i < n; i++)
    {
        if (!(number[i] >= 0 && number[i] <= 9))
        {
            is_only_digits = false;
        }
    }

    return is_only_digits;
}
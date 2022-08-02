#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int only_digits(string number);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    } else if (!(only_digits(argv[1])))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    } else
    {
        int key = atoi(argv[1]);
        string plain_text = get_srting("plaintext:  ")
        return 0;
    }
}

int only_digits(string number)
{
    bool is_only_digits = true;
    int n = strlen(number);


    for (int i = 0; i < n; i++)
    {
        if (!(number[i] >= 48 && number[i] <= 57))
        {
            is_only_digits = false;
        }
    }

    return is_only_digits;
}
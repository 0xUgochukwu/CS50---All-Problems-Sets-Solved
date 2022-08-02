#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int only_digits(string number);
char rotate(char x, int k);

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
        string plain_text = get_string("plaintext:  ");
        string cipher_text = "";
        char ch;

        for (int i = 0, n = strlen(plain_text); i < n; i++)
        {
            ch = rotate(plain_text[i], key);
            strncat(cipher_text, &ch, 1);
        }

        printf("ciphertext:  %s\n", cipher_text);
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

char rotate(char x, int k)
{
    int overflow_key;

    if (x >= 65 && x <= 90)
    {
        x = x + k;

        // Checks if the Character Overflowed and adjusts the Overflow so we always print a Char b/w A - Z

        if (x > 90)
        {
            x = 64 + (x - 90); // Adding overflow to the begining of A - Z so it starts counting from a again
        }

        return (char) x;
    } else if (x >= 97 && x <= 122)
    {
        x = x + k;

        // Checks if the Character Overflowed and adjusts the Overflow so we always print a Char b/w a - z

        if (x > 122)
        {
            x = 96 + (x - 122); // Adding overflow to the begining of a - z so it starts counting from a again
        }

        return (char) x;
    }
    else
    {
        return x;
    }
}
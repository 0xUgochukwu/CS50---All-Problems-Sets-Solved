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
    }
    else if (!(only_digits(argv[1])))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        int key = atoi(argv[1]) % 26;
        string plain_text = get_string("plaintext:  ");
        string cipher_text = "";

        printf("ciphertext:  ");

        for (int i = 0, n = strlen(plain_text); i < n; i++)
        {
            printf("%c", rotate(plain_text[i], key));
        }
        printf("\n");
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
    int cipher_char;

    if (x >= 65 && x <= 90)
    {
        cipher_char = x + k;

        // Checks if the Character Overflowed and adjusts the Overflow so we always print a Char b/w A - Z

        if (cipher_char > 90)
        {
            cipher_char = 64 + (cipher_char - 90); // Adding overflow to the begining of A - Z so it starts counting from a again
        }

        return (char) cipher_char;
    }
    else if (x >= 97 && x <= 122)
    {
        cipher_char = x + k;

        // Checks if the Character Overflowed and adjusts the Overflow so we always print a Char b/w a - z

        if (cipher_char > 122)
        {
            cipher_char = 96 + (cipher_char - 122); // Adding overflow to the begining of a - z so it starts counting from a again
        }

        return (char) cipher_char;
    }
    else
    {
        return x;
    }
}
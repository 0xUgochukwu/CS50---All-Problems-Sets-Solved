#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


char rotate(char x, string key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (strlen(argv[1]) != 26)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else
    {
        string plain_text = get_string("plaintext:  ");
        string key = argv[1];

        printf("ciphertext:  ");

        for (int i = 0, n = strlen(plain_text); i < n; i++)
        {
            printf("%c", rotate(plain_text[i], key));
        }
        printf("\n");
    }


}



char rotate(char x, string key)
{
    // char cipher_char;
    // int index;

    if (x >= 65 && x <= 90)
    {
        // index = x - 'A';
        // cipher_char = toupper(key[index]);
        // return cipher_char;

        return toupper(key[x - 'A']);

    }
    else if (x >= 97 && x <= 122)
    {
        // index = x - 'a';
        // cipher_char = tolower(key[index]);
        // return cipher_char;

        return tolower(key[x - 'a']);
    }
    else
    {
        return x;
    }
}
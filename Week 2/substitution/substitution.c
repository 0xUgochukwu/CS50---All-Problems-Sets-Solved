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
        int key = argv[1];
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



char cipher(char x, int k)
{
    cipher_char (int) x
}
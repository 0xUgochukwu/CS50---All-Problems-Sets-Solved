#include <cs50.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);

int main(void)
{
    string text = get_string("Text: ");
    int n = count_letters(text);
    printf("%i \n", n);
}




int count_letters(string text)
{
    int letters = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if ((text[i] >= 97 && text[i] <= 122) || (text[i] >= 65 && text[i] <= 90))
        {
            letters ++;
        }
    }

    return letters;
}

int count_words(string text)
{
    
}
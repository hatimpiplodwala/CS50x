#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

bool only_digits(string key);

int main(int argc, string argv[])
{
    int key;

    if (argc == 2)
    {
        if (!(only_digits(argv[1])))
        {
            printf("Key should consist of digits only\n");
            return 1;
        }

        else
            key = atoi(argv[1]);
    }

    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string plaintext = get_string("plaintext:  ");

    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        if (isalpha(plaintext[i]))
        {
            if (isupper(plaintext[i]))
            {
                plaintext[i] = ((plaintext[i] - 'A') + key) % 26 + 'A';
            }

            else if (islower(plaintext[i]))
            {
                plaintext[i] = ((plaintext[i] - 'a') + key) % 26 + 'a';
            }
        }
    }

    printf("ciphertext: %s\n", plaintext);
}

bool only_digits(string key)
{
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        if (!(isdigit(key[i])))
        {
            return false;
        }
    }

    return true;
}
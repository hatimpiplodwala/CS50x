#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    string key;
    if (argc == 2)
    {
        if (strlen(argv[1]) != 26)
        {
            printf("Key must contain 26 characters\n");
            return 1;
        }
        else
            key = argv[1];
    }

    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    for(int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!(isalpha(key[i])))
        {
            printf("All key must be alphabetical\n");
            return 1;
        }

        for (int j = i + 1; j < n; j++)
        {
            if (tolower(key[i]) == tolower(key[j]))
            {
                printf("All key must be unique\n");
                return 1;
            }
        }
    }

    string plaintext = get_string("plaintext:  ");

    for (int i = 0, n = strlen(plaintext), index; i < n; i++)
    {
        index = -1;

        if (isalpha(plaintext[i]))
        {
            index = toupper(plaintext[i]) - 'A';
        }

        if (index > -1)
        {
            if (islower(plaintext[i]))
            {
                plaintext[i] = tolower(key[index]);
            }

            else if (isupper(plaintext[i]))
            {
                plaintext[i] = toupper(key[index]);
            }
        }
    }

    printf("ciphertext: %s\n", plaintext);
}
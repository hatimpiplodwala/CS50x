#include <cs50.h>
#include <stdio.h>

bool checksum(int array[], int length);

int main(void)
{
    long cardnumber = get_long("Number: ");

    int length = 0;
    int cardarray[16];

    for (int i = 0, remainder; cardnumber != 0; i++)
    {
        remainder = cardnumber % 10;
        cardarray[i] = remainder;
        cardnumber /= 10;
        length++;
    }

    bool sum = checksum(cardarray, length);

    if (sum)
    {
        if (cardarray[length-1] == 4)
        {
            if (length == 13 || length == 16)
            {
                printf("VISA\n");
                return 0;
            }
        }

        else if (cardarray[length-1] == 3 && (cardarray[length-2] == 4 || cardarray[length-2] == 7))
        {
            if (length == 15)
            {
                printf("AMEX\n");
                return 0;
            }
        }

        else if (cardarray[length-1] == 5 && (cardarray[length-2] == 1 || cardarray[length-2] == 2 ||
                    cardarray[length-2] == 3 || cardarray[length-2] == 4 || cardarray[length-2] == 5))
        {
            if (length == 16)
            {
                printf("MASTERCARD\n");
                return 0;
            }
        }
    }

    printf("INVALID\n");
    return 0;
}

bool checksum(int array[], int length)
{
    int sum = 0;
    int element = 0;

    for (int i = 1; i < length; i+=2)
    {
        element = array[i] * 2;
        while (element != 0)
        {
            sum += (element % 10);
            element /= 10;
        }
    }

    for (int i = 0; i < length; i+=2)
    {
        sum+=array[i];
    }

    if ((sum % 10) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
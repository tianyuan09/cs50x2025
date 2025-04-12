#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long number;
    int digit = 0, pointer = 0, sum = 0, id = 0, first = 0, second = 0;
    do
    {
        number = get_long("Number:");
    }
    while (number < 1000);
    // Get first two digits from the original number
    long first_two = number;
    while (number > 0)
    {
        digit = number % 10;
        // printf("digit: %d; id = %d \n", digit, id);
        if (id % 2 == 0)
        {
            sum = sum + digit;
            // printf("sum: %d\n", sum);
        }
        else
        {
            if (digit * 2 > 9)
            {
                sum = sum + (digit * 2) % 10 + (digit * 2) / 10;
                // printf(" here sum: %d\n", sum);
            }
            else
            {
                sum = sum + digit * 2;
                // printf("sum: %d\n", sum);
            }
        }
        number = number / 10;
        id = id + 1;
    }
    while (first_two >= 100)
    {
        first_two /= 10;
    }
    first = first_two / 10;
    second = first_two % 10;

    string cardtype = "INVALID";
    if (sum % 10 == 0)
    {
        if (id == 15 && first == 3 && (second == 4 || second == 7))
        {
            cardtype = "AMEX";
        }
        else if ((id == 13 || id == 16) && first == 4)
        {
            cardtype = "VISA";
        }
        else if (id == 16 && first == 5 && second >= 1 && second <= 5)
        {
            cardtype = "MASTERCARD";
        }
    }
    printf("%s\n", cardtype);
}

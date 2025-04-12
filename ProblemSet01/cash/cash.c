#include <cs50.h>
#include <stdio.h>

int quarters(int cents);
int dimes(int cents);
int nickels(int cents);

int main(void)
{
    // Prompt the user for change owed, in cents

    // Calculate how many quarters you should give customer
    // Subtract the value of those quarters from cents
    // Print that sum
    int change;
    int coins = 0, q = 0, d = 0, n = 0, p = 0;
    do
    {
        change = get_int("Change owed:");
    }
    while (change < 0);
    q = quarters(change);
    change = change - q * 25;
    d = dimes(change);
    change = change - d * 10;
    n = nickels(change);
    change = change - n * 5;
    printf("%d\n", (q + d + n + change));
}

int quarters(int cents)
{
    return cents / 25;
}

int dimes(int cents)
{
    return cents / 10;
}
int nickels(int cents)
{
    return cents / 5;
}

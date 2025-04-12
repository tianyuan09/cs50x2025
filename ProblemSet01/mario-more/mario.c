#include <cs50.h>
#include <stdio.h>

void print_row(int space, int bricks);

int main(void)
{
    // user input for height
    int n;
    do
    {
        n = get_int("Height:");
    }
    while (n < 1);

    // print a pyramid of that height
    for (int i = 0; i < n; i++)
    {
        print_row(n - i - 1, i + 1);
    }
}
//print the spaces and bricks
void print_row(int spaces, int bricks)
{
    for (int j = 0; j < spaces; j++)
    {
        printf(" ");
    }
    for (int i = 0; i < bricks; i++)
    {
        printf("#");
    }
    printf("  "); //add padding
    for (int i = 0; i < bricks; i++)
    {
        printf("#");
    }
    printf("\n");
}

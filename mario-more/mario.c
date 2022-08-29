#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Height: "); // ask for input (the height)
    }
    while (n < 1 || n > 8); //only allows numbers between 1-8

    for (int i = 0; i < n; i++) //controls amount of rows
    {
        for (int spaces = n - 1; spaces > i; spaces--)
        {
            printf(" ");
        }
        for (int c1 = 0; c1 <= i; c1++)
        {
            printf("#");
        }
        printf("  ");
        for (int c2 = 0; c2 <= i; c2++)
        {
            printf("#");
        }
        printf("\n");
    }
}
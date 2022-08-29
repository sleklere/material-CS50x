#include <cs50.h>
#include <stdio.h>

int grab_digit(int d);

int main(void)
{
    long n = get_long("Enter credit card number: "); // credit card number
    int num;
    int sum1 = 0;
    for (long d = 100; d < (10e17); d = d * 100)     // grab digits
    {
        long extra_decimals = d / 10;
        num = ((n % d) / extra_decimals) * 2;
        int num_d = num / 10;
        int num_d_2 = num % 10;
        sum1 += num_d + num_d_2;
    }
    int sum2 = 0;
    for (long d = 10; d < (10e17); d = d * 100)     // grab digits that dont multiply
    {
        long extra_decimals = d / 10;
        num = (n % d) / extra_decimals;
        sum2 += num;
    }
    int check_sum = sum1 + sum2;
    if ((check_sum % 10) == 0) // if condition is True (meaning the last digit of the total sum is 0) --> valid
    {
        long x = 10e15; // grab first digit for 16-digit visas
        long x2 = 10e12; // same for ones with 13 digits
        long x3 = 10e16;
        long z = (n % x) / 10000000000000; // AMEX check
        long z2 = (n % x3) / 100000000000000; // Mastercard check
        if (((n % x) / (x / 10)) == 4 || ((n % x2) / (x2 / 10)) == 4)
        {
            printf("VISA");
        }
        else if (z == 37 || z == 34)
        {
            printf("AMEX");
        }
        else if (z2 == 51 || z2 == 52 || z2 == 53 || z2 == 54 || z2 == 55)
        {
            printf("MASTERCARD");
        }
        else
        {
            printf("INVALID");
        }
    }
    else
    {
        printf("INVALID");
    }
    printf("\n");
}
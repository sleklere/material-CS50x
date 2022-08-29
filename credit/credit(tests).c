#include <cs50.h>
#include <stdio.h>

int grab_digit(int d);

int main(void)
{
    long n = get_long("Enter credit card number: "); // credit card number
    int num;
    int sum1 = 0;
    for (long d = 100; d < (10e17); d = d*100)     // grab digits
    {
        long extra_decimals = d / 10;
        num = ((n % d) / extra_decimals) * 2;
        int num_d = num / 10;
        int num_d_2 = num % 10;
        // printf("%i", num);
        // printf("\n");
        sum1 += num_d + num_d_2;
    }
    // printf("\n");
    // printf("Sum1: %i", sum1);
    // printf("\n");
    int sum2 = 0;
    for (long d = 10; d < (10e17); d = d*100)     // grab digits that dont multiply
    {                                             // check if valid (check sum. multiply every other digit by 2, starting with the 2nd to last. --> add products --> add that to the
        long extra_decimals = d / 10;             // sum of the digits that werent *)
        num = (n % d) / extra_decimals;
        // printf("%i", num);
        // printf("\n");
        sum2 += num;
    }
    // printf("Sum2: %i", sum2);
    // printf("\n");
    int check_sum = sum1 + sum2;
    printf("Check Sum = %i", check_sum);
    printf("\n");
    if ((check_sum % 10) == 0) // if condition is True (meaning the last digit of the total sum is 0) --> valid
    {
        printf("VALID!");
    }
    long x = 10e15; // grab first digit for 16-digit visas
    long x2 = 10e12; // same for ones with 13 digits
    long z = (n % x) / 10000000000000;
    if (((n % x) / (x / 10)) == 4 || ((n % x2) / (x2 / 10)) == 4)
    {
        printf("VISA");
    }
    else if (z == 37 || z == 34)
    {
        printf("AMEX");
    }
    else
    {
        printf("INVALID!");
    }
    printf("\n");
}
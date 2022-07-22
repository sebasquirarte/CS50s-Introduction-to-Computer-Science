// Determines if a credit card number is valid and if Visa, Mastercard, or American Express

// Checksum Steps:
// 1. Multiply every other digit by 2, starting with the number’s second-to-last digit. Add those products’ digits together.
// 2. Add the sum to the sum of the digits that weren’t multiplied by 2.
// If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!
// Conditions:
// American Express uses 15-digit numbers and starts with 34 or 37.
// MasterCard uses 16-digit numbers and start with 51, 52, 53, 54, or 55.
// Visa uses 13- and 16-digit numbers and starts with 4.

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long cc_number = get_long("Number: ");

    // Checksum

    int sum1 = 0;
    int sum2 = 0;

    // First step
    long number_mod = cc_number / 10;
    while (number_mod > 0)
    {
        int second_last = number_mod % 10;
        int times_two = second_last * 2;
        sum1 = sum1 + (times_two % 10) + (times_two / 10);
        number_mod = number_mod / 100;
    }

    number_mod = cc_number;

    // Second step
    while (number_mod > 0)
    {
        int last = number_mod % 10;
        sum2 = sum2 + last;
        number_mod = number_mod / 100;
    }

    int sum_total = sum1 + sum2;

    // Conditions

    // Length
    int length = 0;
    long number_length = cc_number;

    while (number_length > 0)
    {
        number_length = number_length / 10;
        length = length + 1;
    }

    // Starting numbers
    int i = length - 2;
    int j = 1;
    long div = 10;

    while (j < i)
    {
        div = div * 10;
        j ++;
    }

    long first_digits = cc_number / div;
    int first_digit = first_digits / 10;

    // Verification

    if (sum_total % 10 == 0)
    {
        // American Express
        if (length == 15 && (first_digits == 34 || first_digits == 37))
        {
            printf("AMEX\n");
        }
        // Mastercard
        else if (length == 16 && first_digits >= 51 && first_digits <= 55)
        {
            printf("MASTERCARD\n");
        }
        // Visa
        else if ((length == 13 || length == 16) && first_digit == 4)
        {
            printf("VISA\n");
        }
        // Invalid
        else
        {
            printf("INVALID\n");

        }
    }
    else
    {
        printf("INVALID\n");
    }
}
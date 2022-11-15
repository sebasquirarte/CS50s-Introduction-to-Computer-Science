// Creates text graphic of a simple half pyramid with variable height
// Part of 'CS50s Introduction to Computer Science' through HarvardX
// Sebastian Quirarte | sebastianquirajus@gmail.com

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompts user for height
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // Rows
    for (int row = 1; row <= height; row++)
    {
        // Spaces
        for (int j = 1; j <= (height - row); j++)
        {
            printf(" ");
        }
        // #'s
        for (int k = 1; k <= row; k++)
        {
            printf("#");
        }

        printf("\n");
    }
}

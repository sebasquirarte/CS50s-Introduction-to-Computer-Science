// Cesar Cypher - Creates cyphertext by moving letter a variable number of places
// Part of 'CS50s Introduction to Computer Science' through HarvardX
// Sebastian Quirarte | sebastianquirajus@gmail.com | 24 Jul 2022

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

bool only_digits(string key);
char rotate(char x, int y);

int main(int argc, string argv[])
{
    // Checks if just one command line argument and only digits
    if (argc == 2 && only_digits(argv[1]))
    {
        // Converts key to int
        int key = atoi(argv[1]);
        string plain_text = get_string("plaintext: ");

        printf("%s", "ciphertext: ");

        for (int i = 0; i < strlen(plain_text); i++)
        {
            char letter_cypher = rotate(plain_text[i], key);
            printf("%c", letter_cypher);
        }
        printf("\n");
    }
    // Prints if more than one command line argument or not only digits
    else
    {
        printf("%s\n", "Usage: ./caesar key");
        return 1;
    }
}

// Checks if command line argument is made up of only digits
bool only_digits(string s)
{
    bool validity = false;

    for (int i = 0; i < strlen(s); i++)
    {
        if (isdigit(s[i]))
        {
            validity = true;
        }
        else
        {
            validity = false;
        }
    }
    return validity;
}

// Shifts letter by cipher key
char rotate(char x, int y)
{
    if (isalpha(x))
    {
        if (islower(x))
        {
            x = x - 97;
            x = (x + y) % 26;
            x = x + 97;
        }
        else
        {
            x = x - 65;
            x = (x + y) % 26;
            x = x + 65;
        }
    }
    else
    {
        return x;
    }
    return x;
}

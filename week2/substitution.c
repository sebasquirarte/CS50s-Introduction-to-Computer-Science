// Substitute Cypher - Creates cyphertext by replacing letters with corresponding character within key
// Part of 'CS50s Introduction to Computer Science' through HarvardX
// Sebastian Quirarte | sebastianquirajus@gmail.com | 24 Jul 2022

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // Verify only one command line argument and length of key
    if (argc == 2 && strlen(argv[1]) == 26)
    {
        // Verify no duplicates in key
        bool valid = false;
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            for (int j = i + 1; j < strlen(argv[1]) + 1; j++)
            {
                if (isalpha(argv[1][i]) && tolower(argv[1][i]) != tolower(argv[1][j]))
                {
                    valid = true;
                }
                else
                {
                    printf("Usage ./substitution key\n");
                    return 1;
                }

            }
        }

        // Prompt user for plaintext
        string plain_text = get_string("%s", "plaintext:");

        // Cipher letter
        for (int i = 0; i < strlen(plain_text); i++)
        {
            if (islower(plain_text[i]))
            {
                plain_text[i] = tolower(argv[1][plain_text[i] - 97]);
            }
            else if (isupper(plain_text[i]))
            {
                plain_text[i] = toupper(argv[1][plain_text[i] - 65]);
            }
        }

        // Output ciphertext
        printf("ciphertext: %s\n", plain_text);
        return 0;
    }
    else if (argc == 2 && strlen(argv[1]) != 26)
    {
        printf("%s\n", "Key must contain 26 characters.");
        return 1;
    }
    else
    {
        printf("Usage ./substitution key\n");
        return 1;
    }

}

// Readability - Determines grade level of given text
// Part of 'CS50s Introduction to Computer Science' through HarvardX
// Sebastian Quirarte | sebastianquirajus@gmail.com | 22 Jul 22

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string s);
int count_sentences(string s);

int main(void)
{
    // Prompts user for text
    string text = get_string("%s", "Text: ");

    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    float avg_letters = (float) letters / (float) words * 100;
    float avg_sentences = (float) sentences / (float) words * 100;

    // Determines grade level
    float index = 0.0588 * avg_letters - 0.296 * avg_sentences - 15.8;
    int grade = round(index);

    // Outputs grade level
    if (grade > 1 && grade < 16)
    {
        printf("Grade %i\n", grade);
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Before Grade 1\n");
    }
}

// Counts letters in text
int count_letters(string s)
{
    int counter = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        if (isalpha(s[i]))
        {
            counter += 1;
        }
        else
        {
            counter += 0;
        }

    }
    return counter;
}

// Counts words in text
int count_words(string s)
{
    int counter = 1;
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == ' ')
        {
            counter += 1;
        }
        else
        {
            counter += 0;
        }

    }
    return counter;
}

// Counts sentences in text
int count_sentences(string s)
{
    int counter = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == '.')
        {
            counter += 1;
        }
        else if (s[i] == '?')
        {
            counter += 1;
        }
        else if (s[i] == '!')
        {
            counter += 1;
        }
        else
        {
            counter += 0;
        }

    }
    return counter;
}

//Greets user with an input name
// Part of 'CS50s Introduction to Computer Science' through HarvardX
// Sebastian Quirarte | sebastianquirajus@gmail.com

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Asks user for name
    string name = get_string("Name: ");
    //Prints greeting
    printf("hello, %s\n", name);
}

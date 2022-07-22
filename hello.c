//Greets user with an input name

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Asks user for name
    string name = get_string("Name: ");
    //Prints greeting
    printf("hello, %s\n", name);
}
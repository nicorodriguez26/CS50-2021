// Nicolas Rodriguez Aldegheri
// CS50 pset 1: Hello | 2021
// July 07, 2021. 

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string name = get_string("What's your name?\n");
    printf("Hello %s!\n", name);
}

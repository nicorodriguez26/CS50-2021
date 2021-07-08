// CS50 2021 - Introduction to Computer Science
// Week 1 - Laboratory 1 - Language: C
// Hello - hello.c
// Nicolas Rodriguez Aldegheri
// 07/07/21

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string name = get_string("What's your name?\n");
    printf("Hello %s!\n", name);
}

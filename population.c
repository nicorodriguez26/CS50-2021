// CS50 2021 - Introduction to Computer Science.
// Week 1 - Laboratory 1 - Language: C
// Population Growth - populaton.c
// Nicolas Rodriguez Aldegheri
// 07/07/21

#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // TODO: Prompt for start size
    int strt_pop;
    do
    {
        strt_pop = get_int("Start size: ");
    }
    while (strt_pop < 9);

    // TODO: Prompt for end size
    int end_pop;
    do
    {
        end_pop = get_int("End size: ");
    }
    while (end_pop < strt_pop);

    // TODO: Calculate number of years until we reach threshold
    int years = 0;
    int n = strt_pop;

    if (strt_pop == end_pop)
    {
        printf("Years: 0\n");
    }
    else
    {
        do
        {
            n = round(n + (n / 3) - (n / 4));
            years++;
        }
        while (end_pop > n);
        printf("Years: %i\n", years);
    }
    // x = x + (x/3) - (x/4)
    // TODO: Print number of years
}

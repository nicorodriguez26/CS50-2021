// Nicolas Rodriguez Aldegheri
// CS50 lab 1: Population Growth | 2021
// July 07, 2021. 

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
      
        // TODO: Print number of years
        printf("Years: %i\n", years);
    }
}

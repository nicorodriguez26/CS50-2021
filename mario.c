// CS50 2021 - Introduction to Computer Science
// Week 1 - Problem Set 1 - Language: C
// Mario More Confortable - mario.c
// Nicolas Rodriguez Aldegheri
// 08/07/21

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Get a Valid User Input
    int UV;
    printf("Select a number between 1 and 8 for the pyramid height\n");
    do
    {
        UV = get_int("Height: ");
    }
    while (UV < 1 || UV > 8);
    //Rows
    for (int R = 1; R <= UV; R++)
    {
        //Columns spaces
        for (int CS = UV - R; CS > 0; CS--)
        {
            printf(" ");
        }
        //Columns hashes
        for (int CH = 1; CH <= R; CH++)
        {
            printf("#");
        }
        //Space between pyramid
        printf("  ");
        //Columns hashes after space between pyramid
        for (int CH = 1; CH <= R; CH++)
        {
            printf("#");
        }
        printf("\n");
    }
}

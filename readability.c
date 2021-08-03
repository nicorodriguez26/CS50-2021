// CS50 2021 - Introduction to Computer Science.
// Week 2 - Problem Set 2 - Language: C
// Readability - readability.c
// Nicolas Rodriguez Aldegheri
// 03/08/21

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main(void)
{
    string text = get_string("Text: ");
    int lttrs = 0;
    int wrds = 1;
    int sntncs = 0;

    //count letters, words and sentences.
    for (int i = 0; i < strlen(text); i++)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            lttrs++;
        }
        else if (text[i] == ' ')
        {
            wrds++;
        }
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sntncs++;
        }

    }
    //printf("Letters: %i.\nWords: %i.\nSentences: %i.\n", lttrs, wrds, sntncs);

    //Take the numbers and insert them into the formula
    float grade = 0.0588 * (100 * (float)lttrs / (float)wrds) - 0.296 * (100 * (float)sntncs / (float)wrds) - 15.8;
    if (grade <= 16 && grade >= 0)
    {
        printf("Grade %i\n", (int) round(grade));
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Before Grade 1\n");
    }
}

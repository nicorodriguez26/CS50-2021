// CS50 2021 - Introduction to Computer Science.
// Week 2 - Laboratory 2 - Language: C
// Scrabble - scrabble.c
// Nicolas Rodriguez Aldegheri
// 03/08/21

#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// ASCII table: http://www.columbia.edu/kermit/ascii.html

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    printf("\n");
    printf("Player 1: %i points\n", score1);
    printf("Player 2: %i points\n", score2);

    // Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    // Compute and return score for string
    int score = 0;
    //  Reference to a temporary count of points
    int count;
    // It is used to mark the result of the subtraction of the
    // letter as the location of the index of the POINTS string
    int position;

    // Here the function iterates depending the lenght of the string
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        // Check the letter and establish a position,
        // subtracting the character with 65 which is
        // the position of the letters in the ASCII table
        // of the uppercase letters.
        if (isupper(word[i]))
        {
            position = word[i] - 65;
            count = POINTS[position];
        }
        // Check the letter and establish a position,
        // subtracting the character with 97 which is
        // the position of the letters in the ASCII table
        // of the lowercase letters.
        else if (islower(word[i]))
        {
            position = word[i] - 97;
            count = POINTS[position];
        }
        else
        {
            count = 0;
        }
        score += count;
    }
    return score;
}

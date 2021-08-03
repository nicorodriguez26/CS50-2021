// CS50 2021 - Introduction to Computer Science.
// Week 2 - Problem Set 2 - Language: C
// Sbstitution - substitution.c
// Nicolas Rodriguez Aldegheri
// 03/08/21

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

bool validate(string key);

int main(int argc, string argv[])
{
    //Check if the argument is equal to 2
    if (argc == 2)
    {
        //Define the "key" that is equal to the second argument
        //Then will check if the key, through the boolean is valid
        string key = argv[1];
        if (validate(key) == true)
        {
            //At this point, if the previous steps are ready 2go, will define the
            //rest of the data to work with
            string txt = get_string("plaintext: ");
            int charcount = strlen(txt);
            char cipher[charcount];
            string abc = "abcdefghijklmnopqrstuvwxyz";
            //Now a "for loop" to start ciphering the text
            for (int i = 0; i < charcount; i++)
            {
                //Null Terminating character
                if (txt[i] == '\0')
                {
                    break;
                }
                //Checking if the plaintext words are uppercase
                if (isupper(txt[i]) != 0)
                {
                    //Stablishing a value from 0 to 26 (key max character)
                    for (int j = 0; j < 26; j++)
                    {
                        if (abc[j] == tolower(txt[i]))
                        {
                            cipher[i] = toupper(key[j]);
                            break;
                        }
                    }
                }
                //Checking if the plaintext words are uppercase
                else if (islower(txt[i]) != 0)
                {
                    for (int j = 0; j < 26; j++)
                    {
                        if (abc[j] == txt[i])
                        {
                            cipher[i] = tolower(key[j]);
                            break;
                        }
                    }
                }
                else
                {
                    cipher[i] = txt[i];
                }
            }
            //Null Terminating character
            cipher[charcount] = '\0';
            printf("ciphertext: %s\n", cipher);
            return 0;
        }
        else
        {
            printf("Please make sure your key is a permutation of all 26 characters - not more, not less.\n");
            return 1;
        }
    }
    else
    {
        printf("Input error. Please provide a single key.\n");
        return 1;
    }
}

bool validate(string key)
{
    int match = 0;
    if (strlen(key) == 26)
    {
        for (char c = 'a'; c <= 'z'; c++)
        {
            for (int i = 0; i < 26; i++)
            {
                if (tolower(key[i]) == c)
                {
                    match++;
                    break;
                }
            }
        }
        if (match == 26)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

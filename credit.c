// CS50 2021 - Introduction to Computer Science.
// Week 1 - Problem Set 1 - Language: C
// Credit - credit.c
// Nicolas Rodriguez Aldegheri
// 09/07/21

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Description of what to do at the beginning.
    long cdn;
    int num1 = 0, num2 = 0, numDigits = 0, sumDOdds = 0, sumEvens = 0;
    printf("Write your credit card number below\n");

    //Prompt the credit card number.
    do
    {
        cdn = get_long("Credit card number: \n");
    }
    while (cdn < 0);

    //Calculate the checksum of the input.

    /*Well at this point the variable num2 is equal to the variable num1
    so that it always maintains a previous value of num1 and num1 is equal
    to cdn% 10, to give it the value of the last number of the corresponding
    cdn. Then we pass to the conditional that if the result of the sumDigits%2
    value equals 0, it will add sumEvens to the last corresponding num1.
    If the conditional sumDigits result is non-zero num1 is multiplied by 2
    and creates the multiple variable, in the next step sumDOdds is equal
    to the sum of sumDOdds and multiple / 10 plus multiple% 10. Finally cdn%10
    to delete one number at a time in the previous cdn and sumDigits ++ to
    alternate between odd and even numbers.*/

    while (cdn > 0)
    {
        num2 = num1;
        num1 = cdn % 10;
        if (numDigits % 2 == 0)
        {
            sumEvens += num1;
        }
        else
        {
            int multiple = 2 * num1;
            sumDOdds += (multiple / 10) + (multiple % 10);
        }
        cdn /= 10;
        numDigits++;
    }
    //Print according tod the result of the three previous steps.
    bool valid = (sumDOdds + sumEvens) % 10 == 0;
    int idn = (num1 * 10) + num2;
    //If the the card is VISA.
    if (num1 == 4 && numDigits >= 13 && numDigits <= 16 && valid)
    {
        printf("VISA\n");
    }
    //If the card is MASTERCARD.
    else if (idn >= 51 && idn <= 55 && numDigits == 16 && valid)
    {
        printf("MASTERCARD\n");
    }
    //If the card is AMEX.
    else if ((idn == 34 || idn == 37) && numDigits == 15 && valid)
    {
        printf("AMEX\n");
    }
    //Or if the card isn't valid.
    else
    {
        printf("INVALID\n");
    }
}

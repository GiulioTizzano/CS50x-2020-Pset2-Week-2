#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int main(void)
{
    int lettercount = 0;
    int wordscount = 1;
    int sentencecount = 0;

    // prompt user for the text
    string input = get_string("Text: ");
    int n = strlen(input);

    //set conditions for the letters, words and sentences
    for (int chara = 0; chara  < n; chara++)
    {
        if ((input[chara] >= 'a' && input[chara] <= 'z') || (input[chara] >= 'A' && input[chara] <= 'Z'))
        {
            lettercount++;
        }
        else if (input[chara] == ' ')
        {
            wordscount++;
        }
        else if (input[chara] == '!' || input[chara] == '?' || input[chara] == '.')
        {
            sentencecount++;
        }
    }



    printf("%i,%i,%i\n", lettercount, wordscount, sentencecount);

    //calculation with the Coleman-Liau index formula
    //defining L and S in a mathematical fractional ratio
    float L = (float) lettercount * 100 / (float) wordscount;
    float S = (float) sentencecount * 100 / (float) wordscount;

    float x = 0.0588 * L - 0.296 * S - 15.8;
    x = round(x);

    //determining the grade itself

    if (x < 16 && x >= 0)
    {
        printf("Grade %i\n", (int) x);
    }
    else if (x < 0)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade 16+\n");
    }
}

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    //declaring variables
    string key = argv[1];


    if (argc == 2)
    {
        for (int i = 0, n = strlen(key); i < n; i++)
        {
            if (isalpha(key[i]))
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
        if (key >= 0)
        {
            //convert first array value into an integer with atoi function, where k is the integer
            int k = atoi(key);
            string plaintext = get_string("plaintext: ");
            printf("ciphertext: ");

            for (int i = 0, y = strlen(plaintext); i < y; i++)
            {
                //getting the ciphertext for uppercase letters with the given formula Ci = (Pi + k) % 26
                if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
                {
                    printf("%c", ((((plaintext[i] + k) - 65) % 26) + 65));
                }
                //getting the ciphertext for lowercase letters with the given formula
                else if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
                {
                    printf("%c", ((((plaintext[i] + k) - 97) % 26) + 97));
                }
                else
                {
                    printf("%c", plaintext[i]);
                }



            }
            printf("\n");
            return 0;

        }
        else
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }





    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

}
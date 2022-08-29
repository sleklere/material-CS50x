#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

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

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("\nPlayer 1 wins!");
        printf("\n");
    }
    else if (score1 == score2)
    {
        printf("Tie!");
        printf("\n");
    }
    else
    {
        printf("\nPlayer 2 wins!");
        printf("\n");
    }
}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    int acumulator = 0;
    for (int i = 0, wordLength = strlen(word); i < wordLength; i++)
    {
        char letterU = toupper(word[i]); // get char and convert it to uppercase
        //printf("%c", letterU);
        //get ASCII value for given char
        int letterInASCII = (int) letterU;
        // check if ASCII value of char is between uppercase letters (65...90)
        int charPoints;
        if (letterInASCII >= 65 && letterInASCII <= 90)
        {
            charPoints = POINTS[letterInASCII - 65];
        }
        else
        {
            charPoints = 0;
        }
        //printf("\n%i\n", letterInASCII);
        // printf("\nletter points: \n%i\n", charPoints);
        acumulator += charPoints;
    }
    // printf("\nacumulator: %i\n", acumulator);
    return acumulator;
}
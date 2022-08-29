#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
// SPECIFICATION

// Your program must prompt the user for a string of text (using get_string).
int main (void)
{
  string text = get_string("Text: ");
  printf(("%s\n"), text);
}
//Your program should count the number of letters, words, and sentences in the text.
//You may assume that a letter is any lowercase character from a to z or any uppercase character
//from A to Z, any sequence of characters separated by spaces should count as a word, and that
//any occurrence of a period, exclamation point, or question mark indicates the end of a sentence.

// counting letters
int acumulator = 0;
int letterAcum = 0;
for (int i = 0, textLength = strlen(text); i < textLength; i++)
{
  char charUpper = toupper(word[i]); // get char and convert it to uppercase
    //printf("%c", letterU);
  //get ASCII value for given char
  int charInASCII = (int) charUpper;
  printf("%i", charInASCII);
  // check if ASCII value of char is between uppercase letters (65...90)
  int charPoints;
  // checking if its a letter or a !? etc
  if (charInASCII >= 65 && charInASCII <= 90)
  {
      letterAcum++;
  }
  // else if () 
  // }
  else
  {
      charPoints = 0;
  }
  //printf("\n%i\n", letterInASCII);
  // printf("\nletter points: \n%i\n", charPoints);
  acumulator += charPoints;
}


// counting words

// counting sentences





//Your program should print as output "Grade X" where X is the grade level computed by the
//Coleman-Liau formula, rounded to the nearest integer.

//If the resulting index number is 16 or higher (equivalent to or greater than a senior
//undergraduate reading level), your program should output "Grade 16+" instead of giving
//the exact index number. If the index number is less than 1, your program should output
//"Before Grade 1".

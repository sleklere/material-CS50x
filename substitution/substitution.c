#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc == 1) //si no se inserta la key
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string key = argv[1];
    bool keyIsLetter = 1; // 2do condicional para que corra o no el loop

    for (int i = 0; i < strlen(key) && keyIsLetter == 1; i++)
    {
        // check si el caracter es una letra (deberia terminar en 1 dsps de todas las iteraciones)
        keyIsLetter = isalpha(key[i]);
    }
    // si se inserto la key, chequear que este bien
    if (argc == 2)
    {
        if (strlen(key) != 26) //chequear el largo
        {
            printf("\nKey must contain 26 characters\n");
            return 1;
        }
        else if (keyIsLetter == 0) //chequear que todos los caracteres sean letras
        {
            printf("\nKey must contain alphabetic characters\n");
            return 1;
        }

        for (int i = 0; i < strlen(key); i++) //por cada letra de la key *
        {
            char letter = key[i];
            for (int j = i + 1; j < strlen(key); j++) // *iterar de nuevo la key chequeando que la letra del loop 'padre' no sea igual a ninguna otra en la key
            {
                if (letter == key[j])
                {
                    printf("Key must not contain repeated characters\n");
                    return 1;
                }
            }
        }
    }
    else // chequear que solo hayan 2 inputs (./substitution y la key)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    printf("plaintext:");
    printf("\n");
    string text = get_string("");

    printf("ciphertext: ");

    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]) == 0) //si el caracter actual del texto no es una letra, que se deje tal como esta
        {
            printf("%c", text[i]);
        }
        else // si es letra, evaluar si es upper o no
        {
            if (islower(text[i]))
            {
                int index = ((int) text[i]) - 97;
                printf("%c", tolower(key[index]));
            }
            else
            {
                int index = ((int) text[i]) - 65;
                printf("%c", toupper(key[index]));
            }
        }
    }

    printf("\n");
    return 0;
}
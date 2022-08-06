#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int embaralhar(char entrada, int semente);

int main(int argc, string argv[])
{
    // verifica se sao dois argumentos
    if (argc != 2)
    {
        printf("Usage: ./ceasar key\n");
        exit(1);
    }

    // verifica se o argumento não é diferente de um digito
    for(int i = 0, n = strlen(argv[1]); i < n; i++)
    {
         if(argv[1][i] < '1' || argv[1][i] > '9' || argv[1][i] == ' ')
         {
             printf("Usage: ./caesar key\n");
             exit(1);
         }
    }

    // recebe o texto a ser criptografado
    string texto = get_string("plaintext: ");

    // encripta e printa cada caractere
    printf("ciphertext: ");
    for(int i = 0, n = strlen(texto); i < n; i++)
    {
        int caractereCriptografado = embaralhar(texto[i], atoi(argv[1]));
        printf("%c", (char) caractereCriptografado);
    }
    printf("\n");
}

int embaralhar(char entrada, int semente){
    // printf("input: %c\n", entrada);
    // printf("sed: %i\n", semente);
    // printf("charint: %i\n", caractere);
    // printf("index: %i\n", (int) entrada - 65);
    if(isalpha((char) entrada))
    {
        if (isupper(entrada))
        {
            int indiceAlfabetico = (int) entrada - 65;
            int indiceCipher = (indiceAlfabetico + semente) % 26;
            int caractereAscii = indiceCipher + 65;
            //printf("index: %c\n", (char) caractereAscii);
            return caractereAscii;
        }
        else
        {
            int indiceAlfabetico = (int) entrada - 97;
            int indiceCipher = (indiceAlfabetico + semente) % 26;
            int caractereAscii = indiceCipher + 97;
            //printf("index: %c\n", (char) caractereAscii);
            return caractereAscii;
        }
    }
    else
    {
        return (int) entrada;
    }
}

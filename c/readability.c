#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void){

    //string texto = "One fish. Two fish. Red fish. Blue fish.";
    //string texto = "Congratulations! Today is your day. You're off to Great Places! You're off and away!";

    string texto = get_string("Text: ");

    int palavras = 1;
    int frases = 0;
    int letras = 0;

    for(int controle = 0, limite = strlen(texto); controle < limite; controle++)
    {
        if((texto[controle] >= 'a' && texto[controle] <= 'z') || (texto[controle] >= 'A' && texto[controle] <= 'Z'))
        {
            letras++;
        }
        if(texto[controle] == ' ')
        {
            palavras++;
        }
        if(texto[controle] == '.' || texto[controle] == '!' || texto[controle] == '?')
        {
            frases++;
        }
    }
    // printf("Total de letras: %i\n", letras);
    // printf("Total de palavras: %i\n", palavras);
    // printf("Total de frases: %i\n", frases);

    float L = (100 * ((float) letras / (float) palavras));
    float S = (100 * ((float) frases / (float) palavras));

    float indice = (0.0588 * L) - (0.296 * S) - 15.8;
    int escolaridade = (round(indice));

    if(escolaridade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (escolaridade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", escolaridade);
    }
}


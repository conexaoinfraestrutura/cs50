#include <stdio.h>
#include <cs50.h>
void bloco(int quantidade);
void espaco(int quantidade);
int entrada(void);

// blocos a esquerda
int main(void)
{
    int renderizar = entrada();
    int numeroDeEspacosBrancos = renderizar;
    int numeroDeBlocosPrenchidos = renderizar;
    for (int quebralinha = 0; quebralinha < renderizar; quebralinha++)
    {
        numeroDeEspacosBrancos--;
        espaco(numeroDeEspacosBrancos);bloco(numeroDeBlocosPrenchidos - numeroDeEspacosBrancos);
        printf("\n");
    }
}

// printa sustenidos
void bloco(int quantidade)
{
    for (int contador = 0; contador < quantidade; contador++)
    {
        printf("#");
    }
}

// printa espaços em branco
void espaco(int quantidade)
{
    for (int contador = 0; contador < quantidade; contador++)
    {
        printf(" ");
    }
}

// controla a entrada
int entrada(void)
{
    int altura;
    do
    {
        altura = get_int("informe um número, inteiro, entre 1 e 8: ");
    }
    while(altura < 1 || altura > 8);
    return altura;
}

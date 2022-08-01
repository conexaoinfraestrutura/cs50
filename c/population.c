#include <stdio.h>
#include <cs50.h>

int popInicial(void);
int popFinal(void);

int main(void)
{
    int anos = 0;
    int popInicio = popInicial();
    int popFim = popFinal();

    while (popFim < popInicio)
    {
        popFim = popFinal();
    }

    if (popInicio != popFim)
    {
        do
        {
            popInicio = popInicio + (popInicio / 3) - (popInicio / 4);
            anos++;
        }
        while (popInicio < popFim);
    }

    printf("Years: %i\n", anos);
}

int popInicial(void)
{
    int valor;
    do
    {
        valor = get_int("Start size: ");
    }
    while (valor < 9);
    return valor;
}

int popFinal(void)
{
    int valor;
    do
    {
        valor = get_int("End size: ");
    }
    while (valor < 9);
    return valor;
}

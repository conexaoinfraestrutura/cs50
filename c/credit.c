#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int pegaComprimento(long entrada);
int somaDosPares(int comprimento2);
int somaDosImpares(int comprimento1);
int checagem(int comprimento3);
int checaPrimeiroDigito(int comprimento4);
int checaSegundoDigito(int comprimento5);
long cartaoDoCliente(void);

long numeroDoCartao;

int main(void)
{

    numeroDoCartao = cartaoDoCliente();
    int comprimentoNumero = pegaComprimento(numeroDoCartao);

    if (comprimentoNumero == 13)
    {
        if (checagem(13) == 0)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }

    else if (comprimentoNumero == 15)
    {
        if(checaPrimeiroDigito(15) == 3)
        {
            if(checaSegundoDigito(15) == 4 || checaSegundoDigito(15) == 7)
            {
                if (checagem(15) == 0)
                {
                    printf("AMEX\n");
                }
                else
                {
                    printf("INVALID\n");
                }
            }
            else
            {
                printf("INVALID\n");
            }
        }
    }

    else if (comprimentoNumero == 16)
    {
        int posicao1 = (numeroDoCartao / 1000000000000000) % 10;
        if(posicao1 == 4)
        {
            if (checagem(16) == 0)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
            if(checaPrimeiroDigito(16) == 5)
            {
                if(checaSegundoDigito(16) == 1 || checaSegundoDigito(16) == 2 || checaSegundoDigito(16) == 3 || checaSegundoDigito(16) == 4 || checaSegundoDigito(16) == 5)
                {
                    if (checagem(16) == 0)
                    {
                        printf("MASTERCARD\n");
                    }
                    else
                    {
                        printf("INVALID\n");
                    }
                }
                else
                {
                    printf("INVALID\n");
                }
            }
    }
    else
    {
        printf("INVALID\n");
    }

}

int pegaComprimento(long entrada)
{
    return entrada == 0 ? 1 : (int)(log(labs(entrada)) / log(10)) + 1;
}

int somaDosPares(int comprimento2)
{
    int controle2 = 2;
    int total2 = 0;
    do
    {
        long divisor2 = pow(10, controle2 - 1);
        int p2Divisao = (numeroDoCartao / divisor2) % 10;
        if ((p2Divisao * 2) > 9)
        {
            int decimal2posicao1 = ((p2Divisao * 2) / 1) % 10;
            int decimal2posicao2 = ((p2Divisao * 2) / 10) % 10;
            total2 = total2 + decimal2posicao1 + decimal2posicao2;
        }
        else
        {
            total2 = total2 + (p2Divisao * 2);
        }
        controle2 += 2;
    }
    while (controle2 <= comprimento2);
    return total2;
}

int somaDosImpares(int comprimento1)
{
    int controle1 = 1;
    int total1 = 0;
    do
    {
        long divisor1 = pow(10, controle1 - 1);
        int p1Divisao = (numeroDoCartao / divisor1) % 10;
        total1 = total1 + p1Divisao;
        controle1 += 2;
    }
    while (controle1 <= comprimento1);
    return total1;
}

int checagem(int comprimento3)
{
    int retorno2 = somaDosPares(comprimento3);
    int retorno1 = somaDosImpares(comprimento3);
    int resultado = ((retorno1 + retorno2) / 1) % 10;
    return resultado;
}

int checaPrimeiroDigito(int comprimento4)
{
    long ultimaPosicao = pow(10, comprimento4 - 1);
    int digito1 = (numeroDoCartao / ultimaPosicao) % 10;
    return digito1;
}

int checaSegundoDigito(int comprimento5)
{
    long penultimaPosicao = pow(10, comprimento5 - 2);
    int digito2 = (numeroDoCartao / penultimaPosicao) % 10;
    return digito2;
}

long cartaoDoCliente(void)
{
    long cartao;
    do
    {
        cartao = get_long("Number: ");
    }
    while(cartao < 1);
    return cartao;
}

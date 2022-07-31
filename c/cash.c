#include <cs50.h>
#include <stdio.h>

float grana(void);

int main(void)
{

    int totalDeMoedas = 0;
    float troco = grana();
    int granaDoCliente = troco * 100 + 0.5;

    //moedas de 25
    float ResultadoDe25 = granaDoCliente / 25;
    int restoInteiro25 = (int)ResultadoDe25;
    totalDeMoedas = totalDeMoedas + restoInteiro25;
    granaDoCliente = granaDoCliente - ( restoInteiro25 * 25 );

    //moedas de 10
    float ResultadoDe10 = granaDoCliente / 10;
    int restoInteiro10 = (int)ResultadoDe10;
    totalDeMoedas = totalDeMoedas + restoInteiro10;
    granaDoCliente = granaDoCliente - ( restoInteiro10 * 10 );

    //moedas de 5
    float ResultadoDe5 = granaDoCliente / 5;
    int restoInteiro5 = (int)ResultadoDe5;
    totalDeMoedas = totalDeMoedas + restoInteiro5;
    granaDoCliente = granaDoCliente - ( restoInteiro5 * 5 );

    //moedas de 1
    float ResultadoDe1 = granaDoCliente / 1;
    int restoInteiro1 = (int)ResultadoDe1;
    totalDeMoedas = totalDeMoedas + restoInteiro1;
    granaDoCliente = granaDoCliente - ( restoInteiro1 * 1 );

    printf("coins: %i\n", totalDeMoedas);

}

float grana(void)
{
    float valor;
    do
    {
        valor = get_float("Change owned: ");
    }
    while(valor <= 0);
    return valor;
}

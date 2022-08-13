#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Defini a estrutura de dados dos canalhas
typedef struct
{
    string nome;
    int voto;
candidato;

// Defini o tamanho máximo da array de canalhas em uma constante (Obrigatorio)
#define MAXCANALHAS 9
candidato canalhas[MAXCANALHAS];

// Outra variável util nos laços das funções adjacentes e principal
int realocaIndiceArrayCanalhas;

// Prototipos das funcoes
bool vote(string nomeDoCanalha);
void print_winner(void);

int main(int argc, string argv[])
{
    // Reposiciona indice da array de canalhas
    realocaIndiceArrayCanalhas = argc - 1;

    // povoa a matriz com candidatos e total de votos zerado
    for(int i = 0; i < realocaIndiceArrayCanalhas; i++)
    {
        canalhas[i].nome = argv[i + 1];
    }

    // defini o numero de eleitores
    int eleitores = get_int("Number of voters: ");

    for(int i = 0, n = eleitores; i < n; i++)
    {
        // obtem o nome do votado
        string votoFeito = get_string("Vote: ");

        // Computa o voto valido e alerta os invalidos
        if(vote(votoFeito) == 0)
        {
            printf("Invalid vote.\n");
        }
    }

    // chama função que retorna o vencedor
    print_winner();

}

// funcao de update de votos
bool vote(string nomeDoCanalha)
{
    // Computa o voto
    for(int i = 0; i < realocaIndiceArrayCanalhas; i++)
    {
        if(strcmp(canalhas[i].nome, nomeDoCanalha) == 0)
        {
            canalhas[i].voto++;
            return true;
        }
    }
    return false;
}

// funcao que mostra o(s) vencedor(es)
void print_winner(void)
{
    // ordena a array
    for(int i = 0; i < realocaIndiceArrayCanalhas; i++)
    {
        for(int j = 0; j < realocaIndiceArrayCanalhas; j++)
        {
            if(canalhas[i].voto < canalhas[j].voto)
            {
                canalhas[i].voto = canalhas[j].voto;
                canalhas[i].nome = canalhas[j].nome;
            }
        }
    }

    // printa o vencedor
    printf("%s\n", canalhas[0].nome);

    // verifica se não houve empates
    for(int i = 0; i < realocaIndiceArrayCanalhas; i++)
    {
        if(canalhas[i + 1].voto == canalhas[i].voto && canalhas[i + 1].nome != canalhas[i].nome)
        {
            printf("%s\n", canalhas[i + 1].nome);
        }
    }
}

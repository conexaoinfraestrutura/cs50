#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Defini a estrutura de dados dos canalhas
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Defini o tamanho máximo da array de canalhas em uma constante (Obrigatorio)
#define MAX_VOTERS 10
#define MAX_CANDIDATES 4
candidate candidates[MAX_CANDIDATES];
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Outras variáveis uties
int candidatesIndex;
int majorityTotal;
int electors;
int minimunVotes;

// Prototipos das funcoes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void ripof(int min);
void printastruct(void);
void printapref(void);

int main(int argc, string argv[])
{
    // Monta o array de candidatos
    candidatesIndex = argc - 1;
    for(int i = 0; i < candidatesIndex; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    // Capta e valida os votos
    electors = get_int("Number of voters: ");
    printf("\n");

    for(int i = 0; i < electors; i++)
    {
        int voter = i;
        for(int j = 0; j < candidatesIndex; j++)
        {
            int rank = j;
            string name = get_string("Rank %i: ", rank + 1);

            if(vote(voter,rank,name) == 0)
            {
                printf("Invalid vote.\n");
            }
        }

        printf("\n");
    }

    // Computa a eleição
    int controle = 1;
    do
    {
        tabulate();
        ripof(find_min());
        ++controle;
    }
    while(controle == argc);

    // Declara o vencedor ou o empate
    if(print_winner())
    {
        for(int i = 0; i < candidatesIndex; i++)
        {
            for(int j = 0; j < candidatesIndex; j++)
            {
                if(candidates[i].votes < candidates[j].votes)
                {
                    candidates[0].votes = candidates[j].votes;
                    candidates[0].name = candidates[j].name;
                    candidates[j].votes = candidates[0].votes;
                    candidates[j].name = candidates[0].name;
                }
            }
        }
        printf("%s\n", candidates[0].name);
    }
    else if(is_tie(find_min()))
    {
        printf("tie\n");
    }

    //printastruct();
    //printapref();
}

// Monta a array de escolhas
bool vote(int voter, int rank, string name)
{
    for(int i = 0; i < candidatesIndex; i++)
    {
        if(strcmp(candidates[i].name, name) == 0)
        {
            preferences[voter][rank] = i;
            return true;
        }
    }
    return false;
}

// Contabiliza os votos dos candidatos
void tabulate(void)
{
    for(int i = 0; i < electors; i++)
    {
        for(int j = 0; j < candidatesIndex; j++)
        {
            if(preferences[i][j] == j)
            {
                if(!candidates[j].eliminated)
                {
                    candidates[j].votes++;
                }
            }
        }
    }
}

// Extrai a menor quantidade de votos
int find_min(void)
{
    minimunVotes = candidates[0].votes;
    for(int i = 0; i < candidatesIndex; i++)
    {
        if(!candidates[i].eliminated)
        {
            if(candidates[i].votes == minimunVotes)
            {
                minimunVotes = candidates[i].votes;
            }
        }
    }
    return minimunVotes;
}

// Elimina o candidato menos votado
void ripof(int min)
{
    for(int i = 0; i < candidatesIndex; i++)
    {
        if(!candidates[i].eliminated)
        {
            if(candidates[i].votes < min)
            {
                candidates[i].eliminated = true;
            }
        }
    }
}

// Verifica um vencedor
bool print_winner(void)
{
    majorityTotal = (electors / 2) + 1;
    for(int i = 0; i < candidatesIndex; i++)
    {
        if(candidates[i].votes >= majorityTotal)
        {
            return true;
        }
    }
    return false;
}

// Verifica um empate
bool is_tie(int min)
{
    bool istied = false;
    for(int i = 0; i < candidatesIndex; i++)
    {
        if(!candidates[i].eliminated)
        {
            if(candidates[i].votes == min)
            {
                 istied = true;
            }
        }
    }
    return istied;
}

// print a estrutura dos cadidatos (debug)
void printastruct(void)
{
    printf("Candidates:\n");
    printf("Name:\t");
    for(int i = 0; i < candidatesIndex; i++)
    {
        printf("%s\t", candidates[i].name);
    }
    printf("\n");
    printf("Votes:\t");
    for(int i = 0; i < candidatesIndex; i++)
    {
        printf("%i\t", candidates[i].votes);
    }
    printf("\n");
    printf("Ripof:\t");
    for(int i = 0; i < candidatesIndex; i++)
    {
        printf("%d\t", candidates[i].eliminated);
    }
    printf("\n");
}

// print as escolhas (debug)
void printapref(void)
{
    printf("\n");
    printf("Preferences:\n");
    printf("\n");
    for(int j = 0; j < electors; j++)
    {
        for(int i = 0; i < candidatesIndex; i++)
        {
            printf("preferences:%i\n", preferences[j][i]);
        }
    printf("\n");
    }
}

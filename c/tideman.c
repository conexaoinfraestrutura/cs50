#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Defini a estrutura de dados
typedef struct
{
    int winner;
    int loser;
}
pair;

// Defini a quantidade máxima de candidatos (Obrigatorio)
#define MAX_CANDIDATES 9

// Arrays
string candidates[MAX_CANDIDATES];
pair pairs[MAX_CANDIDATES * (MAX_CANDIDATES - 1) / 2];
int preferences[MAX_CANDIDATES][MAX_CANDIDATES];
int locked[MAX_CANDIDATES][MAX_CANDIDATES];

// Outras variáveis
int candidatesIndex;
int electors;
int pair_count;

// Prototipos das funcoes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Monta o array de candidatos
    candidatesIndex = argc - 1;
    for(int i = 0; i < candidatesIndex; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Capta o numero de eleitores
    electors = get_int("Number of voters: ");
    printf("\n");

    for(int i = 0; i < electors; i++)
    {
        // Incializa a array com a classificação dos candidatos
        int ranks[candidatesIndex];

        for(int j = 0; j < candidatesIndex; j++)
        {

            string name = get_string("Rank %i: ", j + 1);

            // Na hora de passar o array, apenas use o nome do array, sem []
            if(vote(j,name,ranks) == 0)
            {
                printf("Invalid vote.\n");
            }
        }

        // armazena os dados
        record_preferences(ranks);

        printf("\n");
    }

    // computada a eleição
    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
}

bool vote(int rank, string name, int ranks[])
{
    for(int i = 0; i < candidatesIndex; i++)
    {
        if(strcmp(candidates[i], name) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

void record_preferences(int ranks[])
{
    for(int i = 0; i < candidatesIndex; i++)
    {
        for(int j = i+1; j < candidatesIndex; j++)
        {
            preferences[ranks[i]][ranks[j]]++;
        }
    }
}

void add_pairs(void)
{
    for(int i = 0; i < candidatesIndex; i++)
    {
        for(int j = 0; j < candidatesIndex; j++)
        {
            if(preferences[i][j] > preferences[j][i])
            {
                pair new_pair = {i, j};
                pairs[pair_count] = new_pair;
                pair_count++;
            }
        }
    }
}

int pair_weight(i)
{
    int pair_winner = pairs[i].winner;
    int pair_loser = pairs[i].loser;
    return preferences[pair_winner][pair_loser];
}

void sort_pairs(void)
{
    for(int i = pair_count - 1; i >= 0; i--)
    {
        int min_weight = pair_weight(i);
        int min_idx = i;
        for(int j = i-1; j >= 0; j--)
        {
            if(pair_weight(j) < min_weight)
            {
                min_weight = pair_weight(j);
                min_idx = j;
            }
        }
        pair temp = pairs[min_idx];
        pairs[min_idx] = pairs[i];
        pairs[i] = temp;
    }
}

bool has_cycle(int winner, int loser)
{
    if(locked[loser][winner] == true)
    {
        return true;
    }
    for(int i = 0; i < candidatesIndex; i++)
    {
        if(locked[loser][i] == true && has_cycle(winner,i))
        {
            return true;
        }
    }
    return false;
}

void lock_pairs(void)
{
    for(int i = 0; i < pair_count; i++)
    {
        int winner = pairs[i].winner;
        int loser = pairs[i].loser;
        if(!has_cycle(winner, loser))
        {
            locked[winner][loser] = true;
        }
    }
}

void print_winner(void)
{
    for(int i = 0; i < candidatesIndex; i++)
    {
        for(int j = 0; j < candidatesIndex; j++)
        {
            if(locked[i][j] == true)
            {
                break;
            }
            else if(j == candidatesIndex - 1)
            {
                printf("%s\n", candidates[i]);
            }
        }
    }
}

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char embaralhar(char entrada, string chave);

int main(int argc, string argv[])
{
    // verifica a quantidade de argumentos
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        exit(1);
    }

    // verifica se o comprimento da chave é de 26 posições
    if(strlen(argv[1]) < 26 || strlen(argv[1]) > 26)
    {
        printf("Key must contain 26 characters.\n");
        exit(1);
    }

    // Verifica ser a chave é albabetica
    for(int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if(!isalpha(argv[1][i])){
            printf("Key must only contain alphabetic characters.\n");
            exit(1);
        }
    }

    // Verifica ser não a há duplicados
    int count;
    for(int i = 0; i < strlen(argv[1]); i++) {
        count = 1;
        for(int j = i+1; j < strlen(argv[1]); j++) {
            if(argv[1][i] == argv[1][j] && argv[1][i] != ' ') {
                count++;
                argv[1][j] = '0';
            }
        }
        if(count > 1 && argv[1][i] != '0')
        {
            printf("Key must not contain repeated characters.\n");
            exit(1);
        }
    }

    // recebe o texto a ser criptografado
    string texto = get_string("plaintext: ");

    // encripta e printa cada caractere
    printf("ciphertext: ");

    for(int i = 0, n = strlen(texto); i < n; i++)
    {
        char caractereCriptografado = embaralhar(texto[i], argv[1]);
        printf("%c", caractereCriptografado);
    }

    printf("\n");

}

char embaralhar(char entrada, string chave){
        if (isupper(entrada))
        {
            int indiceAlfabetico = (int) entrada - 65;
            return toupper(chave[indiceAlfabetico]);
        }
        else if (islower(entrada))
        {
            int indiceAlfabetico = (int) entrada - 97;
            return tolower(chave[indiceAlfabetico]);
        }
        else
        {
            return entrada;
        }
}

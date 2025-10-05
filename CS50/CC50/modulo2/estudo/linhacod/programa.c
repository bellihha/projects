#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    // Verifica se a quantidade de argumentos é válida
    if (argc != 2)
    {
        printf("Uso: ./programa chave\n");
        return 1; // Retorna 1 indicando erro
    }

    // Pega a chave do segundo argumento
    string key = argv[1];

    // Mostra a chave para o usuário
    printf("A chave inserida foi: %s\n", key);

    return 0; // Retorna 0 indicando sucesso
}


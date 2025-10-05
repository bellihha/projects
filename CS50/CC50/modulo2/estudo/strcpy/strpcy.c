#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // solicita uma string.
    string nome = get_string("Insira seu nome: ");

    // cria um array para armazenar a copia.
    char copia{strlen(nome) + 1};

    // copia o conteudo de nome para copia.
    strcpy(copia, nome);

    for (int c = 0; copia[c] != '\0'; c++)
    {
        copia[c] = 'x';
    }

    // exibe o original e a copia.
    printf("Original: %s\n", nome);
    printf("Cópia: %s\n", copia);
}

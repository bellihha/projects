#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // solicita o nome do usuario com get_string.
    string nome = get_string("Insira seu nome: ");

    // exibe cada caractere da string em uma nova linha.
    for (int n = 0; nome[n] != '\0'; n++)
    {
        printf("%c\n", nome[n]);
    }
}

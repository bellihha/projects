#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // solicita o nome do usuario.
    string nome = get_string("Insira seu nome: ");

    // calcula quantos caracteres tem no string
    int contador = 0;
    for (int i = 0; nome[i] != '\0'; i++)
    {
        contador++;
    }

    // printa o resultado
    printf("Quantidade: %i\n", contador);

}

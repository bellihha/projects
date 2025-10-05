#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // solicitar o nome do usuario
    string nome = get_string("Insira seu nome para a contagem: ");

    // faz a contagem automatica dos caracteres no string nome.
    int comprimento = strlen(nome);

    // dá o resultado da contagem.
    printf("Quantidade: %i\n", comprimento);

    if (comprimento < 5)
    {
        printf("Seu nome é bem curo! :D\n");
    }
    else if (comprimento > 5 && comprimento < 10)
    {
        printf("Seu nome é na média! :D\n");
    }
    else
    {
        printf("Seu nome é  E N O R M E!! :O\n");
    }


}

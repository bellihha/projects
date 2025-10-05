#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // comprimenta o usuario :D
    string resposta = get_string("Qual é o seu nome?\n");
    printf("Olá, %s.\n", resposta);
}

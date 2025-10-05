#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // int idade1, idade2, idade3;
    // ao inves de criar 3 variaveis o array facilita diminuindo a equação.
    int idades[5];
    for (int i = 0; i < 5; i++)
    {
        idades[i] = get_int("Idades: ");
    }
    // os elementos dos array são acessados por indices, que sempre começam com 0.
    for (int final = 0; final < 5; final++)
    {
        printf("A idade informada foi: %i\n", idades[final]); // exibe o valor?
    }
}

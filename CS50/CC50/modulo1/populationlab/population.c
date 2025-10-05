#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Solicite o valor inicial ao usuário
    int n;
    do
    {
        n = get_int("Start size:\n");
    }
    while (n < 9);

    // TODO: Solicite o valor final ao usuário
    int x;
    do
    {
        x = get_int("End size:\n");
    }
    while (x < n);

    // TODO: Calcule o número de anos até o limite
    int e = 0;
    while (n < x)
    {
        n = n + (n / 3) - (n / 4);
        e++;
    }
    // TODO: Imprima o número de anos
    printf("Years: %i\n", e);
}

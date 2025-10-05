#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int Altura;
    do
    {
        Altura = get_int("Altura: ");
    }
    while (Altura < 1 || Altura > 8);


    for (int z = 0; z < Altura; z++)
    {

        for (int Coluna = 0; Coluna < Altura - z - 1; Coluna++)
            printf(" ");

        for (int Coluna = 0; Coluna <= z; Coluna++)
            printf("#");

        printf("  ");

        for (int Coluna = 0; Coluna <= z; Coluna++)
            printf("#");

        printf("\n");
    }
}

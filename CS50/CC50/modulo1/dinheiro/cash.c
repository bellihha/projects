#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    float troco;

    do
    {
        troco = get_float("Seu troco: ");
    }
    while (troco < 000.0001);

    int centavos = round(troco * 100);

    printf("\033[36mTroco fornecido: %.2f\033[0m\n", troco);

    // Valores do centavos

    int moeda25 = (centavos / 25);
    centavos = centavos % 25;

    int moeda10 = (centavos / 10);
    centavos = centavos % 10;

    int moeda5 = (centavos / 5);
    centavos = centavos % 5;

    int moeda1 = (centavos / 1);
    centavos = centavos % 1;

    // Exibindo para testar
    printf("\033[35mTotal de moedas necessarias: %d\033[0m\n", moeda25 + moeda10 + moeda5 + moeda1);
    if (moeda25 > 0)
        printf("\033[36mMoedas de 25 centavos: %d\033[0m\n", moeda25);
    if (moeda10 > 0)
        printf("\033[36mMoedas de 10 centavos: %d\033[0m\n", moeda10);
    if (moeda5 > 0)
        printf("\033[36mMoedas de 5 centavos: %d\033[0m\n", moeda5);
    if (moeda1 > 0)
        printf("\033[36mMoedas de 1 centavo: %d\033[0m\n", moeda1);
}

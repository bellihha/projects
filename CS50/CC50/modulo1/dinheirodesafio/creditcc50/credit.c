#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Solicita o número do cartão
    long numero = get_long("Número: ");

    // Determina o comprimento e os dois primeiros dígitos
    int comprimento = 0;
    long temp = numero;
    int primeiros_dois = 0;

    while (temp > 0)
    {
        if (temp >= 10 && temp < 100)
        {
            primeiros_dois = temp; // Captura os dois primeiros dígitos
        }
        temp /= 10;
        comprimento++;
    }

    // Aplica o Algoritmo de Luhn
    int soma_total = 0;
    temp = numero;
    for (int i = 0; temp > 0; i++, temp /= 10)
    {
        int digito = temp % 10;
        if (i % 2 == 0)
        {
            soma_total += digito;
        }
        else
        {
            int produto = digito * 2;
            soma_total += (produto / 10) + (produto % 10);
        }
    }

    // Valida o cartão
    if (soma_total % 10 == 0)
    {
        if (comprimento == 15 && (primeiros_dois == 34 || primeiros_dois == 37))
        {
            printf("AMEX\n");
            return 0;
        }
        else if (comprimento == 16 && (primeiros_dois >= 51 && primeiros_dois <= 55))
        {
            printf("MASTERCARD\n");
            return 0;
        }
        else if ((comprimento == 13 || comprimento == 16) && (primeiros_dois / 10 == 4))
        {
            printf("VISA\n");
            return 0;
        }
    }

    // Caso inválido
    printf("INVALID\n");
}

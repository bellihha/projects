#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    // solicitação de credito perfeita.
   long credito;

   credito = get_long("Coloque se numero do cartão de credito for American express, Mastercard ou VISA: " );

   // printf meramente ilustrativo.
   printf("\033[36mCredito fornecido: %li\033[0m\n", credito);

   // calculo...

   int posição = 0;
   int soma_total = 0;
   int comprimento = 0;

   long temp = credito;

   while (temp > 0)
   {
    temp /= 10;
    comprimento++;
   }

   int primeiros_dois = credito;
   while (primeiros_dois >= 100)
   {
    primeiros_dois /= 10;
    }


   while(credito > 0)
   {

     int digito = credito % 10;

     if (posição % 2 == 0)
     {
        soma_total += digito;
     }
     else
     {
        int produto = digito * 2;
        if (produto > 9)
        {
            soma_total += (produto / 10) + (produto % 10);
        }
        else
        {
            soma_total += produto;
        }
     }
     posição++;
     credito /= 10;
   }

   printf("\033[36mSoma total dos dígitos (já calculado): %d\033[0m\n", soma_total);

   if (soma_total % 10 == 0)
{
    if (comprimento == 15 && (primeiros_dois == 34 || primeiros_dois == 37))
    {
        printf("\033[32mCartão válido: American Express\033[0m\n");
    }
    else if (comprimento == 16 && (primeiros_dois >= 51 && primeiros_dois <= 55))
    {
        printf("\033[32mCartão válido: Mastercard\033[0m\n");
    }
    else if ((comprimento == 13 || comprimento == 16) && (primeiros_dois / 10 == 4))
    {
        printf("\033[32mCartão válido: VISA\033[0m\n");
    }
    else
    {
        printf("\033[31mCartão inválido: Não corresponde a nenhuma bandeira conhecida\033[0m\n");
    }
}
else
{
    printf("\033[31mEste número de crédito é inválido!\033[0m\n");
}


}

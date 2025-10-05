#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("./substitution KEY \n");
        return 1;
    }

    int comprimento = strlen(argv[1]);

    if (comprimento != 26)
    {
        printf("A chave deve conter 26 caracteres.\n");
        return 1;
    }

    int letras_vistas[26] = {0};

    for (int k = 0; k < comprimento; k++)
    {
        char caractere_atual = argv[1][k];

        if (!isalpha(caractere_atual))
        {
            printf("A chave deve conter apenas letras.\n");
            return  1;
        }

        int indice = toupper(caractere_atual) - 'A';

        if (letras_vistas[indice] == 1)
        {
            printf("A chave não pode repetir letras.\n");
            return 1;
        }
        else if (letras_vistas[indice] == 0)
        {
            letras_vistas[indice] = 1;
        }
    }

    string texto_simples = get_string("Texto simples: ");

    printf("texto cifrado: ");

    for (int i = 0; i < strlen(texto_simples); i++)
    {
        char caractere_original = texto_simples[i];

        if (isalpha(texto_simples[i]))
        {
            int index;
            char caractere_cifrado;
            if (isupper(texto_simples[i]))
            {
                index = texto_simples[i] - 'A';
                caractere_cifrado = argv[1][index];
                printf("%c", toupper(caractere_cifrado));

            }
            else if (islower(texto_simples[i]))
            {
                index = texto_simples[i] - 'a';
                caractere_cifrado = argv[1][index];
                printf("%c", tolower(caractere_cifrado));
            }
        }
        else
        {
            printf("%c", caractere_original);
        }
    }

    printf("\n");

    return 0;
}


#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// armazena as variaveis que guardam os resultados.
typedef struct
{
    int letras;
    int palavras;
    int frases;
} contagem;

contagem calculo(string text);

int main(void)
{

    // pega o texto do usuario.
    string texto0 = get_string("Text: ");

    // calcular indice.
    contagem resultado = calculo(texto0);

    float L = (float) resultado.letras / resultado.palavras * 100;
    float S = (float) resultado.frases / resultado.palavras * 100;
    float indice = 0.0588 * L - 0.296 * S - 15.8;

    // exibe o resultado.
    if (indice < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (indice >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", (int) round(indice));
    }
}

contagem calculo(string text)
{
    // começa as contagens de letras, palavras e frases.
    contagem contagem = {0, 0, 0};

    // conta as letras, palavras e frases.
    for (int p = 0; text[p] != '\0'; p++)
    {
        if (isalpha(text[p]))
        {
            contagem.letras++;
        }
        if (text[p] == ' ')
        {
            contagem.palavras++;
        }
        if (text[p] == '.' || text[p] == '!' || text[p] == '?')
        {
            contagem.frases++;
        }
    }
    if (contagem.letras > 0)
    {
        contagem.palavras++;
    }
    return contagem;
}

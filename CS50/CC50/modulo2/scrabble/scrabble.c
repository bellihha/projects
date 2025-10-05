#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Solicitar ao usuário duas palavras.
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Calcular os pontos de cada palavra.
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Imprimir o vencedor ou empate.
    if (score1 == score2)
    {
        printf("Tie! \n");
    }
    else if (score1 > score2)
    {
        printf("Player 1 wins! :D \n");
    }
    else
    {
        printf("Player 2 wins! :D \n");
    }
    printf("Score 1: %i \n", score1);
    printf("Score 2: %i \n", score2);
}

// Computa e devolve os pontos de cada palavra.
int compute_score(string word)
{

    int total_points = 0;
    for (int p = 0; word[p] != '\0'; p++)
    {
        if (isalpha(word[p]))
        {
            int index;
            if (isupper(word[p]))
            {
                index = word[p] - 'A';
            }
            else
            {
                index = word[p] - 'a';
            }
            total_points += POINTS[index];
        }
    }
    return total_points; // retorna os pontos totais.
}

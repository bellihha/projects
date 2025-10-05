// Inclui as bibliotecas necessárias para o projeto.
#include <cs50.h>    // Para a função get_string()
#include <ctype.h>   // Para as funções isalpha(), isupper(), islower(), toupper(), tolower()
#include <stdio.h>   // Para a função printf()
#include <string.h>  // Para a função strlen()

// A função principal do programa, que começa a ser executada.
// argc: contém o número de palavras na linha de comando.
// argv: é um array de strings, contendo as palavras da linha de comando.
int main(int argc, string argv[])
{
    // --- VALIDAÇÃO DOS ARGUMENTOS E DA CHAVE ---

    // 1. VERIFICA O NÚMERO DE ARGUMENTOS
    // O programa deve ser executado com exatamente 2 argumentos:
    // o nome do programa (ex: ./substitution) e a chave.
    // Se argc não for 2, o uso está incorreto.
    if (argc != 2)
    {
        printf("./substitution KEY\n"); // Imprime a forma correta de usar.
        return 1; // Retorna 1, que significa que o programa terminou com um erro.
    }

    // Pega o comprimento da chave, que está em argv[1].
    int comprimento = strlen(argv[1]);

    // 2. VERIFICA O COMPRIMENTO DA CHAVE
    // Se o comprimento não for exatamente 26 caracteres, a chave é inválida.
    if (comprimento != 26)
    {
        printf("A chave deve conter 26 caracteres.\n");
        return 1; // Termina com erro.
    }

    // Cria um array para funcionar como um "checklist" para as 26 letras do alfabeto.
    // Inicializamos tudo com 0. O 0 significará "letra ainda não vista".
    int letras_vistas[26] = {0};

    // 3. VERIFICA O CONTEÚDO DA CHAVE (SE SÃO LETRAS E SE NÃO HÁ REPETIÇÃO)
    // Loop que passa por cada caractere da chave, da posição 0 até o final.
    for (int k = 0; k < comprimento; k++)
    {
        // Pega o caractere atual da chave para facilitar a leitura do código.
        char caractere_atual = argv[1][k];

        // 3a. VERIFICA SE O CARACTERE É UMA LETRA DO ALFABETO
        // A função isalpha() checa se um caractere é uma letra.
        // O "!" inverte a lógica, então o if é acionado se NÃO for uma letra.
        if (!isalpha(caractere_atual))
        {
            printf("A chave deve conter apenas letras.\n");
            return 1; // Termina com erro.
        }

        // 3b. VERIFICA SE HÁ LETRAS REPETIDAS
        // Converte o caractere para maiúsculo para padronizar ('a' e 'A' são tratados da mesma forma).
        // A subtração por 'A' transforma a letra em um índice de 0 a 25 ('A'-'A'=0, 'B'-'A'=1, etc).
        int indice = toupper(caractere_atual) - 'A';

        // Verifica o nosso "checklist". Se na posição 'indice' o valor já for 1...
        if (letras_vistas[indice] == 1)
        {
            // ...significa que já vimos essa letra antes. É uma duplicata!
            printf("A chave não pode repetir letras.\n");
            return 1; // Termina com erro.
        }
        else // Se o valor ainda for 0...
        {
            // ...significa que é a primeira vez que vemos esta letra.
            // Marcamos sua posição no checklist como 1 ("letra vista").
            letras_vistas[indice] = 1;
        }
    }

    // --- CRIPTOGRAFIA DO TEXTO ---
    // Se o programa chegou até aqui, a chave é 100% válida.

    // Pede ao usuário para digitar o texto que será criptografado.
    string texto_simples = get_string("texto simples: ");

    // Imprime o prefixo da saída, como pedido no enunciado.
    printf("texto cifrado: ");

    // Loop que passa por cada caractere do texto digitado pelo usuário.
    for (int i = 0; i < strlen(texto_simples); i++)
    {
        // Pega o caractere original do texto do usuário.
        char caractere_original = texto_simples[i];

        // Verifica se o caractere original é uma letra do alfabeto.
        if (isalpha(caractere_original))
        {
            // Se for uma letra, precisamos criptografá-la.
            int index;
            char caractere_cifrado;

            // Verifica se a letra original era maiúscula.
            if (isupper(caractere_original))
            {
                // Calcula o índice de 0-25 da letra.
                index = caractere_original - 'A';
                // Usa o índice para encontrar a letra correspondente na chave.
                caractere_cifrado = argv[1][index];
                // Imprime a letra cifrada, garantindo que ela seja maiúscula.
                printf("%c", toupper(caractere_cifrado));
            }
            else // Se não era maiúscula, só pode ser minúscula.
            {
                // Calcula o índice de 0-25 da letra.
                index = caractere_original - 'a';
                // Usa o índice para encontrar a letra correspondente na chave.
                caractere_cifrado = argv[1][index];
                // Imprime a letra cifrada, garantindo que ela seja minúscula.
                printf("%c", tolower(caractere_cifrado));
            }
        }
        else // Se o caractere original NÃO for uma letra...
        {
            // ...não fazemos nada, apenas o imprimimos como ele é (espaços, números, pontuação).
            printf("%c", caractere_original);
        }
    }

    // Após o loop terminar, imprime uma nova linha para formatar a saída.
    printf("\n");

    // Retorna 0, que significa que o programa foi executado com sucesso.
    return 0;
}

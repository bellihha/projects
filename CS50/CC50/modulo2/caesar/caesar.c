#include <cs50.h>

#include <ctype.h>
#include <stdio.h>
#include <string.h>

// variavel que vai criptografar o plaintext.
void cript(string text, int key);

int main(int argc, string argv[]) // pega a key
{
    if (argc != 2) // pega o caractere correto.
    {
        printf("Usage: ./caesar key \n");
        return 1;
    }

    int key = 0;
    for (int i = 0; argv[1][i] != '\0'; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key \n");
            return 1;
        }

        key = key * 10 + (argv[1][i] - '0');
    }

    // pega plaintext.
    string plaintext = get_string("Plaintext: ");

    // printa ciphertext.
    printf("Ciphertext: ");
    cript(plaintext, key);

    // significa que esta tudo certo.
    return 0;
}

// criptografa o plaintext para ciphertext.
void cript(string text, int key)
{
    for (int L = 0; text[L] != '\0'; L++)
    {
        if (isalpha(text[L]))
        {
            int encrypted_index;
            int index;
            char encrypted;
            if (isupper(text[L]))
            {
                index = text[L] - 'A';
                encrypted_index = (index + key) % 26;
                encrypted = encrypted_index + 'A';
                printf("%c", encrypted);
            }
            else if (islower(text[L]))
            {
                index = text[L] - 'a';
                encrypted_index = (index + key) % 26;
                encrypted = encrypted_index + 'a';
                printf("%c", encrypted);
            }
        }
        else
        {
            printf("%c", text[L]);
        }
    }
    printf("\n");
}

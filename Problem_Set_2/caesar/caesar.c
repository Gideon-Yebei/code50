#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void encrypt(string plaintext, int key);
bool is_valid_key(string key);

int main(int argc, string argv[])
{
    // Check if the user provides a command-line argument
    if (argc != 2 || !is_valid_key(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Convert the key from string to an integer
    int key = atoi(argv[1]);

    // Get plaintext input from the user
    string plaintext = get_string("plaintext: ");

    // Encrypt the plaintext using the provided key
    encrypt(plaintext, key);

    return 0;
}

// Function to check if the provided key is a valid integer
bool is_valid_key(string key)
{
    // Check each character of the key
    for (int i = 0; key[i] != '\0'; i++)
    {
        // If any character is not a digit, return false
        if (!isdigit(key[i]))
        {
            return false;
        }
    }
    return true;
}

// Function to encrypt plaintext using Caesar cipher
void encrypt(string plaintext, int key)
{
    printf("ciphertext: ");

    // Iterate through each character in the plaintext
    for (int i = 0; plaintext[i] != '\0'; i++)
    {
        char encrypted_char;

        // Encrypt alphabetic characters
        if (isalpha(plaintext[i]))
        {
            // Determine whether the character is uppercase or lowercase
            char base = isupper(plaintext[i]) ? 'A' : 'a';

            // Apply Caesar cipher encryption formula
            encrypted_char = (plaintext[i] - base + key) % 26 + base;
        }
        else
        {
            // Keep non-alphabetic characters unchanged
            encrypted_char = plaintext[i];
        }

        // Print the encrypted character
        printf("%c", encrypted_char);
    }

    printf("\n");
}

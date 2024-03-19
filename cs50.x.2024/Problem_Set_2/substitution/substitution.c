#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define ALPHABET_LENGTH 26

// Function to validate the key
bool validate_key(string key);

// Function to encrypt plaintext using substitution cipher
void encrypt(string plaintext, string key);

int main(int argc, string argv[])
{
    // Check if the user provides a command-line argument
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // Validate the key
    if (!validate_key(argv[1]))
    {
        printf("Key must contain 26 unique alphabetic characters.\n");
        return 1;
    }

    // Get plaintext input from the user
    string plaintext = get_string("plaintext: ");

    // Encrypt the plaintext using the provided key
    encrypt(plaintext, argv[1]);

    return 0;
}

bool validate_key(string key)
{
    // Check if the key has exactly 26 characters
    if (strlen(key) != ALPHABET_LENGTH)
    {
        return false;
    }

    // Initialize an array to keep track of characters encountered
    bool encountered[ALPHABET_LENGTH] = {false};

    // Iterate through each character in the key
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        // Check if the character is alphabetic
        if (!isalpha(key[i]))
        {
            return false;
        }

        // Convert the character to uppercase
        char c = toupper(key[i]);

        // Check if the character has already been encountered
        if (encountered[c - 'A'])
        {
            return false;
        }

        // Mark the character as encountered
        encountered[c - 'A'] = true;
    }

    return true;
}

void encrypt(string plaintext, string key)
{
    printf("ciphertext: ");

    // Iterate through each character in the plaintext
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        char encrypted_char;

        // Encrypt alphabetic characters
        if (isalpha(plaintext[i]))
        {
            // Determine whether the character is uppercase or lowercase
            char base = isupper(plaintext[i]) ? 'A' : 'a';

            // Determine the index of the character in the key
            int index = toupper(plaintext[i]) - 'A';

            // Get the corresponding character in the key
            encrypted_char = isupper(plaintext[i]) ? toupper(key[index]) : tolower(key[index]);
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

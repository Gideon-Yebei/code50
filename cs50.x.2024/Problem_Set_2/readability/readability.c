#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
float calculate_index(int letters, int words, int sentences);

int main(void)
{
    // Get input text from the user
    string text = get_string("Text: ");

    // Count letters, words, and sentences
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // Calculate the Coleman-Liau index
    float index = calculate_index(letters, words, sentences);

    // Round index to nearest integer
    int grade = (int) (index + 0.5);

    // Output the result
    if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }

    return 0;
}

// Function to count letters in the text
int count_letters(string text)
{
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isalpha(text[i]))
        {
            count++;
        }
    }
    return count;
}

// Function to count words in the text
int count_words(string text)
{
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isspace(text[i]) || text[i + 1] == '\0')
        {
            count++;
        }
    }
    return count;
}

// Function to count sentences in the text
int count_sentences(string text)
{
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        }
    }
    return count;
}

// Function to calculate the Coleman-Liau index
float calculate_index(int letters, int words, int sentences)
{
    float L = (float) letters / words * 100;
    float S = (float) sentences / words * 100;
    return 0.0588 * L - 0.296 * S - 15.8;
}

#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Function to calculate the score of a word
int calculate_score(char *word);

int main(void)
{
    // Define the point values for each letter
    int points[] = {/* A */ 1,  /* B */ 3, /* C */ 3, /* D */ 2,
                    /* E */ 1,  /* F */ 4, /* G */ 2, /* H */ 4,
                    /* I */ 1,  /* J */ 8, /* K */ 5, /* L */ 1,
                    /* M */ 3,  /* N */ 1, /* O */ 1, /* P */ 3,
                    /* Q */ 10, /* R */ 1, /* S */ 1, /* T */ 1,
                    /* U */ 1,  /* V */ 4, /* W */ 4, /* X */ 8,
                    /* Y */ 4,  /* Z */ 10};

    char word1[20], word2[20];
    int score1 = 0, score2 = 0;

    // Prompt player 1 for their word
    printf("Player 1, enter your word: ");
    scanf("%s", word1);

    // Prompt player 2 for their word
    printf("Player 2, enter your word: ");
    scanf("%s", word2);

    // Calculate the score for player 1's word
    score1 = calculate_score(word1);

    // Calculate the score for player 2's word
    score2 = calculate_score(word2);

    // Compare scores and determine the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }

    return 0;
}

int calculate_score(char *word)
{
    // Define the point values for each letter
    int points[] = {/* A */ 1,  /* B */ 3, /* C */ 3, /* D */ 2,
                    /* E */ 1,  /* F */ 4, /* G */ 2, /* H */ 4,
                    /* I */ 1,  /* J */ 8, /* K */ 5, /* L */ 1,
                    /* M */ 3,  /* N */ 1, /* O */ 1, /* P */ 3,
                    /* Q */ 10, /* R */ 1, /* S */ 1, /* T */ 1,
                    /* U */ 1,  /* V */ 4, /* W */ 4, /* X */ 8,
                    /* Y */ 4,  /* Z */ 10};

    int score = 0;

    // Calculate the score for the word
    for (int i = 0; word[i] != '\0'; i++)
    {
        // Convert the character to uppercase
        char uppercase_letter = toupper(word[i]);

        // Check if the character is a valid letter
        if (isalpha(uppercase_letter))
        {
            // Calculate the score based on the letter
            score += points[uppercase_letter - 'A'];
        }
    }

    return score;
}

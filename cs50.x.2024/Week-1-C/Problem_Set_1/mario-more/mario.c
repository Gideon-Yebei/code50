#include <cs50.h>
#include <stdio.h>

/**
 * @file mario.c
 * @brief Prints a pyramid of '#' characters based on user input.
 *
 * This program prompts the user for the height of a pyramid and then prints a pyramid
 * of '#' characters with the specified height. The program ensures that the height
 * is between 1 and 8, inclusive.
 */

int main(void)
{
	// Prompt the user for the pyramid's height
	int n;
	do
	{
		n = get_int("Height: ");
	} while (n < 1 || n > 8);

	// Print a pyramid of that height
	int i;
	int j;
	for (i = 0; i < n; i++)
	{
		// Print spaces
		for (j = 0; j < n - i - 1; j++)
		{
			printf(" ");
		}
		// Print '#' characters
		printf("*");

		// print space between
		printf(" ");

		// Print '#' characters
		for (j = 0; j <= i; j++)
		{
			printf("#");
		}

		// Move to the next line after each row
		printf("\n");
	}
	return 0;
}

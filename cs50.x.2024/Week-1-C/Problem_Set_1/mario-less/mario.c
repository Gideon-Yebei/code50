#include <cs50.h>
#include <stdio.h>

/**
 * Prints a pyramid of a given height.
 *
 * @param n The height of the pyramid.
 */
int main(void)
{
	// Prompt the user for the pyramid's height
	int n;
	do
	{
		n = get_int("Height: ");
	}
	while (n < 1);

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
		for (j = 0; j <= i; j++)
		{
			printf("#");
		}

		// Move to the next line after each row
		printf("\n");
	}

	return 0;
}

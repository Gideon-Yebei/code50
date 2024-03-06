#include <cs50.h>
#include <math.h>
#include <stdio.h>

/**
 * Gets a positive integer from the user.
 *
 * @return The positive integer entered by the user.
 */
int get_positive_int(void);

/**
 * Calculates the minimum number of coins needed to make change.
 *
 * @param cents The amount of change in cents.
 * @return The minimum number of coins needed.
 */
int calculate_coins(int cents);

int main(void)
{
	// Get change owed input from the user
	int change = get_positive_int();

	// Calculate and print the minimum number of coins needed
	int coins = calculate_coins(change);
	printf("%d\n", coins);

	return 0;
}

int get_positive_int(void)
{
	int n;
	do
	{
		n = get_int("Change owed: ");
	} while (n < 0);

	return n;
}

int calculate_coins(int cents)
{
	// Array of coin denominations
	int coins[] = {25, 10, 5, 1};

	// Initialize counter for coins
	int count = 0;

	// Iterate through each coin denomination
	int i;
	for (i = 0; i < 4; i++)
	{
		// Count the number of coins of each denomination needed
		count += cents / coins[i];
		cents %= coins[i];
	}

	return count;
}

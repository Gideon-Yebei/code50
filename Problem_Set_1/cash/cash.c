#include <cs50.h>
#include <math.h>
#include <stdio.h>

int get_positive_int(void);
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

// Function to get a positive integer from the user
int get_positive_int(void)
{
    int n;
    do
    {
        n = get_int("Change owed: ");
    }
    while (n < 0);

    return n;
}

// Function to calculate the minimum number of coins needed
int calculate_coins(int cents)
{
    // Array of coin denominations
    int coins[] = {25, 10, 5, 1};

    // Initialize counter for coins
    int count = 0;

    // Iterate through each coin denomination
    for (int i = 0; i < 4; i++)
    {
        // Count the number of coins of each denomination needed
        count += cents / coins[i];
        cents %= coins[i];
    }

    return count;
}

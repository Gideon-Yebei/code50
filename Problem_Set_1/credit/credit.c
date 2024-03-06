/**
 * @file credit.c
 * @brief This program validates a credit card number using Luhn's algorithm and identifies the card type.
 */

#include <cs50.h>
#include <stdio.h>

// Function prototypes
long long get_credit_card_number(void);
int calculate_length(long long number);
void identify_card_type(long long number);

int main(void)
{
	// Get user input for credit card number
	long long credit_card_number = get_credit_card_number();

	// Calculate the length of the credit card number
	int length = calculate_length(credit_card_number);

	// Check if the credit card number has a valid length
	if (length != 13 && length != 15 && length != 16)
	{
		printf("INVALID\n");
		return 0;
	}

	// Identify the card type
	identify_card_type(credit_card_number);

	return 0;
}

/**
 * @brief Prompts the user to enter a valid credit card number.
 * @return The valid credit card number entered by the user.
 */
long long get_credit_card_number(void)
{
	long long number;
	do
	{
		number = get_long("Number: ");
	}
	while (number <= 0);

	return number;
}

/**
 * @brief Calculates the length of a number.
 * @param number The number for which the length needs to be calculated.
 * @return The length of the number.
 */
int calculate_length(long long number)
{
	int length = 0;
	while (number > 0)
	{
		number /= 10;
		length++;
	}
	return length;
}

/**
 * @brief Identifies the card type using Luhn's algorithm and prints the result.
 * @param number The credit card number to be identified.
 */
void identify_card_type(long long number)
{
	// Convert the credit card number to an array of digits
	int length = calculate_length(number);
	int digits[length];
	long long temp = number;
	int i;

	for (i = length - 1; i >= 0; i--)
	{
		digits[i] = temp % 10;
		temp /= 10;
	}

	// Perform Luhn's algorithm to check the validity of the credit card number
	int sum = 0;
	for (i = 0; i < length; i++)
	{
		if (i % 2 == 0)
		{
			sum += digits[i];
		}
		else
		{
			int doubled_digit = digits[i] * 2;
			sum += doubled_digit % 10 + doubled_digit / 10;
		}
	}

	// Check if the checksum is valid and identify the card type
	if (sum % 10 == 0)
	{
		int first_digit = digits[length - 1];
		int second_digit = digits[length - 2];

		if (length == 15 && (first_digit == 3 && (second_digit == 4 || second_digit == 7)))
		{
			printf("AMEX\n");
		}
		else if (length == 16 && first_digit == 5 && (second_digit >= 1 && second_digit <= 5))
		{
			printf("MASTERCARD\n");
		}
		else if ((length == 13 || length == 16) && first_digit == 4)
		{
			printf("VISA\n");
		}
		else
		{
			printf("INVALID\n");
		}
	}
	else
	{
		printf("INVALID\n");
	}
}

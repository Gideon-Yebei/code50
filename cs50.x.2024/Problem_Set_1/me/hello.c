#include "cs50.h"
#include <stdio.h>

/**
 * Asks the user for their name and prints a greeting message.
 *
 * @return 0 if the program executed successfully.
 */
int main(void)
{
	string name = get_string("What's your name? ");
	printf("Hello, %s\n", name);
	return 0;
}

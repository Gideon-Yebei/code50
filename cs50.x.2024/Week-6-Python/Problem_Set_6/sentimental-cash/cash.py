from cs50 import get_float


def main():
    # Prompt user for change
    while True:
        dollars = get_float("Change owed: ")
        if dollars > 0:
            break
    # Convert dollars to cents
    cents = round(dollars * 100)
    # Calculate number of coins
    quarters = cents // 25
    dimes = (cents % 25) // 10
    nickels = ((cents % 25) % 10) // 5
    pennies = ((cents % 25) % 10) % 5
    # Print number of coins
    print(quarters + dimes + nickels + pennies)


if __name__ == "__main__":
    main()

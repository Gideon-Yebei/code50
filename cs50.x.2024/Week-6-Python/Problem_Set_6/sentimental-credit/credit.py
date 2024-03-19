from cs50 import get_string


def main():
    # Prompt user for credit card number
    while True:
        card_number = get_string("Number: ")
        if card_number.isdigit():
            break
    # Check if card number is valid
    if is_valid(card_number):
        print(get_card_type(card_number))
    else:
        print("INVALID")


def is_valid(card_number):
    # Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.
    # Add the sum to the sum of the digits that weren’t multiplied by 2.
    # If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!
    # Initialize sum
    sum = 0
    # Initialize flag
    alternate = False
    # Iterate over card number digits
    for i in range(len(card_number) - 1, -1, -1):
        digit = int(card_number[i])
        if alternate:
            digit *= 2
            if digit > 9:
                digit -= 9
        sum += digit
        alternate = not alternate
    # Check if sum’s last digit is 0
    return sum % 10 == 0


def get_card_type(card_number):
    # Check if card number is American Express
    if len(card_number) == 15 and (card_number[:2] == "34" or card_number[:2] == "37"):
        return "AMEX"
    # Check if card number is MasterCard
    elif len(card_number) == 16 and 51 <= int(card_number[:2]) <= 55:
        return "MASTERCARD"
    # Check if card number is Visa
    elif (len(card_number) == 13 or len(card_number) == 16) and card_number[0] == "4":
        return "VISA"
    # Return card type
    return "INVALID"


if __name__ == "__main__":
    main()

from cs50 import get_string


def main():
    # Prompt user for text
    text = get_string("Text: ")
    # Count number of letters
    letters = count_letters(text)
    # Count number of words
    words = count_words(text)
    # Count number of sentences
    sentences = count_sentences(text)
    # Calculate Coleman-Liau index
    index = calculate_index(letters, words, sentences)
    # Print grade level
    if index < 1:
        print("Before Grade 1")
    elif index >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {index}")


def count_letters(text):
    # Initialize counter
    count = 0
    # Iterate over characters in text
    for c in text:
        if c.isalpha():
            count += 1
    # Return counter
    return count


def count_words(text):
    # Initialize counter
    count = 1
    # Iterate over characters in text
    for c in text:
        if c.isspace():
            count += 1
    # Return counter
    return count


def count_sentences(text):
    # Initialize counter
    count = 0
    # Iterate over characters in text
    for c in text:
        if c in [".", "!", "?"]:
            count += 1
    # Return counter
    return count


def calculate_index(letters, words, sentences):
    # Calculate L
    L = (letters / words) * 100
    # Calculate S
    S = (sentences / words) * 100
    # Calculate Coleman-Liau index
    index = 0.0588 * L - 0.296 * S - 15.8
    # Return index
    return round(index)


if __name__ == "__main__":
    main()

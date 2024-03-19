from cs50 import get_int


def print_pyramid(n):
    for i in range(n):
        print(" " * (n - i - 1), end="")
        print("#" * (i + 1))


def main():
    n = -1
    while n < 1 or n > 8:
        n = get_int("Height: ")
    print_pyramid(n)


if __name__ == "__main__":
    main()

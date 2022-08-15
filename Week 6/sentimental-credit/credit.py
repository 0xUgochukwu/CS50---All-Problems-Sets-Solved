# TODO

from cs50 import get_int

# Getting the card Number from the user
cardNumber = get_int("Number: ")

x = cardNumber
sum1 = 0
sum2 = 0


while True:
    # Getting Every digit
    mod1 = x % 10
    x //= 10
    sum1 += mod1

    # Getting every other digit
    mod2 = x % 10
    x //= 10

    # Multiblying every other digit by two and adding each digit together
    mod2 = mod2 * 2
    d1 = mod2 % 10
    d2 = mod2 // 10
    sum2 = sum2 + d1 + d2

    # Check if card numbers are exhausted
    if x <= 0:
        break

# Totaling the two sums
total = sum1 + sum2

# Counting how many numbers are in the card
card

if (count != 13 and count != 15 and count != 16):
    print("INVALID")
else:
    if total % 10 != 0:
        print("h INVALID")
    else:
        start = cardNumber

        while True:
            start //= 10
            if start < 100:
                break

        if start // 10 == 5 and start % 10 in range(1, 5):
            print("MASTERCARD")
        elif start // 10 == 3 and (start % 10 == 4 or start % 10 == 7):
            print("AMEX")
        elif  start // 10 == 4:
            print("VISA")
        else:
            print("INVALID")



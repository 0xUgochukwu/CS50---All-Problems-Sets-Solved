# TODO

from cs50 import get_int

cardNumber = get_int("Number: ")

x = cardNumber
sum1 = 0
sum2 = 0

while True:
    mod1 = x % 10
    x //= 10
    sum1 += mod1

    mod2 = x % 10
    x //= 10

    mod2 = mod2 * 2
    d1 = mod2 % 10
    d2 = mod2 // 10
    sum2 = d1 + d2

    if x <= 0:
        break

total = sum1 + sum2

count = 0
cc = cardNumber

while cc > 0:
    cc //= 10
    count += 1

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



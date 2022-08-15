# TODO

from cs50 import get_int

cardNumber = get_int("Number: ")

cardNumber = x
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


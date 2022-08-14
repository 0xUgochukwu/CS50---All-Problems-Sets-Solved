# TODO
from cs50 import get_float

# Initialize coins

coins = 0

# Prompt user for the amount

while True:
    amount = round(int(get_float("How many cents? ")))
    if amount > 0:
        break


# find out how many coins

while amount > 0:
    while amount >= 25:
        coins += 1
        amount -= 25
    while amount >= 10:
        coins += 1
        amount -= 10
    while amount >= 5:
        coins += 1
        amount -= 25
    while amount >= 1:
        coins += 1
        amount -= 1


print(coins)

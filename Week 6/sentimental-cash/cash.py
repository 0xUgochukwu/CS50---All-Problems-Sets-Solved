# TODO
from cs50 import get_float

# Initialize coins

coins = 0

# Prompt user for the change

while True:
    change = get_float("Change Owed: ")
    if change > 0:
        break

# Convert the amount to cents
cents = round(int(change * 100))

# find out how many coins

while cents > 0:
    while cents >= 25:
        coins += 1
        cents -= 25
    while cents >= 10:
        coins += 1
        cents -= 10
    while cents >= 5:
        coins += 1
        cents -= 25
    while cents >= 1:
        coins += 1
        cents -= 1


print(coins)

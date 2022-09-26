# TODO
import cs50

def main():
    while True:
        change = cs50.get_float("Change owed: ")
        if (change > 0):
            break

    quarters = calculate_quarters(change)
    change = round(change - (quarters * 0.25), 2)

    dimes = calculate_dimes(change)
    change = round(change - (dimes * 0.10), 2)

    nickels = calculate_nickels(change)
    change = round(change - (nickels * 0.05), 2)

    pennies = calculate_pennies(change)
    change = round(change - (pennies * 0.01), 2)

    coins = quarters + dimes + nickels + pennies

    print(coins)

def calculate_quarters(change):
    count = 0

    while (change >= 0.25):
        count+=1
        change = round(change - 0.25, 2)

    return count

def calculate_dimes(change):
    count = 0

    while (change >= 0.10):
        count+=1
        change = round(change - 0.10, 2)

    return count

def calculate_nickels(change):
    count = 0

    while (change >= 0.05):
        count+=1
        change = round(change - 0.05, 2)

    return count

def calculate_pennies(change):
    count = 0

    while (change >= 0.01):
        count+=1
        change = round(change - 0.01, 2)

    return count

if __name__ == "__main__":
    main()

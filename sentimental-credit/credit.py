# TODO
def main():
    cardnumber = int(input("Number: "))

    length = 0
    cardarray = list()

    while(cardnumber != 0):
        remainder = cardnumber % 10
        cardarray.append(remainder)
        cardnumber = cardnumber // 10
        length += 1

    sum = checksum(cardarray, length)

    if (sum):
        if (cardarray[length-1] == 4 and length in [13,16]):
            print("VISA")
            return 0

        elif (cardarray[length-1] == 3 and cardarray[length-2] in [4,7] and length == 15):
            print("AMEX")
            return 0

        elif (cardarray[length-1] == 5 and cardarray[length-2] in [1,2,3,4,5] and length == 16):
            print("MASTERCARD")
            return 0

    print("INVALID")
    return 0

def checksum(cardarray, length):
    sum = 0
    for i in range(1, length, 2):
        element = cardarray[i] * 2
        while element != 0:
            sum += (element % 10)
            element //= 10

    for i in range(0, length, 2):
        sum += cardarray[i]

    if sum % 10 == 0:
        return True
    else:
        return False

if __name__ == "__main__":
    main()


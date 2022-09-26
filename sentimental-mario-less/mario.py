# TODO

def main():

    height = 0
    while (height <= 0 or height >= 9):
        try:
            height = int(input("Height : "))
        except:
            print("Enter an integer from 1 to 8")

    for i in range(1, height+1):
        blankspaces = height - i
        print(" " * blankspaces, end = "")
        print("#" * i, end = "")
        print()

if __name__ == "__main__":
    main()
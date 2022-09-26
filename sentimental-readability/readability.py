# TODO
import cs50

def main():
    phrase = cs50.get_string("Text : ")

    numltrs = count_letters(phrase)
    numwords = count_words(phrase)
    numsens = count_sentences(phrase)

    L = (numltrs/numwords) * 100
    S = (numsens/numwords) * 100

    index = round((0.0588 * L) - (0.296 * S) - 15.8)

    if index <= 0:
        print("Before Grade 1")
    elif index >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {index}")

def count_letters(phrase):
    count = 0
    for i in phrase:
        if (i.isalpha()):
            count += 1
    return count

def count_words(phrase):
    count = 0
    for i in phrase:
        if (i == " "):
            count += 1
    count += 1
    return count

def count_sentences(phrase):
    count = 0
    for i in phrase:
        if i == '.' or i == '!' or i == '?':
            count += 1
    return count

if __name__ == "__main__":
    main()

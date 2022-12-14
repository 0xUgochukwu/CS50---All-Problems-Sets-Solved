# TODO

from cs50 import get_string
import re


def main():
    text = get_string("Text: ")
    letters = count_letters(text)
    words = count_words(text)
    sentences = count_sentences(text)

    L = (letters / words) * 100
    S = (sentences / words) * 100

    index = round(0.0588 * L - 0.296 * S - 15.8)

    if index < 1:
        print("Before Grade 1")
    elif index >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {index}")


def count_letters(text):
    letters = 0

    for i in text:
        if i.isalpha():
            letters += 1

    return letters


def count_words(text):
    words = text.split()

    return len(words)


def count_sentences(text):
    sentences = re.split(r'[.!?]+', text)

    return len(sentences) - 1


if __name__ == '__main__':
    # This code won't run if this file is imported.
    main()
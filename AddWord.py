#! /bin/python3

import pyperclip

path = "/home/KicamonIce/Documents/study/Note/English/MyWords.txt"
NewWord = pyperclip.paste()


def write_word(path, newword):
    path += "/MyWords.txt"
    with open(path, 'a+') as f:
        f.writelines(newword)


write_word(path, f"{NewWord}.<++>.1.")

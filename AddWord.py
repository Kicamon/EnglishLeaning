#! /bin/python3

import pyperclip

path = "/home/KicamonIce/Documents/project/cpp/English study"
NewWord = pyperclip.paste()


def write_csv(path, newword):
    path += "/MyWords.txt"
    with open(path, 'a+') as f:
        f.writelines(newword)


write_csv(path, f"{NewWord}.<++>.1.")

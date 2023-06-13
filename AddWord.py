#! /bin/python3

import pyperclip

path = "/home/KicamonIce/Documents/study/Note/English"
NewWord = pyperclip.paste()


def write_word(path, newword):
    path += "/MyWords.txt"
    with open(path, "r") as f:
        line = f.readline()
        while line:
            hadword = ""
            for char in line:
                if char == '|':
                    break
                hadword += char
            if hadword == newword:
                return
            line = f.readline()
    addstr = f"{newword}|<++>|1|"
    with open(path, 'a+') as f:
        f.writelines(addstr+'\n')


write_word(path, NewWord)

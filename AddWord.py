#! /bin/python3

import csv
import pyperclip

path = "~/Documents/project/cpp/English study"
NewWord = pyperclip.paste()


def write_csv(path, csv_head):
    path += "/MyWords.csv"
    with open(path, 'a+') as f:
        f.writelines(csv_head)


write_csv(path, f"{NewWord}.<++>.1.")

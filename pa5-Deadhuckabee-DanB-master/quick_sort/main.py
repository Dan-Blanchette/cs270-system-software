#!/usr/bin/env python3
# Dan Blanchette
# CS-270
# quick sort and binary search part 2B

# Acknowledgements: For removing encoding='uft-8-sig' 
# https://stackoverflow.com/questions/53187097/how-to-read-file-in-python-withou-ufef

from quicksrt import quickSort
from binSearch import binarySearch
from PyDictionary import PyDictionary


def main():
    dictionary = PyDictionary()
    choice = True
    # Read all the words in words_notsorted.txt into a list 
    # encoding call removes /uffef byte order mark from the file importing process
    # which was causing the first line entry of the file to be incorrectly sorted
    # to the end of the list.
    with open("words_notsorted.txt", encoding='utf-8-sig') as fileIn:
        wList = []
        for words in fileIn:
            wList.append(words.rstrip())
    
    # sort the list of words by passing it to the sorting function
    n = len(wList)
    quickSort(wList, 0, n-1)
    choice = ['']
    # loop until user wants to exit
    while True:
        # ask user to enter a word
        uInput = input("please enter a word: ")
        searchWord = ""
        searchWord = uInput
        # search the word in the list using binary search
        binarySearch(wList, 0, len(wList)-1, searchWord)
        # if word is found in the list
        results = binarySearch(wList, 0, len(wList)-1, searchWord)
        if results != -1:
            # write the code:
            print(dictionary.meaning(searchWord))
            choice = input("Would you like to continue?\nEnter (1) for Yes\nor any key to continue: ")

            if choice == '1':
                print("The Program has exited successfully")
                break
            else:
                pass

        else:
            # prompt user, word not found
            print("Error: word was not found on the list")
            choice = input("Would you like to continue?\nEnter (1) for Yes\nor any key to continue: ")

            if choice == '1':
                print("The Program has exited successfully")
                break
            else:
                pass
            # exit out of the loop if user wants to stop
if __name__ == "__main__":
    main()
#!/usr/bin/env python3
import random
import sys
from selectsrt import selectionSort


def main():
    # Generate 1000 random numbers between 10 and 11500
    randomlist = random.sample(range(10, 11500), 1000)
    print(randomlist)
    
    # sort randomlist by passing it to the sorting function
    selectionSort(randomlist)
    # loop through each item in the list and print one item per line
    for i in range(len(randomlist)):
        print(randomlist[i])
if __name__ == "__main__":
    main()
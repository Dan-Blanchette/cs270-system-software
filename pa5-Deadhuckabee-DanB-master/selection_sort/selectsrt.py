#!/usr/bin/env python3
#definiton for the selection sort function
def selectionSort(list):
    # read through the list to the last element
    for i in range(len(list)):
        # the minIndex will be equal to the value of the list index iterator i.
        # it will be used for index comparions in the following loop.
        minIndex = i
        # loop through the contents of the list again starting with j at index 1 
        # of the list and esure that the bounds of the list are not exceeded. 
        # loop until the end of the list.
        for j in range(i+1, len(list)):
            # if the contents of the list index being evauluated by the previous
            # loop are greater than the list's index value at j's position,
            if list[minIndex] > list[j]:
                # assign the larger number in j's position overwriting the minIndex variable's value
                minIndex = j
        # list contents at position i and position minIndex = j are then swapped
        list[i], list[minIndex] = list[minIndex], list[i]

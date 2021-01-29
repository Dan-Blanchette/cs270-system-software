#!/usr/bin/env python3

def partition(list, start, end):
    # startInd = start index
    startIndex = (start-1)
    # pivot is postioned at the last array element
    pivot = list[end]
    # partition the array starting with the last element
    for i in range(start, end):
        # if the current element is less than or equal to the current pivot
        if list[i] <= pivot:
            # start index moves up one position and is swapped with the current element position in the list.
            startIndex = startIndex+1
            list[startIndex], list[i] = list[i], list[startIndex]
    # swap the element contents with the pivot's postion
    list[startIndex+1], list[end] = list[end], list[startIndex+1]
    # return the current position of the starting index
    return (startIndex+1)

def quickSort(list, start, end):
    if len(list) == 1:
        return list
    # sort each element seperately before and after each partition
    if start < end:
        # calls partition which sets the pivot position
        part_Index = partition(list, start, end)
        # swap pivot with the element in the list 
        quickSort(list, start, part_Index-1)
        quickSort(list, part_Index+1, end)
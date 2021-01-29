#!/usr/bin/env python3

# Dan Blanchette
# CS-270
# quick sort and binary search part 2B

# binary search program
def binarySearch(list, l_array, r_array, index):
    # checking the base case
    if r_array >= l_array:
        middle = (r_array + l_array) // 2
    
        if list[middle] == index:
            return middle

        elif list[middle] > index:
            return binarySearch(list, l_array, middle - 1, index)
    
        else:
            return binarySearch(list, middle + 1, r_array, index )
    else:
        return -1
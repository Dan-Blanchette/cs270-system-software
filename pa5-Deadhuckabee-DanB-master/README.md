# PA5: Python Programming (100 pts)

## Learner Objectives
At the conclusion of this programming assignment, participants should be able to:
* Write Python scripts

## Prerequisites
* Understanding of the lessons taught on Python Programming

## Acknowledgements
Content used in this assignment is based upon information in the following sources:
* Linux for Programmers and Users by Glass and Ables
* Generating random number list in Python, [tutorialspoint.com](https://www.tutorialspoint.com/generating-random-number-list-in-python)

## Program Details

### Task 1 - Write **`junk.py`** using Python Programming (50 pts)
* Write a utility called **`junk`** that satisfies the following specification:

*Utility:* **`junk`** [-l] [-p] { *fileName }\*

**`junk`** is a replacement for the **`rm`** utility. Rather than removing files, it moves them into the subdirectory **.junk** in your **home directory**. If **.junk** doesn't exist, it is automatically created. The **`-l`** option lists the current contents of the **.junk** directory, and the **`-p`** option purgest **.junk**.

Here's an example of **`junk`** at work:
```bash
$ ls -lG
-rw-r--r-- 1 gvdelacruz   18 Sep 17 14:24 README.md
-rw-r--r-- 1 gvdelacruz   18 Sep 17 14:24 a.txt
$ junk README.md
$ ls -lG README.md
ls: cannot access 'README.md': No such file or directory
$ junk.py a.txt
$ junk.py -l
-rw-r--r-- 1 gvdelacruz   18 Sep 17 14:24 README.md
-rw-r--r-- 1 gvdelacruz   18 Sep 17 14:24 a.txt
$ junk.py -p
$ junk.py -l
```


### Task 2 - Write two Sorting Algorithms and Binary Search in Python (50 pts)
> **Important Note**: Refrain yourself from the looking online when solving this. You will not learn if you copy codes online. Look at reference manuals, not solutions.

I will encourage to utilize the Python Interpreter. I think this is one of the advantages of Python over C++, the ability to test a line of code on the fly. Especially that you are learning a new language, the interpreter can quickly tell you if the code is valid or invalid.

#### Task 2A (15 pts):
* Pick 1 From This List:
    * Bubble Sort
        * How does it work?
            * Move the HIGHER valued elements towards the right and LOWER elements towards the left.
            * One the first pass, the highest element bubbles to the end
            * Repeat until its sorted
        * If you forgot how this works, watch this [video](https://www.youtube.com/watch?v=RT-hUXUWQ2I&feature=youtu.be)
    * Selection Sort
        * How does it work?
            * The smallest value in the array is located and moved to element 0
            * The next smallest value is located and moved to element 1.
            * Process continues until all the elements have been placed in their proper order.
        * If you forgot how this works, watch this [video](https://www.youtube.com/watch?v=3hH8kTHFw2A&feature=youtu.be)
    * Insertion Sort
        * How does it work?
            * Consider the first element to be automatically in the sorted portion of the list
            * Look at the next element in the array and determine where it fits in the sorted list
            * Repeat steps
        * If you forgot how this works, watch this [video](https://www.youtube.com/watch?v=O0VbBkUvriI&feature=youtu.be)

        
    
* Use the code below as the starter code. The `randomlist` is a list of random numbers, sort this list using one of the sorting algorithms above. 
* You MUST write the sorting algorithm in a separate function

```python
import random

def main():
    # Generate 1000 random numbers between 10 and 11500
    randomlist = random.sample(range(10, 11500), 1000)
    print(randomlist)
    
    # sort randomlist by passing it to the sorting function
    
    # loop through each item in the list and print one item per line
    
if __name__ == "__main__":
    main()
```

#### Task 2B Sort and Search (35 pts):
* Pick 1 From This List:
    * Mergesort
        * Watch this [video](https://www.youtube.com/watch?v=Ns7tGNbtvV4&list=PLhQjrBD2T381k8ul4WQ8SQ165XqY149WW&index=36)
    * Quicksort
        * Watch this [video](https://www.youtube.com/watch?v=kUon6854joI)

* Using the instructions in the lecture notes, install the [`PyDictionary`](https://pypi.org/project/PyDictionary/) python package in your computer using `pip3`. This Python package gets definitions online for a word and returns it as a Python dictionary.
* You MUST write the sorting algorithm in a separate function
* You MUST write the binary search in a separate function

```python
from PyDictionary import PyDictionary

def main():
    dictionary = PyDictionary()
   
    # Read all the words in words_notsorted.txt into a list
    
    # sort the list of words by passing it to the sorting function
    
    # loop until user wants to exit
        # ask user to enter a word
        searchWord = ""
    
        # search the word in the list using binary search
    
        # if word is found in the list
        #    write the code:
        #    print(dictionary.meaning(searchWord))
        # else
        #    prompt user, word not found
        
        # prompt user if they want to exit?
        # exit out of the loop if user wants to stop
    
    
if __name__ == "__main__":
    main()
```


## Submitting Assignments
* It is VERY IMPORTANT that besides pushing the code to GitHub that you still submit the GitHub URL of this lab assignment in Canvas. This allows the instructor to be notified of your final submission.

> **_NOTE: By submitting your code to be graded, you are stating that your submission does not violate the Academic Integrity Policy outlined in the syllabus._**

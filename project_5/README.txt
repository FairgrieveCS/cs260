Jonathan Fairgrieve
CS 260
Project 5

For my assignment 5 I went with an array based list. For a linked-list
sorted list, you can create a linked list node class and insert values in the correct 
position by traversing the list and comparing values as you go through.
To search, you can use a similar approach as the binary search, but to traverse
the list you would use pointers to compare values

Insert method: lines 15-28
Search method: lines 31-46
tests (main function): lines 48-72

The time complexity of the insert method is O(n)

The time complexity of the search method is O(log n)

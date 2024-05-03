This is the infamous two sum problem.

Create a program that can read an arbitrary text file

Format is first row contains target integer

2nd row is empty

3rd row to the rest makes up array of integers (we can call it nums)

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.



Text field should contain the answer in form of 0 based indexes for the file given for example 342,468

Submit code

Grading:

40% for brute force O(n*n) code - you could do this in week 1 right ?

70% for O(n log n)

100% for O(n) solution - hint it involves data structure that utilizes hashing

//COmment your code , add links to sources if you use existing ones

---

#### O(n) solution in python:
```python3
def two_sum_hash_table():
    """ An O(n) approach. """
    nummies = {}
    # Iterate over nums while looking up the hashmap if the complement exists
    for i, num1 in enumerate(nums):
        num2 = target - num1
        if num2 in nummies and nummies[num2] != i:
            return i, nummies[num2]
        # Fill the hashmap as explore the numbers
        nummies[num1] = i
```
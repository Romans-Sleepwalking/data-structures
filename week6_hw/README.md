Read the included 2d.csv file - it is just a text file with comma used as a separator

First row can be ignored - those are just column names

1. Store the data in a dynamically allocated 2d array of integers - allocated with new

(if you use  regular/static 2d int array you will only get 70% maximum for this assignment).

2. First task is to find the minimum value in the first column.

3. Second task is to find the arithmetic mean in the second column with precision up to 2 digits after comma.

4. Third task is to find the population standard deviation in the third column again with precision up to 2 digits after comma

If you've forgotten the formula: https://www.khanacademy.org/math/statistics-probability/summarizing-quantitative-data/variance-standard-deviation-sample/a/population-and-sample-standard-deviation-review is a nice refresher

5. remember to clear the dynamically allocated memory.



Submit answers in the text field, for example 42, 5075.32, 2759.62 (not correct :) )

Submit also the source code file main.cpp .

PS You can use any library you want, if you use something not part of standard library you must submit also the appropriate library headers and .cpp files (in zip )

PSS You are allowed to check your program correctness using any other programming language or software (Python Pandas, Excel etc)

---

Checked in the notebook:
1. Minimum value in A - 206
2. Mean average value in B - 5331.04
3. Standard deviation in C - 2674.30
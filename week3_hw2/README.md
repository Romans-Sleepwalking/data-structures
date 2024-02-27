The city has a known population p0

A percentage of population perc is added each year

Every year a certain number of delta also arrive (or leave)

We need to know when (if at all) the city will reach a population of p



Write a function getCityYear (int p0, double perc, int delta, int p) that returns the years (full) when p is reached.



If p cannot be reached, then we return -1



Example:



getCityYear (1000,2,50,1200) -> 3

1000 + 1000 * 0.02 + 50 => 1070 after the 1st year

1070 + 1070 * 0.02 + 50 => 1141 after the 2nd year

1141 + 1141 * 0.02 + 50 => 1213 after the 3rd year

so the function here returns 3 and is done



PS. Note that we give perc as a percentage to be converted to a decimal number.



More test examples:

getCityYear(1000, 2, -50, 5000) -> -1

getCityYear(1500, 5, 100, 5000) -> 15


1. In the text field submit answer to following two function calls

getCityYear(1500000, 2.5, 10000, 2'000'000)

getCityYear(1000, -3, 50, 2000)

For example (15, 3)

2. In file field submit main.cpp with your function (student name and id on first line of comments as usual)
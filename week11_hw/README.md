In https://en.wikipedia.org/wiki/The_Adventure_of_the_Dancing_Men Sherlock Holmes was able to decrypt a number of secret messages partially aided by the knowledge of letter frequency in English language at the time.

Write a program that ideally can read any text file (file name would be passed as the first command line argument)

The program would ideally output all unicode symbol frequencies in .tsv (tab separated format) where first row is symbol\tcount - with \t representing tab,

2nd row would be the most frequent symbol - for example e\t5025

3rd row would be the 2nd most frequent symbol for example s\t4804

Ideally outgoing file name would be incoming_char_frequency.tsv



You can use any data structure in std::

You will get 70% of grade if your program works on ascii characters (up to 255)

For full 90% your program should be able to read UTF-8,

Tip: look into wstring and wchar_t

For full 100% your program should offer a command line flag option to lowercase all characters before counting. This means S and s would be be counted under s, A and a under a, etc.

Also there should be -i flag for input file, and -o for output

So full 100% program once compiled to your_prog binary would work as follows in CLI:

./your_prog -l -i somefile.txt -o somefile.csv

NOTE -l and -o flags should be optional. if no -l flag then characters are not changed before counting. If no -o flag, then output file is same name as input except it has .csv extension. In the example given -o flag was thus not necessary.

NOTE2: your output can also be .tsv (ie tab separated values), you can choose whichever you like better



Comment your code with explanations. Also provide sources if you use any!



In text field submit the 3 most frequent characters in text below: for example s - 350, e - 327, t - 321 (just an example)

In file field submit source code (main.cpp etc) AND dancing_men_char_frequency.tsv
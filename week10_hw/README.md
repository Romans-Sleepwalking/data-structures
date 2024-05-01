Write a program which is able to asks for file name

reads text file
correctly parse any simple arithmetic and parenthesis.
Output correct answer or error if unable to parse.
File length is up to 10k symbols

Any whitespace including newlines and tabs is to be ignored.

That is (5 \t  + 7)\n*6 is same as (5+7)*6





1. Minimal 40% requirements correctly understand + and -

File contains: 5+3-10+6

Program outputs: 4

User inputs: User inputs: 5+3-10++

Program outputs: error

User inputs: 5

Output: 5

User inputs: RBS

Output: error

2. For 80% grade implement support for unlimited number of parenthesis

Input: 10-(6+3)

Output: 1

Input: 10-(6+(3-2))

Output: 3


Input: 10-(6+3))

Output: error //can do custom error message as well for parenthesis




3. For 100% grade implement support for * and / as well as well as unlimited parenthesis!

Input: 2+3*10

Output: 32

Input: (2*(5-2)+2)*10

Output: 80

Input: 3+6/0

Output: nan



Limitations: You can use any standard data structure from the STL or write your own structs/classes

Hint: for 100% you might need something recursive to make your life easier

Hint: some tree like structure might help you out



SUBMIT: source code, text should contain answer to sequence with parenthesis.txt file evaluation
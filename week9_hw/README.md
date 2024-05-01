Write a program which is able to ask for and correctly parse any simple arithmetic and parenthesis.

Output correct answer or error if unable to parse.

Maximum input: 40 characters/symbols



1. Minimal 40% requirements correctly understand + and -

User inputs: 5+3-10+6

Program outputs: 4

User inputs: User inputs: 5+3-10++

Program outputs: error

User inputs: 5

Output: 5

User inputs: RBS

Output: error

2. For 70% grade implement support for single parenthesis

Input: 10-(6+3)

Output: 1

Input: 10-(6+3))

Output: error //can do custom error message as well for parenthesis




3. For 100% grade implement support for * and / as well

Note: for this assignment only one parenthesis can be open at a time - this makes things easier!

Also: you only have 40 symbols to worry about

Input: 2+3*10

Output: 32

Input: (2+3)*(10+2) //notice we open 2nd parenthesis after 1st one is closed

Output: 60

Input: 3+6/0

Output: nan

https://www.youtube.com/watch?v=7ha78yWRDlE

Limitations: You can use any standard data structure from the STL or write your own structs/classes

Hints: You might want to use some stack data structures to save operations and data

Hints: for highest grade without too much pain look into shunting yard algorithm

https://www.youtube.com/watch?v=Wz85Hiwi5MY

PS. In effect you will have written a partial interpreter for a language such as Python :)

SUBMIT: source code, text is optional
define a class Song

The class constructor needs to have additional  parameters

title defaults to empty string

author defaults to empty string

lyrics you can choose string but possibly some other data type

year - int can default to 0

you are allowed to use extra parameters if need be, for example how many lines song has



inside constructor method:

set/store these parameters inside objects variables of the same name

print on the screen "New Song made" - (try also printing here author and title!)

Minimum (70% of grade:

Write a member function(method in other languages) sing that prints the song line by line on the screen, first printing the author and title and year, if any.

Write a member function  yell that prints the song in capital letters line by line on the screen, first printing the author and title, if any.

15% of grade: make the above sing and chain methods chainable, so we can call them several times (chained)

15% of grade: create an additional parameter max_lines for member functions(yell and sing) that print only a certain number of lines for both sing and yell. Better do with some default value e.g. -1, at which all rows are then printed.

Create multiple songs with lyrics

Example:

auto ziemelmeita = Song("Ziemeļmeita", "Jumprava", "Gāju meklēt ziemeļmeitu\n
Garu, tālu ceļu veicu", 1988)

ziemelmeita.sing(1).yell() //chaining

Outputs:

Ziemeļmeita - Jumprava - 1988

Gāju meklēt ziemeļmeitu //notice only first line is printed because of sing(1)

Ziemeļmeita - Jumprava - 1988

GĀJU MEKLĒT ZIEMEĻMEITU

GARU, TĀLU CEĻU VEICU



//COMMENT YOUR CODE!

//Provide links to any sources used

Submit main.cpp (if you use more than one file, then zip them)

I'd love to see your own Song examples not just Jumprava. :)

Text field can be left blank or you can provide a link to your git repository

---

[source link](https://www.youtube.com/watch?v=dQw4w9WgXcQ)
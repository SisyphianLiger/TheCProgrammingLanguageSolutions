# TheCProgrammingLanguageSolutions
My Work solving the C Programming Language by Kernighan and Ritchie


Here you can read the descriptions of my answers to the assignments in the 
below section. There will be a make file on the top level. The make file 
will be able to execute binaries based on the assignment number. 

For example, in folder 1_1 there will be a bin file which will hold the 
compiled binaries. From the top level you can simply make 1_1 and it will 
no and run the output of 1_1 from the /bin folder.


# Chapter 1: A Tutorial Introduction
## 1.1 Hello World!
Some interesing things to note, the printf statement must always have a \n
to indicate a new line, and missing a semi-colon after the statement results 
in an error. Also, as displayed in the book, Hello World use three printf 
statements and appear as a syscall as one string 

## 1.2 Hello World with \c?
A Quick Excercise here to indicate issues with escape characters, namely that 
\c will not be compiled as it the compile detects is as an escape character, 
however, \\c would be work find to print \c

## 1.3 Write a Table over the Farenheit to Celcius Table 
Here we use Printf to print before the while loop, and then with some special 
formatting with | input | input | following by a print line of --------
we can make a table. 

## 1.4 Write the same table but as Celcius to Farenheit
This is again quite simple, with the main change being the switch in equation.
With a little algrebra we can express 

C = (5.0/9.0) + (F - 32) 
F = C / (5.0/9.0) + 32

And then switching the table info from 1.3

## 1.5 Reverse temperature conversion 300 degress to 0
I reuse the original code block from 1.3 which uses the F to C conversion and 
swap the start and stop variables names start and min (demarcating the decrement).
Finally, the decrement here is expressed with the -= operator once the calculation 
is made.

## 1.6 Verifying that getchar() != EOF is a 0 or 1 output
Interestingly enough a boolean value is represented by 0 or 1, 
the tricky part can be if a programmer does not seperate their function call 
from their boolean expression. As such the following code 

while(c = getchar() != EOF) {
    // logic here 
}

Will result in c being a 1 for all input as the boolean expression result is 
captured not the char and the expression returns false so long as we are not 
at the end of file (EOF)

Testing the variable with the char j
c = getchar() != EOF gives 
Verifying c is 0 or 1: 1

And c = getchar()
Verifying c1 is not 0 or 1: 10

## 1.7 Write a program to print the value of EOF
EOF is a part of the standard library and can defined as a Symbolic Constant.

https://man7.org/linux/man-pages/man3/EOF.3const.html

The program in 1.7 uses the description that the EOF is there is an error returns 
and int to print out the value of EOF, as such the result in code prints 
EOF == -1

## 1.8 Count blanks tabs and newlines
Sort of evolving from the EOF chapter we can now compare char's to their ASCII
counterparts, '\n' == newline, '\t' == tab, 32 == space to count within a series 
of chars the amount of times we see them. 

This program uses the getchar() method to do just that, and output's to the user 
after termination of the loop with cntrl-D.


## 1.9 Copy I/O to make extra blanks be gone
This one was a bit tricky at first, but only because my poor syntax.
In the while loop, you want to putchar to c whenever the following conditions 
occur. 

1. The space counter is not > 1 and we encounter a space
2. The char is not related to space 

That way the copied char returned will skip over spaces and return a copy of 
the char without extra spaces, but not getting rid of all spaces.

## 1.10 Copy its input output replaceing tab backspace with \\t and \\b

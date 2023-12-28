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



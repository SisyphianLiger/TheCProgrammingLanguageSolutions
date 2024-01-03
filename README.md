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
This one is a bit tricky as the OS of mac takes care of the backspace tab, 
from research online I can confirm that this solution is valid, and that if 
this file needed to read a text file with backspaces then they would be replaced.

Just like the previous answers we check each char in the text for three possible
answers, tab/backspace/forwardslash, and if we find them we replace them with 
their actual char representation. A tricky thing to note is that this means we 
must putchar the \ followed by the b/t// to show the user the replacement. 

## 1.11 Testing for the word count program 
In order to properly assess this bare bones file, we would need to find scenarious, 
where the newline character would not be read correctly. One idea for testing would 
be to read a Hello\nworld in text to see if it would be counted or not, another 
possible test case would be to see if multiple blank new lines are handled correctly.

## 1.12 Write a program that prints its input one word per line
This was quite a simple program, given that the only time we need to go down is,
when there is a " ", an tab, or a new line, we can use a if else chain to make 
it such that if we find those three breaks between words then we print a blank 
line, and else we print the char.

## 1.13 Write a program to print a histogram from the char word input length 
For this problem I wanted to make try to make an inverted histogram, i.e. a 
vertical graph. It took a bit of time to figure out, and it was definitely a 
write it down on paper solution. 

Putiing it down on paper I could see that I could simply flip the first for loop, 
and with that use the for loops value to compare to the element and check if the 
element in the array is less than or equal to the I value. We print * if this 
logic is met and otherwise we print ' '

## 1.14 Write a program to print a histogram for all printable char frequencies
Here I just decided to make the histogram horizontal both to do it the other way, 
but also just to see how it would look. Now, the prompt says to print a histogram 
of all frequencies, but if I am honest, that is a bit difficult presenting it, 
to human readable formats in you shell. 

So I took the following idea into consideration, we should find printable chars, 
if we do, we can store them in an array, we know for example that there are 95 
characters in total, and that there is an integer representation of the 
chars, in question. Thus, for any char not in the range of we ignore it, then to 
add the sequence of chars in order I create a symbolic constant that subtracts,
the difference of the char to it's index, i.e. if char == 32, 32 - 32 == 0, add 
increment the char at arr[c - ASCIISTART]++.

The final step is to again print out the array, accounting for a difference in 
the x access of + 2,  where 0 displays the char and 1 displays a seperator. 

The result is a histogram that counts all instances of printable chars to the 
terminal.

## 1.15 Rewrite the temperature conversion program in section 1.2 with a function 
This was relatively simple, if you know how functions work. Given it did not 
specifiy to put the function in a different file the solution was to take, 
the original function allow for parameters to be accepted, i.e. start, stop, limit, 
and calculate the values. Given this is a sys call, and there is no return value, 
the function has the type void signifying no expression return. 

## 1.16 Revise the main routine of longest ine to print as much of the possible text
Ok, this was relatively difficult, and testing this code leads to a bus error, 
after multiple inputs from the solutions on KnR. But at least, the logic is as 
followed. We need to modify the getline char line such that it does not cause 
a buffer overflow. To do this when adding the char to the maxvalue, we set a 
limit point equal to i < limit - 2, where we reserve 2 slots, one for the 
new line character and one for the null terminator...

So, you can just check the book solutions for this code, but I just want to be 
honest here and say I did not get what the prompt wanted us to do, and did not 
realize we could modify any of the functions, (sounded like we could only 
modify the main loop...so great to know! But probably not the best assignment.

## 1.17 Write a Program to print all input lines that are longer than 80 chars
This program was quite simple. From the example, with some modifications I was 
able to use the len of get line to check if the length of incoming input was 
greater than 80 (in my case 20 because 80 is a lot of chars). If there was
update it printed out the current max, then at the end of the program, it 
prints out the total max and it's string output!

## 1.18 Write a program removing trailing blanks and tabs from each line of input, and delete entirely blank lines 
This one is a bit tricker but here is how I tackled the problem. Again using 
the copy and getline functions I did the following. 

For blank lines, which have len == 1 (because '\n'), we skip those.

For tabs, in the iteration, similar to 1.16, we can make sure that so long as
we add the j variable and not the iteration through the input, we can avoid tabs 
with a != '\t'

Lastly, we make sure to set the limit when i breaks to 3, this time, and check 
if there is a trailing whitespace, if so we increment j and go onto the next checks
where we add the '\n' and '\0' operator.

## 1.19 Write a function reverse(s) that reverses the character string s. Use it to write a program that reverses its input a line at a time.

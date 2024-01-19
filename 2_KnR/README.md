# Excercise 2-1
For Section 2.1 I simply used the limits library and worked with the print formatter,
to print all types, I excluded floats for now, but will add them later.

# Exercise 2-2
This problem was weirdly worded but I figured out that to not use and or statements nor 
a for loop, the program wanted a while loop, and conditional statements, i.e. if clauses. 
So, that is what I did, reformatted the for loop extracting the exit conditions out, and 
putting them into the while loop. 

# Exercise 2-3 htoi 
Here we advance our knowledge of the ASCII table converting hexidecimal numbers to
their integer values. With Hex you have to be aware of the distance from the char 
being represented to its number counter part. In other words 'a' is 97 and can be
represented by subtracting 87 from it's position. The integer value is thus 10.

But another issue this problem presents is the 0x or 0X front loading the problem 
states, has to be on hexidecimal numbers. My "fix" to this assuming that the hexidecimal
string coming in is a variation of 0xab 0Xab or ab or AB or Ab, is to use a obtain the 
length of the for loop then go backwards until the index is 0 or the we reach an X/x.

During this loop I calculate the add the current value n with it's power counterpart, i.e.
the hex coming in for calcluation. In theory this code could work for long hex strings, 
with an addition of skipping over spaces. 

# Excercise 2-4 Modify the sqeeze function to make string comparisons
This one took probably a lot longer than it should but here is the general solution.
I ended up using a double for loop. In the outer for loop I iterate through s[], and 
in the inner for loop the magic happens, I end up iterating through the c[], up until 
I meet the '\0' point. In the iterations I am checking if there is a match from string, 
to string. If so I then have a boolean flag is_matched that is switched on if 
is_matched is false. The if statement will then update the specified index, and out of 
the for loop the boolean flag is reset. The process continues until the entire string 
is compared. 

# Excercise 2-5 Write any(s1, s2) returns the first location in the string s1 where any 
# char from s2 occurs.
With some minor logic changing from 2-4 this was a pretty simple problem. Again just 
scan through all the possible letters in s2 to match s1, if we find a match in s1 we 
return i, else we have gone through the list and can return -1. 

One optimization would be to skip over the same letters in s2. 

# Exercise 2-6 
Write a function that returns x with the n bits that begin at position p set to the 
rightmost n bits of y, leaving the other bits unchanged
setbits(x,p,n,y);

so this problem is a bit more complicated until you realize that an integer is just 
and array of bits. So what do. Well first we have to find the location of p and n.
A slice if you will. Once we have that slice we can then mask it's vaues with y, 
and with an or gate add it's bits to x. 

# Excercise 2-7
Write a funciton invert(x,p,n) that returns x with the n bits that being at position p
inverted(i.e. changed into 0 and vice versa), leaving the others unchanged.
Taking the mask from 2-6 we can than use an xor on x to invert the range of bits 
we need.

# Excercise 2-8 
Write a function rightrot(x,n) that returns the value of the integer x rotated 
to the right by n bit positions.

Super simple, but there could be some flipping errors to watch out for, basically,
all we need here is a x >> n. But n could be greater than x so checking for that 
in production code may prevent bugs.



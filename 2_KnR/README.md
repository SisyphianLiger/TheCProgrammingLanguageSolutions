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



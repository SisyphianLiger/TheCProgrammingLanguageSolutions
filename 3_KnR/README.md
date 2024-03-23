# 3-1 
Our binary search makes two tests inside the loop, when one would suffice (at 
the price of more tests outside). Write a version with only one test inside the
loop and measure the difference in run-time.

So, while this is a optimization, having only one conditional check within the loop,
the acutaly results on my computer led to identical values. So, I can conclude, that 
the algorithmic measurement of LogN for binary search hold true.

# 3-2
Write a function escape(s, t) that converts characters like newline and tab 
into visible escape sequences like \n and \t as it copies the string t to s. 
Use a switch. Write a function for the other direction as well, converting 
escape sequences into the real characters.

With this problem, the tricky part was assessing the t was a copy output...
still not sure why it is called t. Of course in order to take in put to map out 
tabs and newlines, we must first copy all incoming text to s[]. Then, make a copy 
that handles '\n' and '\t' characters properly. Also I was today years old when 
I realized that a postfix operator allows for a read on variable before writing...
so yea...that was nice!


# 3-3
This problem is a bit janky, mainly because in theory s2 should be some random,
char array with a buffer...but I wanted to do it hard mode so I seperatated out 
the two functions into the finding the length needed from s1, and then expanding 
it. Reading the code it seems a tad redundant, and this is true, but the goal for
me was because I didn't have access to the heap I did not want to use it. 

Thus I get the length of s2 and use it to make a buffer that would fit exactly.
In order to keep track of the 0-9A-Za-z combinaitons, I put the char integer 
equivalents in an array, which in my case is then sorted. A hash map would probably
be the most ideal for this problem with K,V pair of K == first spot, and V == the 
two value ranges needed to expand the characters. 

All in all this was for me a difficult problem, but really expanded my knowledge 
of strings in C, and char * arrays. I will probably refactor the code, and this 
is not safe code by any means but was fun onto 3.4

# 3-4
The problem with this code is that when processing INT_MIN, the two's complement 
of INT_MIN does not have a positive equivalent. In order to solve this problem,
we can use the abs() function from the stdlib.h to make sure that when we use 
the modulus operator in our do portion of the do-while loop, that we are taking 
the positive value digit. The negation is presevered with the sign variable, and 
added at the end of the char array. Because we are adding numbers in reverse we 
must finally rerverse the string at the end of the function call. 

# 3-5 
This problem is a bit of an expansion of 3-4 now that we have a way to guarentee 
that there is no conflict with the two's complement. Given we have three route,
Binary, Octal and Hexidecimal, we need to take an integer, and divide them by 
there respective base cases, 2, 8, 16, and while doing so we take the absolute 
value of the number. That will leave us with an char array that once reversed
is the correct notation. Only binary has to have a negative number added to it.
Hexidecimal and Octal already represent there negative sign within their system.

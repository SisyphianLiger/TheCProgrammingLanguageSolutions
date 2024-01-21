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

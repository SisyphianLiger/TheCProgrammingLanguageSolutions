# 4_1

To solve this problem we break it down into branches, in brance 0, if we do not 
have a match, we move the char s[] string. Easy enough. When we have a match, if
the index of the char t[] string is 0, we record this information in a temporary 
variabl temp_pos. The variable stored is the s position or s_pos. Then if it is
the case that the next position of t is the null terminator reset the t position 
index, and then add the temporary position value to the position index. Finally,
for matches without the '\0' terminator, we simply increment the t_pos variable.

# 4_2
To solve this problem, the addition to processing the e6 or E-6 takes place after
we have the value. I.E. if we have the string 123.45, value will be 12345.0 at 
the time when we check if there is scientific notation involved. If there is,
then we enter a branch were we must then check again and overwrite sign, count 
the power digit after e to determine the power, and then return the equation, 

Floating Point Number = (sign of the number) * Mantissa * exponent

A mention about the exponent is that it is calculated by a power of 10. 

# 4_3











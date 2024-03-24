# 4_1

To solve this problem we break it down into branches, in brance 0, if we do not 
have a match, we move the char s[] string. Easy enough. When we have a match, if
the index of the char t[] string is 0, we record this information in a temporary 
variabl temp_pos. The variable stored is the s position or s_pos. Then if it is
the case that the next position of t is the null terminator reset the t position 
index, and then add the temporary position value to the position index. Finally,
for matches without the '\0' terminator, we simply increment the t_pos variable.

# 4_2


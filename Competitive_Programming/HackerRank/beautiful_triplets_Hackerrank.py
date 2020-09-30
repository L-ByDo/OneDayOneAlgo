num = list (map (int, input ().split ())) 
c = list (map (int, input ().split ())) 
d = num[1] 
gc = 0 
for i in range (num[0]):
    if c[i] + d in c and c[i] + 2 * d in c:
#if first number and it's additions are present
        gc += 1 
print (gc) 

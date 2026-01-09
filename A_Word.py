s = input()

low = 0 
high = 0

for i in range(0,len(s)):
    if(s[i] >= 'a' and s[i] <= 'z'):
        low+=1
    else:
        high+=1

if(low<high):
    print(s.upper())
else:
    print(s.lower())

    

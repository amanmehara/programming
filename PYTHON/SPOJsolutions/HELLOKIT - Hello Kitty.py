def rotate(wrd,n):
	

s = input()
n = int(s.split()[1])
s = s.split()[0]
s = s*n
#print(s)
for x in range(1,len(s)):
	print(rotate(s,x))

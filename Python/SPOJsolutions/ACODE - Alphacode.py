#http://stackoverflow.com/questions/12838549/merge-two-integers-in-python
  
st = str(input())
ways = 1
taken = True
for x in range(len(st)-1):
	if int(st[x])*10 + int(st[x+1]) <= 26:
		print(int(st[x]), int(st[x+1]))
		if taken:
			ways += 1
		else:
			ways += 2
		taken = True
	else:
		taken = False
print (ways)
	

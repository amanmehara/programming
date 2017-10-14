#http://stackoverflow.com/questions/16908186/python-check-if-list-items-are-number
#http://stackoverflow.com/questions/1549801/differences-between-isinstance-and-type-in-python
t = int(input())
while t:
	a = input()
	lis=[str(x) for x in input().split()]
	lis.remove('+');
	lis.remove('=');
	for x in range(0,3):
		if lis[x].isdigit():
			lis[x] = int(lis[x])
		else:
			lis[x] = -1
	if lis[0] == -1:
		lis[0] = lis[2] - lis[1]
	if lis[1] == -1:
		lis[1] = lis[2] - lis[0]
	else:
		lis[2] = lis[0] + lis[1]
	
	print (lis[0]," + ", lis[1], " = ", lis[2])
	t-=1
	

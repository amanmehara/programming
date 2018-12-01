'''
The concept is very simple...
Assuming that there no. of boys (b) < no. of girls (g), then, we have b + 1 places where we can fills groups of girls. To minimize the number of girls in a line, we shall try to distribute them equally, i.e., g / (b + 1) girls everywhere.

If g % (b + 1) != 0, then we shall distribute g % (b + 1) girls in those many places and the answer then becomes g / (b + 1) + 1.

Trivial cases, g = b, answer is 1.
g or b = 0, answer is b or g respectively.
'''

mini = 0
g,b = [int(x) for x in input().split()]
while g != -1 and b != -1:
	if b == 0 or g==0:
		mini = b
		if g>b:
			mini = g
	elif g == b:
		mini = 1
	elif g>b:
		mini = int(g/(b+1))
		if g%(b+1) != 0:
			mini += 1
	else:
		mini = int(b/(g+1))
		if b%(g+1) != 0:
			mini += 1
	
	print(mini)
	g,b = [int(x) for x in input().split()]
	

# your code goes here
def Z(n):
	summ = 0
	while(n//5>=1):
		summ+=n//5
		n=n//5
	return summ
	
t=int(input())
while t:
	p = int(input())
	print(Z(p))
	t-=1
#source :http://www.purplemath.com/modules/factzero.htm
#source :https://en.wikipedia.org/wiki/Trailing_zero

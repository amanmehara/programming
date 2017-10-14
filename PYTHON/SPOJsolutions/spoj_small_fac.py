def fac(n):
	mult = 1
	for x in range(1,n+1):
		mult*=x
	return mult

t=int(input())
while t:
	p = int(input())
	q = fac(p)
	print(q)
	t-=1

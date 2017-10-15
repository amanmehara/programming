n=int(input())
while n!=0:
	perm = []*n
	perm = [int(x) for x in input().split(' ')]
	inv_perm = [(perm.index(x)+1) for x in range(1,n+1)]
	if perm==inv_perm:
		print ("ambiguous")
	else:
		print("not ambiguous")
	n=int(input())

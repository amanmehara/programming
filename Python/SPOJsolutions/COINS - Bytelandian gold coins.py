n = int(input())
while(n!=EOF):
    lis = [0]*n
    lis[0]=0
    for x in range(n+1):
	temp = lis[x//3]+lis[x//2]+lis[x//4]
	lis[x] = max(lis[x],temp)
    print(lis[n])
    n = int(input())

n = int(input())
if n <= 1:
	print("TAK")
elif n & (n-1) == 0:
	print("TAK")
else:
	print("NEI")

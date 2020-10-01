
def binary_search(arr, low, high, x): 

	if high >= low: 
		mid = (high + low) // 2
		
		if arr[mid] == x: 
			return mid 

		elif arr[mid] > x: 
			return binary_search(arr, low, mid - 1, x) 

		
		else: 
			return binary_search(arr, mid + 1, high, x) 

	else: 
		return -1


arr = [ 12, 43, 74, 90, 88 ] 
x = 90

result = binary_search(arr, 0, len(arr)-1, x) 

if result != -1: 
	print("Element is present at index", str(result)) 
else: 
	print("Element is not present ")

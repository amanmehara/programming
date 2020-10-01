def binary(arr, low, high, n): 
	if high >= low: 

		mid = (high + low) // 2
		if arr[mid] == n: 
			return mid  
		elif arr[mid] > n: 
			return binary(arr, low, mid - 1, n) 

		else: 
			return binary(arr, mid + 1, high, n)   
      
  else:
    return -1

arr = [ 12, 43, 74, 90, 88 ] 
n = 90
 
res = binary(arr, 0, len(arr)-1, n) 

if res != -1: 
	print("Element is present at index", str(res)) 
else: 
	print("Element is not present") 

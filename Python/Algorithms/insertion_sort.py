def insertion_sort(arr):
    length = len(arr)

    # Traverse through 1 to length of array
    for i in range(1, length):
        j = i-1;

        #Swap elements that are not in right position.
        while (j >= 0) and (arr[j] > arr[j+1]):
            temp = arr[j]
            arr[j] = arr[j+1]
            arr[j+1] = temp
            j-=1


# Driver code to test insertion sort function
arr = [12, 11, 13, 5, 6]
print("Before Sorting :", arr) # Before Sorting : [12, 11, 13, 5, 6]
insertion_sort(arr)
print("After Sorting :", arr) # After Sorting : [5, 6, 11, 12, 13]

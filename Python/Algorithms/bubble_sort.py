def bubble_sort(array):
    """
    >>> bubble_sort([3,2,1])
    [1, 2, 3]
    """
    length = len(array)
    for i in range(length - 1):
        for j in range(0, length - i - 1):
            if array[j] > array[j + 1]:
                array[j], array[j + 1] = array[j + 1], array[j] # swap two numbers
    return array

if __name__ == "__main__":
    import doctest
    doctest.testmod()

    array = [100, 67, 3, 56, 23, 86, 13, 64, 890]
    sorted_array = bubble_sort(array)
    print(sorted_array)
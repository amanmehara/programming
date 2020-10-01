
def quickSort(sequence):

    lenght = len(sequence)
    if lenght <= 1:
        return sequence
    else:
        pivot = sequence.pop()

    items_lower = []
    items_larger = []

    for item in sequence:
        if item < pivot:
            items_lower.append(item)
        else:
            items_larger.append(item)

    
    return quickSort(items_lower) + [pivot] + quickSort(items_larger)

print(quickSort([5,4,2,1,7,9,3,1]))

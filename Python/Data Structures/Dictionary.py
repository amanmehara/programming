# Dictionaries are data structures formatted somewhat like a JSON document

# Ways to declare a dictionary
Dict_example = {'key1': 39, 'key2': 21, 'key3': 69}
Dict_example2 = dict(key1 = 39, key2 = 21, key3 = 69)


# Calling methods
number = Dict_example['key1']
print(number)  # OUTPUT --> 39

# Changing a value of a key
Dict_example2['key1'] = 99
print(Dict_example2['key1'])  # OUTPUT --> 99

# Adding keys to a dictionary
Dict_example['key4'] = 101
print(Dict_example['key4'])  # OUTPUT --> 101

# Deleting keys from the existing dictionary
del Dict_example2['key3']
print(Dict_example2)  # OUTPUT --> {'key1': 99, 'key2': 21}
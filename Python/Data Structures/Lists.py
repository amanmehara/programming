# Lists or Arrays are present in all main programming languages

# Declaration or creation of a list 
Fruits = ["apple", "banana", "orange", "pear"]
Numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

# Basic indexing ways upon lists
print(Fruits[0])  # Output --> "apple"; arrayName[index]; index = n-1 (in the list)
print(Fruits[-1], "\n")  # Output --> "pear"; arrayName[index]; index = n-1 (in the list)
print(Fruits[0:3], "\n")  # Output --> "apple"; "banana", "orange"; To output several values
print(Fruits[0:4:2], "\n")  # Output --> "apple", "orange"; To have a skipping value

# Functions upon lists

Fruits.append("pineapple")  # Adds pineapple as the last element of the list
print(Fruits, "\n")

Fruits.remove("pear")  # Removes pear from the list
print(Fruits, "\n")

Fruits.insert(3, "grapes") # Inserts grapes as the fourth element of the list
print(Fruits, "\n")

del Fruits[2:4]  # Deletes certain values
print(Fruits)
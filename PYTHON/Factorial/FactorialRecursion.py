# recursive function definition to calculate factorial
def factorial(n):
  if(n<1):
    return 1
  else:
    result = n*factorial(n-1)
  return result 
  
#Input the number
n=int(input("Enter a no."))

# Call the factorial function
result=factorial(n)
print(result)


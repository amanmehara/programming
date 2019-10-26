#!/usr/bin/python

# swap two variables using temporary variable
def swap_temp(a, b):
    print("-" * 32)
    print("Swap with temporary varaiable")
    print("-" * 32)
    print("Before a: {} b: {}".format(a, b))
    tmp = b
    b = a
    a = tmp
    print("After  a: {} b: {}".format(a, b))

def swap_xor(a, b):
    print("-" * 32)
    print("Swap using xor")
    print("-" * 32)
    print("Before a: {} b: {}".format(a, b))
    a ^= b
    b ^= a
    a ^= b
    print("After  a: {} b: {}".format(a, b))

def swap_python(a, b):
    print("-" * 32)
    print("Swap using python a, b = b, a")
    print("-" * 32)
    print("Before a: {} b: {}".format(a, b))
    a, b = b, a
    print("After  a: {} b: {}".format(a, b))


def main():
    a = 1
    b = 2
    
    swap_temp(a, b)
    print("")
    swap_xor(a, b)
    print("")
    swap_python(a, b)

if __name__ == "__main__":
    exit(main())

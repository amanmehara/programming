/**
 * Created by @amanmehara on 24-09-2017.
 */

/*

  + : unary plus
  - : unary minus
 ++ : increment
 -- : decrement

 */

assert +3 == 3
assert -4 == 0 - 4

assert -(-1) == 1 // Note the usage of parentheses to surround an expression to apply the unary minus to that surrounded expression.


// In terms of unary arithmetic operators, the ++ (increment) and -- (decrement) operators are available, both in prefix and postfix notation

def a = 2
def b = a++ * 3 // The postfix increment will increment 'a' after the expression has been evaluated and assigned into 'b'
assert a == 3 && b == 6

def c = 3
def d = c-- * 2 // The postfix decrement will decrement 'c' after the expression has been evaluated and assigned into 'd'
assert c == 2 && d == 6

def e = 1
def f = ++e + 3 // 	The prefix increment will increment 'e' before the expression is evaluated and assigned into 'f'
assert e == 2 && f == 5

def g = 4
def h = --g + 1 // The prefix decrement will decrement 'g' before the expression is evaluated and assigned into 'h'
assert g == 3 && h == 4
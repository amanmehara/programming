/**
 * Created by @amanmehara on 24-09-2017.
 */

/**
 *
 * Unlike Java, Groovy doesn’t have an explicit character literal.
 * However, you can be explicit about making a Groovy string an actual character, by three different means.
 *
 */

char c1 = 'A' // by being explicit when declaring a variable holding the character by specifying the char type
assert c1 instanceof Character

def c2 = 'B' as char // by using type coercion with the as operator
assert c2 instanceof Character

def c3 = (char) 'C' // by using a cast to char operation
assert c3 instanceof Character
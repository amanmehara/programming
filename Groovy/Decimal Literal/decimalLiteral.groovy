/**
 * Created by @amanmehara on 24-09-2017.
 */

// primitive types
float  f = 1.234
double d = 2.345

// infinite precision
BigDecimal bd =  3.456

// Decimals can use exponents, with the e or E exponent letter, followed by an optional sign, and a integral number representing the exponent.

assert 1e3  ==  1_000.0
assert 2E4  == 20_000.0
assert 3e+1 ==     30.0
assert 4E-2 ==      0.04
assert 5e-1 ==      0.5

// Decimal numbers can’t be represented using a binary, octal or hexadecimal representation.
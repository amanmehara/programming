/**
 * Created by @amanmehara on 24-09-2017.
 */

/*

 The "not" operator is represented with an exclamation mark (!) and inverts the result of the underlying boolean expression.
 In particular, it is possible to combine the not operator with the Groovy truth.
 */

assert (!true)    == false // the negation of true is false
assert (!'foo')   == false // 'foo' is a non empty string, evaluating to true, so negation returns false
assert (!'')      == true // '' is an empty string, evaluating to false, so negation returns true
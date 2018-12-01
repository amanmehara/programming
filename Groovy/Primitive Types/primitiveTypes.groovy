/**
 * Created by @amanmehara on 24-09-2017.
 */

// Groovy supports the same primitive types as those defined by the Java Language Specification.

/**
 *
 * While Groovy declares and stores primitive fields and variables as primitives, because it uses Objects for everything, it autowraps references to primitives.
 *
 * Primitive type -> Wrapper class
 *
 * boolean -> Boolean
 * char    -> Character
 * short   -> Short
 * int     -> Integer
 * long    -> Long
 * float   -> Float
 * double  -> Double
 *
 */

class Foo {
    static int i
}

assert Foo.class.getDeclaredField('i').type == int.class
assert Foo.i != int.class && Foo.i.class == Integer.class
/**
 * Created by @amanmehara on 24-09-2017.
 */

def foo(String par1, Integer par2 = 1) { [name: par1, age: par2] }
assert foo('Marie').age == 1
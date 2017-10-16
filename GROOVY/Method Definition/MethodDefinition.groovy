/**
 * Created by @amanmehara on 24-09-2017.
 */

def someMethod() { 'method called' } //Method with no return type declared and no parameter

String anotherMethod() { 'another method called' } //Method with explicit return type and no parameter

def thirdMethod(param1) { "$param1 passed" } //Method with a parameter with no type defined

static String fourthMethod(String param1) { "$param1 passed" } //Static method with a String parameter
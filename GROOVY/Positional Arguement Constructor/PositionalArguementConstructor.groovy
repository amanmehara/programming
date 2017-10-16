/**
 * Created by @amanmehara on 24-09-2017.
 */

class PersonConstructor {
    String name
    Integer age

    PersonConstructor(name, age) { //Constructor declaration
        this.name = name
        this.age = age
    }
}

def person1 = new PersonConstructor('Marie', 1) //Constructor invocation, classic Java way
def person2 = ['Marie', 2] as PersonConstructor //Constructor usage, using coercion with as keyword
PersonConstructor person3 = ['Marie', 3] //Constructor usage, using coercion in assignment
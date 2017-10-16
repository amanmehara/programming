/**
 * Created by @amanmehara on 24-09-2017.
 */

class PersonWithoutConstructor { //No constructor declared
    String name
    Integer age
}

def pwc1 = new PersonWithoutConstructor() //No parameters given in the instantiation
def pwc2 = new PersonWithoutConstructor(name: 'Marie') //name parameter given in the instantiation
def pwc3 = new PersonWithoutConstructor(age: 1) //age parameter given in the instantiation
def pwc4 = new PersonWithoutConstructor(name: 'Marie', age: 2) //name and age parameters given in the instantiation
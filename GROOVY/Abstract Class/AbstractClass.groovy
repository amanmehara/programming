/**
 * Created by @amanmehara on 24-09-2017.
 */

abstract class Abstract { //abstract classes must be declared with abstract keyword

    String name

    abstract def abstractMethod() //abstract methods must also be declared with abstract keyword

    def concreteMethod() {
        println 'concrete'
    }

}
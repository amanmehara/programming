/**
 * Created by @amanmehara on 24-09-2017.
 */

class Outer {

    private String privateStr

    def callInnerMethod() {
        new Inner().method() //the inner class is instantiated and its method gets called
    }

    class Inner { //inner class definition, inside its enclosing class
        def method() {
            println "${privateStr}." //even being private, a field of the enclosing class is accessed by the inner class
        }
    }

}
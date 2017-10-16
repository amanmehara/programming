/**
 * Created by @amanmehara on 24-09-2017.
 */

class SystemGreeter implements Greeter { //The SystemGreeter declares the Greeter interface using the implements keyword

    void greet(String name) { //Then implements the required greet method
        println "Hello $name"
    }

}

def greeter = new SystemGreeter()
assert greeter instanceof Greeter //Any instance of SystemGreeter is also an instance of the Greeter interface
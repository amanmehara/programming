/**
 * Created by @amanmehara on 24-09-2017.
 */

class Outer3 {
    private String privateStr = 'some string'

    def startThread() {
        new Thread(new Runnable() { //	comparing with the last example of previous section, the new Inner2() was replaced by new Runnable() along with all its implementation
            void run() {
                println "${privateStr}."
            }
        }).start() //the method start is invoked normally
    }
}
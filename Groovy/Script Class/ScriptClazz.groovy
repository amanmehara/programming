import org.codehaus.groovy.runtime.InvokerHelper

/**
 * Created by @amanmehara on 24-09-2017.
 */

class ScriptClazz extends Script {
    def run() {
        println 'Groovy world!'
    }
    static void main(String[] args) {
        InvokerHelper.runScript(ScriptClazz, args)
    }
}
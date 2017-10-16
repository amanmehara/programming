/**
 * Created by @amanmehara on 24-09-2017.
 */

boolean checkIfCalled() {
    called = true
}

called = false
true || checkIfCalled()
assert !called

called = false
false || checkIfCalled()
assert called

called = false
false && checkIfCalled()
assert !called

called = false
true && checkIfCalled()
assert called
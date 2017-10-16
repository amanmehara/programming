/**
 * Created by @amanmehara on 24-09-2017.
 */

//The logical "not" has a higher priority than the logical "and".
assert (!false && false) == false

//The logical "and" has a higher priority than the logical "or".
assert true || true && false
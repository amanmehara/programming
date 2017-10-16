/**
 * Created by @amanmehara on 24-09-2017.
 */

int fib(int n) {
    n < 2 ? 1 : fib(n-1) + fib(n-2)
}

assert fib(10)==89

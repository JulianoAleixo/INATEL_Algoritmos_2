#include <iostream>

using namespace std;

/*
int fibonnaci(int n) {
    if (n <= 2) {
        return 1;
    }
    return fibonnaci(n-1) + fibonnaci(n -2);
} // O(2^n)
*/


int fibonnaci(int fib[], int n) {
    if (n <= 2) {
        fib[n]=1;
        return 1;
    }
    if (fib[n] != -1) {
        return fib[n];
    }
    fib[n] = fibonnaci(fib, n-1) + fibonnaci(fib, n -2);
    return fib[n];
} // O(n)

int fibonnaci_int(int n) {
    int fib[n];
    fib[0] = 1;
    fib[1] = 1;
    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }
    return fib[n];
} // O(n)

int main() {
    int fib[1000];

    for (int i = 0; i < 1000; i++)  {
        fib[i] =
    }

    cout << fibonnaci(fib, 10) << endl << endl;
    cout << fibonnaci_int(10) << endl;

    return 0;
}
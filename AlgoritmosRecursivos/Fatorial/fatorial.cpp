#include <iostream>

using namespace std;

int fatorial(int n) {
    if (n == 1) {
        return 1;
    }
    return n * fatorial(n - 1);
} // O(n)

int main() {
    cout << fatorial(7);
    return 0;
}
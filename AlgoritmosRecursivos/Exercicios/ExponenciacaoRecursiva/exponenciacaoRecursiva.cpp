#include <iostream>
using namespace std;

int power(int a, int b) {
    if (b == 0) {
        return 1;
    }

    if (b % 2 != 0) {
        return a * power(a, b - 1);
    }

    int temp = power(a, b / 2);
    return temp * temp;
}

int main() {
    int a, b;
    cin >> a;
    cin >> b;
    cout << power(a, b);
    return 0;
}

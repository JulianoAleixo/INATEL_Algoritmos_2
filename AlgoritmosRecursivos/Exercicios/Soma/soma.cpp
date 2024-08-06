#include <iostream>
using namespace std;

int soma(int n) {
    if (n == 1) {
        return 1;
    } else {
        return n + soma(n - 1);
    }
}

int main() {
    int n;
    cin >> n;
    cout << "A soma dos numeros de 1 a " << n << " e " << soma(n) << ".";
}
#include <iostream>
using namespace std;

int main() {
    int N, qtd = 0;
    cin >> N;

    int v[N];

    int* p = v;
    for (int i = 0; i < N; ++i) {
        cin >> *p;
        p++;
    }

    p = v;
    for (int i = 0; i < N; ++i) {
        if (*p > 0 && *p % 2 == 0) {
            qtd++;
        }
        p++;
    }

    cout << qtd;

    return 0;
}

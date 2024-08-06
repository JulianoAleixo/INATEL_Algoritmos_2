#include <iostream>
using namespace std;

int main() {
    int N, maior;
    cin >> N;

    int v[N];

    int* p = v;
    for (int i = 0; i < N; ++i) {
        cin >> *p;
        p++;
    }

    p = v;
    maior = *p;
    for (int i = 0; i < N; ++i) {
        if (*p > maior) {
            maior = *p;
        }
        p++;
    }

    cout << maior;

    return 0;
}

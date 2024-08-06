#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int v[N];

    int* p = v;
    for (int i = 0; i < N; ++i) {
        cin >> *p;
        p++;
    }

    p = v;
    for (int i = 0; i < N; ++i) {
        cout << *p << " ";
        p++;
    }

    return 0;
}

#include <iostream>
using namespace std;

int hash_aux(int k, int m) {
    int res = k % m;

    if (res < 0) {
        return res + m;
    } else {
        return res;
    }
}

int hash1(int k, int i, int m) {
    return (hash_aux(k, m) + i) % m;
}

int main() {
    int k, m;

    cin >> k >> m;

    for (int i = 0; i < m; ++i) {
        cout << hash1(k, i, m) << " ";
    }
    cout << endl;

    return 0;
}
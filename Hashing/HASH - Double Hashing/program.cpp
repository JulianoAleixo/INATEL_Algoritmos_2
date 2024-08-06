#include <iostream>
using namespace std;

struct Dado {
    int value;
    int status;
};

int h1(int k, int m) {
    int res = k % m;

    if (res < 0) {
        return res + m;
    } else {
        return res;
    }
}

int h2(int k, int m) {
    int res = 1 + (k % (m - 1));

    if (res < 0) {
        return res + m;
    } else {
        return res;
    }

}

int dhash(int k, int m, int i) {
    return (h1(k, m) + i * h2(k, m)) % m;
}

int main() {
    int k, m;

    cin >> k >> m;

    Dado t[m];

    for (int i = 0; i < m; i++) {
        t[i].status = 0;
        t[i].value = -1;
    }

    for (int i = 0; i < m; i++) {
        if (i == m - 1) {
            cout << dhash(k, m, i);
        } else {
            cout << dhash(k, m, i) << " ";
        }
    }

    return 0;
}

#include <iostream>
using namespace std;

struct Dado {
    int value;
    int status;
};

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

int hash_insert(Dado t[], int m, int k) {
    int i = 0;
    do {
        int j = hash1(k, i, m);
        if (t[j].status != 1) {
            t[j].value = k;
            t[j].status = 1;
            return j;
        } else {
            i++;
        }
    } while (i != m);
    return -1;
}

int hash_search(Dado t[], int m, int k) {
    int i = 0;
    int j;
    do {
        int j = hash1(k, i, m);
        if (t[j].value == k) {
            return j;
        }
        i++;
    } while (t[j].status != 0 && i<m);
    return -1;
}

int main() {
    int m, value;

    cin >> m;

    Dado t[m];

    for (int i = 0; i < m; i++) {
        t[i].status = 0;
        t[i].value = -1;
    }

    while (true) {
        int k;
        cin >> k;
        if (k == 0) {
            break;
        }
        int pos = hash_insert(t, m, k);
    }

    cin >> value;
    int position = hash_search(t, m, value);

    if (position != -1) {
        cout << "Chave " << value << " encontrada na posicao " << hash_search(t, m, value);
    } else {
        cout << "Chave " << value << " nao encontrada";
    }

    return 0;
}
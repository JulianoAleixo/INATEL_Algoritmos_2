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

int hash_insert(Dado t[], int m, int k) {
    int i = 0;
    do {
        int j = dhash(k, m, i);
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
        j = dhash(k, m, i);
        if (i < m && t[j].value == k) {
            return j;
        }
        i++;
    } while (i < m && t[j].status != 0);
    return -1;
}

int hash_remove(Dado t[], int m, int k) {
    int j = hash_search(t, m, k);
    if (j != -1) {
        t[j].status = 2;
        t[j].value = -1;
        return 0; // Removed successfully
    } else {
        return -1; // K is not on the table
    }
}

void hash_list(Dado t[], int m) {
    for (int i = 0; i < m; i++) {
        if (i == m - 1) {
            cout << t[i].value << endl;
        } else {
            cout << t[i].value << " ";
        }
    }
}

int main() {
    int k, m, op;

    cin >> m;

    Dado t[m];

    for (int i = 0; i < m; i++) {
        t[i].status = 0;
        t[i].value = -1;
    }

    do {
        cin >> op;
        switch(op) {
            case 1:
                cin >> k;
                hash_insert(t, m, k);
                break;
            case 2:
                cin >> k;
                cout << hash_search(t, m, k) << endl;
                break;
            case 3:
                cin >> k;
                hash_remove(t, m, k);
                break;
            case 4:
                hash_list(t, m);
                break;
            default:
                break;
        }
    } while (op != 5);

    return 0;
}

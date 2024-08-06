#include <iostream>
#include <string>
using namespace std;

struct Dado {
    string info;
    int k; // key
    int status; // 0: empty, 1:filled, 2:removed
};

int h1(int k, int m) {
    int res = k % m;
    return (res < 0) ? res + m : res;
}

int h2(int k, int m) {
    int res = 1 + (k % (m - 1));
    return (res < 0) ? res + m : res;
}

int dhash(int k, int m, int i) {
    return (h1(k, m) + i * h2(k, m)) % m;
}

int hash_insert(Dado t[], int m, int k, const string& info) {
    int i = 0;
    do {
        int j = dhash(k, m, i);
        if (t[j].status != 1) {
            t[j].k = k;
            t[j].status = 1;
            t[j].info = info;
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
        if (t[j].status == 1 && t[j].k == k) {
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
        return 0; // Removed successfully
    } else {
        return -1; // Key is not in the table
    }
}

void hash_list(Dado t[], int m) {
    for (int i = 0; i < m; i++) {
        if (t[i].status == 1) {
            cout << t[i].info << endl;
        } else {
            cout << "vazio" << endl;
        }
    }
}

int get_ascii_sum(const string& word) {
    int sum = 0;
    for (char c : word) {
        sum += c;
    }
    return sum;
}

int main() {
    int m, k, op, foundItemIndex;
    string info;

    cin >> m;
    cin.ignore(); // Ignore the newline character

    Dado t[m];

    for (int i = 0; i < m; i++) {
        t[i].status = 0;
    }

    do {
        cin >> op;
        cin.ignore(); // Ignore the newline character
        switch(op) {
            case 1:
                getline(cin, info);
                k = get_ascii_sum(info);
                hash_insert(t, m, k, info);
                break;
            case 2:
                getline(cin, info);
                k = get_ascii_sum(info);
                foundItemIndex = hash_search(t, m, k);
                if (foundItemIndex == -1) {
                    cout << info << " nao encontrado" << endl;
                } else {
                    cout << info << " encontrado na posicao " << foundItemIndex << endl;
                }
                break;
            case 3:
                getline(cin, info);
                k = get_ascii_sum(info);
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

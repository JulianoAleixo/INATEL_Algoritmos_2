#include <iostream>
#include <iomanip>
using namespace std;

struct Dado {
    int codigo;
    float preco;
    int quantidade;
    int status; // 0 - Empty | 1 - Full | -1 - Removed
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

int hash_insert(Dado produto[], int m, int code, float price, int quantity) {
    int i = 0;
    do {
        int j = hash1(code, i, m);
        if (produto[j].status != 1) {
            produto[j].status = 1;
            produto[j].codigo = code;
            produto[j].preco = price;
            produto[j].quantidade = quantity;

            return j;
        } else {
            i++;
        }
    } while (i != m);
    return -1;
}

int hash_search(Dado produto[], int m, int code) {
    int i = 0;
    int j;
    do {
        j = hash1(code, i, m);
        if (i < m && produto[j].codigo == code) {
            return j;
        }
        i++;
    } while (i < m && produto[j].status != 0);
    return -1;
}

int main() {
    int m, o;

    cin >> m >> o;

    Dado produto[m];

    for (int i = 0; i < m; i++) { // Filling every product into Empty
        produto[i].status = 0;
    }

    for (int i = 0; i < o; i++) {
        char operation;
        cin >> operation;

        if (operation == 'I') {
            int code, quantity;
            float price;

            cin >> code >> price >> quantity;

            hash_insert(produto, m, code, price, quantity);
        } else if (operation == 'A') {
            int code, quantity, index;

            cin >> code >> quantity;

            index = hash_search(produto, m, code);
            if (produto[index].status == 1) {
                produto[index].quantidade += quantity;

                if (produto[index].quantidade <= 0) {
                    produto[index].status = -1;
                }
            }

        }
    }

    int codeToSearch, quantityToBuy, indexOfFoundItem, realQuantity;

    cin >> codeToSearch >> quantityToBuy;

    indexOfFoundItem = hash_search(produto, m, codeToSearch);
    realQuantity = produto[indexOfFoundItem].quantidade;

    if (realQuantity < quantityToBuy || produto[indexOfFoundItem].status != 1) {
        cout << "Quantidade indisponivel" << endl;
    } else {
        cout << "R$" << fixed << setprecision(2) << produto[indexOfFoundItem].preco * quantityToBuy << endl;
    }

    return 0;
}

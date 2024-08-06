#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct info {
    string nome;
    int idade;
    float peso;
    float altura;
};

struct Dado {
    info atleta;
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

int hash_insert(Dado t[], int m, int k, const string& nome, int idade, float peso, float altura) {
    int i = 0;
    do {
        int j = dhash(k, m, i);
        if (t[j].status != 1) {
            t[j].k = k;
            t[j].status = 1;
            t[j].atleta.nome = nome;
            t[j].atleta.idade = idade;
            t[j].atleta.peso = peso;
            t[j].atleta.altura = altura;
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
            if (i == 0) {
                cout << "Nome: " << t[i].atleta.nome << endl;
                cout << "Idade: " << t[i].atleta.idade << endl;
                cout << fixed << setprecision(1);
                cout << "Peso: " << t[i].atleta.peso << endl;
                cout << fixed << setprecision(2);
                cout << "Altura: " << t[i].atleta.altura << endl;
            } else {
                cout << endl;
                cout << "Nome: " << t[i].atleta.nome << endl;
                cout << "Idade: " << t[i].atleta.idade << endl;
                cout << fixed << setprecision(1);
                cout << "Peso: " << t[i].atleta.peso << endl;
                cout << fixed << setprecision(2);
                cout << "Altura: " << t[i].atleta.altura << endl;
            }
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
    int m, k, op, foundItemIndex, idade;
    float peso, altura;
    string nome;

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
                getline(cin, nome);
                k = get_ascii_sum(nome);
                cin >> idade >> peso >> altura;
                hash_insert(t, m, k, nome, idade, peso, altura);
                break;
            case 2:
                getline(cin, nome);
                k = get_ascii_sum(nome);
                foundItemIndex = hash_search(t, m, k);
                if (foundItemIndex == -1) {
                    cout << nome << " nao encontrado" << endl << endl;
                } else {
                    cout << "Nome: " << t[foundItemIndex].atleta.nome << endl;
                    cout << "Idade: " << t[foundItemIndex].atleta.idade << endl;
                    cout << fixed << setprecision(1);
                    cout << "Peso: " << t[foundItemIndex].atleta.peso << endl;
                    cout << fixed << setprecision(2);
                    cout << "Altura: " << t[foundItemIndex].atleta.altura << endl << endl;
                }
                break;
            case 3:
                getline(cin, nome);
                k = get_ascii_sum(nome);
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

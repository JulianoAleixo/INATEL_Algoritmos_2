#include <iostream>
#include <list>

using namespace std;

int main() {
    list<int> lista1, lista2, lista3;
    int valor;

    while (cin >> valor && valor != 0) {
        lista1.push_back(valor);
    }

    while (cin >> valor && valor != 0) {
        lista2.push_back(valor);
    }

    auto it1 = lista1.begin();
    auto it2 = lista2.begin();

    while (it1 != lista1.end() && it2 != lista2.end()) {
        if (*it1 < *it2) {
            if (lista3.empty() || lista3.back() != *it1) {
                lista3.push_back(*it1);
            }
            ++it1;
        } else {
            if (lista3.empty() || lista3.back() != *it2) {
                lista3.push_back(*it2);
            }
            ++it2;
        }
    }

    while (it1 != lista1.end()) {
        if (lista3.empty() || lista3.back() != *it1) {
            lista3.push_back(*it1);
        }
        ++it1;
    }

    while (it2 != lista2.end()) {
        if (lista3.empty() || lista3.back() != *it2) {
            lista3.push_back(*it2);
        }
        ++it2;
    }

    for (int elem : lista3) {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}

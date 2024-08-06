#include <iostream>
#include <list>

using namespace std;

bool encontrar(list<int> lista, int x) {
    for (int num : lista) {
        if (num == x) {
            return true;
        }
    }
    return false;
}

int main() {
    list<int> lista;
    int valor;

    while (cin >> valor && valor != 0) {
        lista.push_back(valor);
    }

    int numero_a_pesquisar;
    cin >> numero_a_pesquisar;

    if (encontrar(lista, numero_a_pesquisar)) {
        cout << "Encontrado" << endl;
    } else {
        cout << "Nao encontrado" << endl;
    }

    return 0;
}

#include <iostream>
#include <list>

using namespace std;

int contar(list<int> lista) {
    int contador = 0;
    for (int num : lista) {
        contador++;
    }
    return contador;
}

int main() {
    list<int> lista;
    int valor;

    while (cin >> valor && valor != 0) {
        lista.push_back(valor);
    }

    cout << contar(lista) << endl;

    return 0;
}

#include <iostream>

using namespace std;

int main() {
    string numero;
    cin >> numero;

    int frequencia[10] = {0};

    for (char digito : numero) {
        frequencia[digito - '0']++;
    }

    char algarismoMaisFrequente = numero[0];
    int maiorFrequencia = frequencia[numero[0] - '0'];

    for (char digito : numero) {
        if (frequencia[digito - '0'] >= maiorFrequencia) {
            algarismoMaisFrequente = digito;
            maiorFrequencia = frequencia[digito - '0'];
        }
    }
    cout << algarismoMaisFrequente << " apareceu mais vezes" << endl;
    return 0;
}

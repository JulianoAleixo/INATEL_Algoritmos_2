#include <iostream>

using namespace std;

int ocorrencias(int vetor[], int elemento, int tamanho) {
    int j, contador = 0;
    for (j = 0; j < tamanho; j++) {
        if (vetor[j] >= elemento) {
            contador = contador + 1;
        }
    }
    return contador;
}

int main() {
    int vetor[7] = {1,2,3,4,5,6,7};
    int elemento = 5;
    int tamanho = 7;

    ocorrencias(vetor, elemento, tamanho);

    return 0;
}
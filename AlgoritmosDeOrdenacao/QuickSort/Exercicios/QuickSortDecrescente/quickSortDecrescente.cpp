#include <iostream>
using namespace std;

void quickSortReverse(int vetor[], int tamanho, int i, int j) {
    int trab, esq, dir, pivo;
    esq = i;
    dir = j;
    pivo = vetor[(esq + dir)/ 2];
    do {
        while (vetor[esq] > pivo)
            esq++;
        while (vetor[dir] < pivo)
            dir--;
        if (esq <= dir) {
            trab = vetor[esq];
            vetor[esq] = vetor[dir];
            vetor[dir] = trab;
            esq++;
            dir--;
        }
    } while (esq <= dir);

    if (dir-i >= 0)
        quickSortReverse(vetor, tamanho, i, dir);
    if (j-esq >= 0)
        quickSortReverse(vetor, tamanho, esq, j);
}

int main() {
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    quickSortReverse(arr, n, 0, n-1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
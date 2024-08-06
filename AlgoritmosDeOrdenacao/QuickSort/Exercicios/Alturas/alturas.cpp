#include <iostream>
#include <string>
using namespace std;

struct Aluno {
    string nome;
    float altura;
};

void quickSort(Aluno vetor[], int tamanho, int i, int j) {
    int esq, dir;
    Aluno trab, pivo;
    esq = i;
    dir = j;
    pivo = vetor[(esq + dir)/ 2];
    do {
        while (vetor[esq].altura < pivo.altura)
            esq++;
        while (vetor[dir].altura > pivo.altura)
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
        quickSort(vetor, tamanho, i, dir);
    if (j-esq >= 0)
        quickSort(vetor, tamanho, esq, j);
}

int main() {
    int n;
    cin >> n;

    Aluno arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i].nome;
        cin >> arr[i].altura;
    }

    quickSort(arr, n, 0, n-1);

    for (int i = 0;  i < n; i++) {
        cout << arr[i].nome << " ";
    }

    return 0;
}
#include <iostream>

using namespace std;

void insercaoDireta(int vetor[], int tamanho) {
    int i, j;
    int chave;
    for (j = 1; j < tamanho; j++) {
        chave = vetor[j];
        i = j - 1;
        while ((i >= 0) && (vetor[i] > chave)) {
            vetor[i + 1] = vetor[i];
            i = i - 1;
        }
        vetor[i + 1] = chave;
    }
}

int main() {
    int arr[3] = {2, 1, 3};

    insercaoDireta(arr, 3);

    return 0;
}

//     1 + 3(n + 1) + 3n
for(i = 0;i<n;i++) { // 6n + 4
x = 2 * i + 1; // 4n
y = 3 + i; // 3n
}

while(i<=n) {
    foo();
    fuu();
    i = i * 2;
}

//  MODELO RAM
for(int i = 0; i<n; i++) { // 6n + 4
    for(int j=0; j<n; j++){ // (6n + 4) * n
        for(int k = 0; k<n; k++) { // (6n + 4) * n²
            cout << "Hello World!" << endl; // 1 * n³
        }
    }
}

// n³ + 6n³ + 4n² + 6n² + 4n + 6n + 4
// 7n³ + 10n² + 10n + 4


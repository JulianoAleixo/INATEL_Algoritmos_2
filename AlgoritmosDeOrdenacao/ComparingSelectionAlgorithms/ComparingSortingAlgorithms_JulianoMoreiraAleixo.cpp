/**************************************************
 *                                                *
 *             Algoritmos de Ordenação            *
 *                   Comparação                   *
 *                                                *
 **************************************************
 *                                                *
 *  Autor: Juliano Moreira Aleixo                 *
 *  Disciplina: C03                               *
 *  Professor: Jonas Lopes de Vilas Boas          *
 *  Data: 17/03/2024                              *
 *                                                *
 **************************************************/

#include  <iostream>

using namespace std;

void selectionSort(int arr[], int n) {
    int aux;
    for (int j = 0; j < n; j++) { // 1 + 3n + 3n + 3
        int lower = arr[j], lowerPosition = j; // 5n
        // This loop needs to start in the second index to swap correctly.
        for (int i = j+1; i < n; i++) { // 3n + 3(n/2)n + 3n + 3(n/2)n = 3n + 1.5n² + 3n + 1.5n²
            if(arr[i] < lower) { // 4(n/2)n = 2n²
                lowerPosition = i; // 2(n/2)n = n²
                lower = arr[i]; // 3(n/2)n = 1.5n²
            }
        }
        aux = arr[j]; // 3n
        arr[j] = lower; // 3n
        arr[lowerPosition] = aux; // 3n
    }
} // Total: 6.5n² + 26n + 4

void insertionSort(int arr[], int n) {
    for(int i = 1; i < n; i++) { // 6n + 4
        int aux = arr[i]; // 3n
        int j = i - 1; // 4n
        while(j >= 0 && arr[j] > aux) { // 3n + 1.5n² + 3n + 1.5n²
            arr[j+1] = arr[j]; // 5(n/2)n = 2.5n²
            j--; // 1.5n²
        }
        arr[j+1] = aux; // 4n
    }
} // Total: 7n² + 23n + 4

void bubbleSort(int arr[], int n) {
    for(int i = 0; i < n; i++) { // 1 + 3n + 3n + 3
        for(int j = i+1; j < n; j++) { // 3n + 3(n/2)n + 3n + 3(n/2)n = 3n + 1.5n² + 3n + 1.5n²
            if(arr[j] < arr[i]) { // 4(n/2)n = 2n²
                int temp = arr[i]; // 3(n/2)n = 1.5n²
                arr[i] = arr[j]; // 4(n/2)n = 2n²
                arr[j] = temp; // 3(n/2)n = 1.5n²
            }
        }
    }
} // Total: 10n² + 12n + 4

int main() {
    int n = 0;
    cin >> n;
    int arr[n];

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // selectionSort(arr, n);
    // insertionSort(arr, n);
    bubbleSort(arr, n);

    cout << endl;
    for(int i : arr) {
        cout << i << " ";
    }

    return 0;
}

/*
 * Selection Sort:
 *      Análise Assintótica: O(n²)
 *      Análise no Modelo RAM: 6.5n² + 26n + 4
 *
 * Insertion Sort:
 *      Análise Assintótica: O(n²)
 *      Análise no Modelo RAM: 7n² + 23n + 4
 *
 * Bubble Sort:
 *      Análise Assintótica: O(n²)
 *      Análise no Modelo RAM: 10n² + 12n + 4
 *
 * Comparando as implementações, em termos de complexidade, o Selection Sort e o
 * Insertion Sort têm uma complexidade similar no modelo RAM, ambos com termos
 * quadráticos dominantes, mas com diferentes constantes multiplicativas.
 *
 * Por outro lado, o Bubble Sort apresenta uma complexidade um pouco pior,
 * devido ao número maior de comparações e trocas dentro dos loops.
 * Portanto, em termos de eficiência, o Bubble Sort é o método mais
 * lento entre os três. Entre o Selection Sort e o Insertion Sort, embora
 * a complexidade no modelo RAM seja um pouco melhor para o Selection Sort,
 * a diferença não é significativa em termos práticos.
 *
 * Assim, a escolha entre o Selection Sort e o Insertion Sort dependerá de
 * outros fatores, como o tamanho dos dados e a estrutura dos dados.
 */
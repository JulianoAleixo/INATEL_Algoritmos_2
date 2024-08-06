#include <iostream>

using namespace std;

void quickSort(int arr[], int start, int end) {
    int pivo = arr[(start + end) / 2];
    int i = start, j = end, aux;

    while (i <= j) {
        while (arr[i] < pivo) {
            i++;
        }
        while (arr[j] > pivo) {
            j--;
        }
        if (i <= j) {
            aux = arr[i];
            arr[i] = arr[j];
            arr[j] = aux;
            i++;
            j--;
        }
    }

    if (start < j) {
        quickSort(arr, start, j);
    }
    if (i < end) {
        quickSort(arr, i, end);
    }
}

int main() {
    int arr[9] = {13, 3, 5, 2, 21, 8, 34, 55, 1};

    quickSort(arr, 0, 8);

    for (int w = 0; w < 9; w++) {
        cout << arr[w] << endl;
    }
    return 0;
}
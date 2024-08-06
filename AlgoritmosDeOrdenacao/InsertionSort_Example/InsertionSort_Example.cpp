#include <iostream>

using namespace std;
/*
void insertionSort(int arr[], int n) {
    int i, j;
    for(j = 1; j < n; j++) {
        int aux = arr[j];
        i = j - 1;
        while(i >= 0 && arr[i] > aux) {
            arr[i+1] = arr[j];
            i--;
        }
        arr[i+1] = aux;
    }
}
*/

void insertionSort(int arr[], int n) {
    int i, j, aux;                      // 0
    for(j = 1; j < n; j++) {            // 1 + 3n + 3(n-1)                      = 6n - 2
        aux = arr[j];                   // 3(n-1)                               = 3n - 3
        for(i = j - 1;i >= 0; i--) {    // 3(n-1) + 2(n-1)(n/2) + 3(n-1)(n/2)   = 2.5n² + 0.5n - 3
            if (arr[i] > aux) {         // 4(n-1)(n/2)                          = 2n² - 2n
                arr[i+1] = arr[i];      // 5(n-1)(n/2)                          = 2.5n² - 2.5n
        } else {
                break;
            }
        }
        arr[i+1] = aux;                 // 4(n-1)                               = 4n - 4
    }
} // Total: 7n² + 18n - 12

int main() {
    int arr[7] = {8, 3, 2, 1, 4, 7, 5};
    int n = 7;

    insertionSort(arr, n);

    for(int k  : arr) {
        cout << arr[k-1] << endl;
    }

    return 0;
    }
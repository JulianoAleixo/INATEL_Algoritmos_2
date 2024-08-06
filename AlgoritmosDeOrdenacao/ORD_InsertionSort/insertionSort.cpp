#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    int i, j, key;

    for (j = 1; j < n; j++) {
        key = arr[j];
        i = j-1;
        while ((i >= 0) && (arr[i] > key)) {
            arr[i+1] = arr[i];
            i = i-1;
        }
        arr[i+1] = key;
    }
}

int main() {
    int arr[100];
    int n = 0, num;

    while (true) {
        cin >> num;
        if (num == 0) {
            break;
        }
        arr[n] = num;
        n++;
    }

    insertionSort(arr, n);

    for (int j = n-1; j >= 0; j--) {
        cout << arr[j] << " ";
    }

    return 0;
}

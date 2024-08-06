#include <iostream>
using namespace std;

void quickSort(int arr[], int n, int i, int j) {
    int trab, left = i, right = j, pivo;

    pivo = arr[(left + right)/2];
    do {
        while (arr[left] < pivo) {
            left++;
        }
        while (arr[right] > pivo) {
            right--;
        }
        if (left <= right) {
            trab = arr[left];
            arr[left] = arr[right];
            arr[right] = trab;
            left++;
            right--;
        }
    } while (left <= right);

    if (right - i >= 0) {
        quickSort(arr, n, i, right);
    }
    if (j - left >= 0) {
        quickSort(arr, n, left, j);
    }
}


int main() {
    int arr[100];
    int n = 0, num;

    while (true) {
        cin >> num;
        if (num == -1) {
            break;
        }
        arr[n] = num;
        n++;
    }

    quickSort(arr, n, 0, n-1);

    for (int k = 0; k < n; k++) {
        cout << arr[k] << " ";
    }

    return 0;
}
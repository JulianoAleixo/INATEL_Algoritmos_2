#include <iostream>

using namespace std;

void bubbleSort(int arr[], int n) {
    int i = 0, j = 0, count = 0, trab = 0, limite = 0;
    bool troca = true;

    limite = n - 1;

    while (troca) {
        troca = false;
        for (i = 0; i < limite; i++) {
            if (arr[i] > arr[i+1]) {
                trab = arr[i];
                cout << "New trab:" << trab << endl;
                arr[i] = arr[i + 1];
                arr[i + 1] = trab;
                j = i;
                troca = true;
                count++;
            }
        }
        limite = j;
    }
    cout<< "Contador:" << count << endl;
}

int main() {
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n ; i++) {
        cin >> arr[i];
    }
    bubbleSort(arr, n);

    return 0;
}
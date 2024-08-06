#include <iostream>
#include <string>
using namespace std;

void insertionSort(string arr[], int n) {
    int i, j;
    string key;
    for (j = 1; j < n; j++) {
        key = arr[j];
        i = j-1;
        while ((i >= 0) && (arr[i].size() > key.size())) {
            arr[i+1] = arr[i];
            i = i-1;
        }
        arr[i+1] = key;
    }
}

int main() {
    int n;
    cin >> n;
    string arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    insertionSort(arr, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }
}
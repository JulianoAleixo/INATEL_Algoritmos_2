#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    float grade;
    int registration;
};

void insertionSort(Student arr[], int n) {
    int i, j;
    Student key;
    for (j = 1; j < n; j++) {
        key = arr[j];
        i = j-1;
        while ((i >= 0) && (arr[i].grade > key.grade)) {
            arr[i+1] = arr[i];
            i = i-1;
        }
        arr[i+1] = key;
    }
}

int main() {
    int n;
    cin >> n;
    Student arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i].name;
        cin >> arr[i].grade;
        cin >> arr[i].registration;
    }

    insertionSort(arr, n);

    for (int i = n-1; i >= 0; i--) {
        cout << arr[i].name << " " << arr[i].grade << " " << arr[i].registration << endl;
    }
}

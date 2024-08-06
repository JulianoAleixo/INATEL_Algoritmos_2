#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        int maior = 0, menor = 0;
        for (int j = 0; j < n; j++) {
            if (arr[i] > arr[j]) {
                menor++;
            }
            else if (arr[i] < arr[j]) {
                maior++;
            }
        }
        if (menor == n-1) {
            cout << "Todos sao menores que " << arr[i] << endl;
        }
        else if (menor == 0) {
            cout << "Nenhum eh menor que " << arr[i] << endl;
        }
        else {
            cout << menor << " eh(sao) menor(es) que " << arr[i] << endl;
        }
    }

    return 0;
}

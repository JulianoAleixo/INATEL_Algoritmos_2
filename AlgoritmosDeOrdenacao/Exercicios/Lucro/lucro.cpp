#include <iostream>
#include <iomanip>

using namespace std;

struct DiaLucro {
    int dia;
    int lucro;
};

void bubbleSort(DiaLucro array[], int n) {
    for (int i = 0; i < n-1; ++i) {
        for (int j = 0; j < n-i-1; ++j) {
            if (array[j].lucro > array[j+1].lucro) {
                DiaLucro temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

int main() {
    int N;
    cin >> N;

    DiaLucro dias[100];
    for (int i = 0; i < N; ++i) {
        cin >> dias[i].lucro;
        dias[i].dia = i + 1;
    }

    bubbleSort(dias, N);

    cout << fixed << setprecision(2);
    for (int i = 0; i < N; ++i) {
        cout << dias[i].lucro << " ";
    }

    cout << endl << "Dia com menor lucro: R$ " << dias[0].lucro << ".00" << endl;
    cout << "Dia com maior lucro: R$ " << dias[N - 1].lucro << ".00" << endl;

    return 0;
}

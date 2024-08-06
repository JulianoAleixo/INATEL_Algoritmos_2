#include <iostream>
using namespace std;

struct Alunos {
    int nota1;
    int nota2;
    double media;
};

int main() {
    int n = 0, qtd = 0;
    cin >> n;
    Alunos arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i].nota1;
        cin >> arr[i].nota2;
        arr[i].media = (arr[i].nota1 + arr[i].nota2) / 2.0;

        if (arr[i].media > 60) {
            qtd++;
        }
    }
    cout << qtd;
}
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Produto {
    string nome;
    float preco;
};

int main() {
    int N;
    cin >> N;

    Produto produtos[100];
    for (int i = 0; i < N; ++i) {
        cin >> produtos[i].nome >> produtos[i].preco;
    }

    float X;
    cin >> X;

    int quantidadeProdutosComprados = 0;

    cout << fixed << setprecision(1);
    for (int i = 0; i < N; ++i) {
        if (produtos[i].preco <= X) {
            cout << "Voce pode comprar o produto " << produtos[i].nome << " por R$ " << produtos[i].preco << endl;
            quantidadeProdutosComprados++;
        }
    }

    cout << "Voce pode comprar " << quantidadeProdutosComprados << " produtos" << endl;

    return 0;
}

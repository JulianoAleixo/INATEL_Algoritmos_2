#include <iostream>
#include <list>

using namespace std;

int main() {
    int N;
    cin >> N;

    list<int> estoque;
    list<int> venda;

    for (int i = 0; i < N; ++i) {
        int operacao;
        cin >> operacao;

        if (operacao == 1) {
            int codigo;
            cin >> codigo;
            estoque.push_back(codigo);
        } else if (operacao == 2) {
            if (!estoque.empty()) {
                int produto = estoque.back();
                estoque.pop_back();
                venda.push_front(produto);
            }
        }
    }

    cout << "Estoque:";
    for (int codigo : estoque) {
        cout << " " << codigo;
    }
    cout << endl;

    cout << "Venda:";
    for (int codigo : venda) {
        cout << " " << codigo;
    }
    cout << endl;

    return 0;
}

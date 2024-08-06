/*
Nome: Juliano Moreira Aleixo
Matricula: GES 501
NP1 - 23/04/2024


#include <iostream>
#include <string>
using namespace std;

typedef struct item{
	int codigo;
	string nome;
	float preco;
} Item;

void selectionSortPreco(Item arr[], int n) {
    Item aux;
    for (int j = 0; j < n; j++) {
        Item lower = arr[j];
        int lowerPosition = j;

        for (int i = j+1; i < n; i++) {
            if(arr[i].preco < lower.preco) {
                lowerPosition = i;
                lower = arr[i];
            }
        }
        aux = arr[j];
        arr[j] = lower;
        arr[lowerPosition] = aux;
    }
}

void selectionSortCodigo(Item arr[], int n) {
    Item aux;
    for (int j = 0; j < n; j++) {
        Item lower = arr[j];
        int lowerPosition = j;

        for (int i = j+1; i < n; i++) {
            if(arr[i].codigo < lower.codigo) {
                lowerPosition = i;
                lower = arr[i];
            }
        }
        aux = arr[j];
        arr[j] = lower;
        arr[lowerPosition] = aux;
    }
}


int main(){
	int n;
	cin>>n;
	Item itens[n];

	for(int i=0;i<n;i++){
		cin>>itens[i].codigo;
		cin>>itens[i].nome;
		cin>>itens[i].preco;
	}
	int o;
	cin>>o;

    if (o == 0) {
        selectionSortCodigo(itens, n);
    }
    else if (o == 1) {
        selectionSortPreco(itens, n);
    }

	for(int i=0;i<n;i++){
		cout<<itens[i].nome<<endl;
	}

	return 0;
}

*/





#include <iostream>
#include <string>
using namespace std;

struct Produto {
    int codigo;
    string nome;
    float preco;
};

void ordenaCodigo(Produto arr[], int n) {
    Produto aux;
    for (int j = 0; j < n; j++) {
        Produto lower = arr[j];
        int lowerPosition = j;
        for (int i = j+1; i < n; i++) {
            if(arr[i].codigo < lower.codigo) {
                lowerPosition = i;
                lower = arr[i];
            }
        }
        aux = arr[j];
        arr[j] = lower;
        arr[lowerPosition] = aux;
    }
}

void ordenaPreco(Produto arr[], int n) {
    Produto aux;
    for (int j = 0; j < n; j++) {
        Produto lower = arr[j];
        int lowerPosition = j;
        for (int i = j+1; i < n; i++) {
            if(arr[i].preco < lower.preco) {
                lowerPosition = i;
                lower = arr[i];
            }
        }
        aux = arr[j];
        arr[j] = lower;
        arr[lowerPosition] = aux;
    }
}

int main() {
    int n, o;
    cin >> n;

    Produto arr[n];

    for(int i = 0; i < n; i++) {
        cin >> arr[i].codigo;
        cin >> arr[i].nome;
        cin >> arr[i].preco;
    }

    cin >> o;
    if (o == 0) {
        ordenaCodigo(arr, n);
    } else if (o == 1) {
        ordenaPreco(arr, n);
    }

    for(int i = 0; i < n; i++) {
        cout << arr[i].nome << endl;
    }

    return 0;
}











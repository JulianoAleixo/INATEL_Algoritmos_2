#include <iostream>
#include <string>
using namespace std;

struct Pirate {
    string name;
    int price = 0;
};

void sortPirates(Pirate arr[], int start, int end){
    if (start < end) {
        Pirate pivo = arr[(start + end) / 2];
        int i = start;
        int j = end;
        Pirate aux;
        while (i <= j) {
            while (arr[i].price < pivo.price)
                i++;
            while (arr[j].price > pivo.price)
                j--;
            if (i <= j) {
                aux = arr[i];
                arr[i] = arr[j];
                arr[j] = aux;
                i++;
                j--;
            }
        }
        sortPirates(arr, start, j);
        sortPirates(arr, i, end);
    }
}

int searchPirate(Pirate arr[], int n, int priceSought){
    int start = 0, end = n - 1, half;
    while (start <= end) {
        half = (start + end) / 2;
        if (arr[half].price == priceSought) {
            return half;
        } else if (arr[half].price > priceSought) {
            end = half - 1;
        } else {
            start = half + 1;
        }
    }
    return -1;
}

int main() {
    int n = 0, priceToSearch, indexOfFoundPirate;
    cin >> n;
    Pirate arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i].price;
        cin >> arr[i].name;
    }

    cin >> priceToSearch;

    sortPirates(arr, 0, n-1);

    indexOfFoundPirate = searchPirate(arr, n, priceToSearch);

    if (indexOfFoundPirate == -1) {
        cout << "Nenhum pirata encontrado";
    }
    else {
        cout << arr[indexOfFoundPirate].name;
    }

    return 0;
}
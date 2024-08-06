#include <iostream>
using namespace std;

int hash_aux(int k, int m) {
    int res = k % m;
    if (res < 0) {
        return res + m;
    } else {
        return res;
    }
}

int main() {
    int a, b, i = 0;

    do  {
        cin >> a >> b;
        if (i == 0) {
            cout << hash_aux(a, b);
        } else {
            cout << endl << hash_aux(a, b);
        }
        i++;
    } while (a != 0 && b != 0);

    return 0;
}
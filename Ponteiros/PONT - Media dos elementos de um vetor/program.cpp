#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int N;
    float media = 0;
    cin >> N;

    int v[N];

    int* p = v;
    for (int i = 0; i < N; ++i) {
        cin >> *p;
        media += *p;
        p++;
    }

    media /= N;

    cout << fixed << setprecision(2) << media;

    return 0;
}

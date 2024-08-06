#include <iostream>
using namespace std;

int binarySearch(int start, int end) {
    int target = 670;
    while (start <= end) {
        int middle = (start + end) / 2;

        int result = 40 * middle + 30;

        if (result == target) {
            return middle;
        } else if (result < target) {
            start = middle + 1;
        } else {
            end = middle - 1;
        }
    }
    return -1;
}

int main() {
    int start = 0;
    int end = 100;

    int result = binarySearch(start, end);
    if (result != -1) {
        cout << "The number that resolves the equation is: " << result << endl;
    } else {
        cout << "There is not any number between 0 and 100 that resolves the equation." << endl;
    }
    return 0;
}
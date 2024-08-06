#include <iostream>

using namespace std;

int rec_bin_search(int arr[], int start, int end, int element) {
    if (start > end) {
        return -1; // Not found the element, return -1
    }
    int middle = (start + end) / 2;
    if (arr[middle] == element) {
        return middle;
    } else if (arr[middle] > element) {
        return rec_bin_search(arr, start, middle - 1, element);
    } else {
        return rec_bin_search(arr, middle + 1, end, element);
    }
} // O(log₂(n))

int main() {
    int arr[10] = {1,3,6,9,12,15,22,32,38,50};

    cout << rec_bin_search(arr, 0, 9, 32);

    return 0;
}
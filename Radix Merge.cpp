/*
* Joshua Arthur
* Radix Sort
* Due 2/25/25
*/

#include <iostream>
using namespace std;

int arr[10000000];

void countingSort(int n, int exp) {

    int* temp = new int[n];
    int count[10];


    for (int i = 0; i < 10; i++) {
        count[i] = 0;
    }

    // Counting Digits
    for (int i = 0; i < n; i++) {
        int digit = (arr[i] / exp) % 10;
        count[digit]++;
    }

    // Convert to the total amount
    for (int i = 1; i < 10; i++) {
        count[i] = count[i] + count[i - 1];
    }

    // Temporary array
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        temp[count[digit] - 1] = arr[i];
        count[digit]--;
    }


    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }

    delete[] temp;
}

void radixSort(int n) {

    int max = arr[0];

    //Maxium
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // Digit Counting
    for (int exp = 1; max / exp > 0; exp = exp * 10) {
        countingSort(n, exp);
    }
}

int main() {

    int n = 0;

    while (cin >> arr[n]) {
        n++;
    }

    if (n > 0) {
        radixSort(n);
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }

    return 0;
}
/*
* Joshua Arthur
* Using inserting sort to organize an array
* Due 2/11/25
*/

#include <iostream>
using namespace std;

int arr[10000000];

void insertionSort(int arr[], int n) {
//Starts at 1, as index 0 is already sorted
    for (int i = 1; i < n; i++) {

        int key = arr[i]; //Current Value
        int j = i - 1;

        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int main() {
    int n = 0;

    
    while (cin >> arr[n]) { 
        n++;
    }

    if (n > 0) {
        insertionSort(arr, n);
    }

    
    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }

    return 0;
}

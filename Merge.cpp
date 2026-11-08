/*
* Joshua Arthur
* Merging two arrays together
* Due 2/11/25
*/
#include <iostream>
using namespace std;


void merge(int arr[], int leftside, int mid, int rightside) {
    //Finds the size of the array
    int size = rightside - leftside + 1;
    int* temp = new int[size];

    int i = leftside; //First half
    int j = mid + 1; //Second Half
    int k = 0;

    while (i <= mid && j <= rightside) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= rightside) {
        temp[k++] = arr[j++];
    }

    for (int x = 0; x < size; x++) {
        arr[leftside + x] = temp[x];
    }

    delete[] temp;
}

void mergeSort(int arr[], int leftside, int rightside) {
    if (leftside >= rightside)
        return;

    int mid = (leftside + rightside) / 2;

    mergeSort(arr, leftside, mid);
    mergeSort(arr, mid + 1, rightside);
    merge(arr, leftside, mid, rightside);
}

int arr[1000000];
int main() {
    
    int n = 0;

    
    while (cin >> arr[n]) {
        n++;
    }

   
    if (n > 0) {
        mergeSort(arr, 0, n - 1);
    }

   
    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }

    return 0;
}

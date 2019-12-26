#include <iostream>
#include <vector>
#include "day - 6/max_heap.h"

using namespace std;


void print_array(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void print_vector(vector<int> arr) {
    for (int i : arr)
        cout << i << " ";
    cout << endl;
}


int main() {
    int arr[12] = { 1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17 };

    int n = sizeof(arr) / sizeof(arr[0]);
    build_heap(arr, n);

    print_array(arr, n);

    insert_to_heap(arr, n, 20);
    print_array(arr, n);

    build_min_heap(arr, n);

    print_array(arr, n);
}
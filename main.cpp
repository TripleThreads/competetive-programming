#include <iostream>
#include <vector>
#include "day - 6/max_heap.h"
#include "day - 6/min_heap.h"

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
    int arr[4] = {4, 5, 8, 2};

    int n = sizeof(arr) / sizeof(arr[0]);
    build_heap(arr, n);


    print_array(arr, n);

    build_min_heap(arr, n);

    print_array(arr, n);
}
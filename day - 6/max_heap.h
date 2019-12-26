//
// Created by segni on 25/12/2019.
//
#include <iostream>
#include <cmath>

using namespace std;

int heapify(int array[], int size, int parent) {
    int largest = parent;
    int left = 2 * parent + 1;
    int right = 2 * parent + 2;

    if (left < size && array[left] > array[largest])
        largest = left;

    if (right < size && array[right] > array[largest])
        largest = right;

    if (largest != parent) {
        swap(array[parent], array[largest]);
        heapify(array, size, largest);
    }

    return parent;
}
void insert_to_heap(int array[], int &size, int key) {
    array[size - 1] = key;
    int parent = ceil((double) size / 2) - 1;
    int current = heapify(array, size, parent);

    parent = ceil((double)current / 2) - 1;
    while (parent >= 0 && array[parent] < array[current]) {
        heapify(array, size, parent);
        current = parent;
        parent = ceil((double)parent / 2) - 1;
    }
}
void build_heap(int array[], int n) {
    int startIx = (n / 2) - 1; // index of last non leaf node

    for (int i = startIx; i >= 0; i--) {
        heapify(array, n, i);
    }
}

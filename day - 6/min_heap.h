//
// Created by segni on 26/12/2019.
//

using namespace std;

void heapify_down(int array[], int size, int parent) {
    int smallest = parent;
    int left = 2 * parent + 1;
    int right = 2 * parent + 2;

    if (left < size && array[left] < array[smallest])
        smallest = left;

    if (right < size && array[right] < array[smallest])
        smallest = right;

    if (smallest != parent) {
        swap(array[parent], array[smallest]);
        heapify_down(array, size, smallest);
    }
}

void build_min_heap(int array[], int size) {

    int nonLeaf = (size / 2) - 1;

    for (int i = nonLeaf; i >= 0; i--) {
        heapify_down(array, size, i);
    }

}

//
// Created by segni on 22/11/2019.
//
#include <iostream>
#include <random>
#include <cmath>
#include <vector>

using namespace std;

void generate_random_array(int array[], int range) {

    for (int i = 0; i < range; i++)
        array[i] = i;

    random_device rd; // only used once to initialise (seed) engine
    mt19937 rng(rd()); // random-number engine used (Mersenne-Twister in this case)
    for (int i = 0; i < range; i++) {
        uniform_int_distribution<int> uni(i, range - 1); // guaranteed unbiased
        int _rand = uni(rng);
        swap(array[i], array[_rand]);
    }

}

void print_array(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void selection_sort(int array[], int size) {

    for (int i = 0; i < size; i++) {

        for (int j = i + 1; j < size; j++) {

            if (array[i] > array[j]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }

        }
    }
    print_array(array, size);
}


void insertion_sort(int array[], int size) {

    for (int i = 1; i < size; i++) {

        int key = array[i];

        int j = i - 1;

        while (j >= 0 && key < array[j]) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }

    print_array(array, size);
}

// quick sort

int partition(int array[], int low, int high) {

    int pivot = array[high]; // our pivot is always the last number

    int i = low;

    for (int j = low; j <= high - 1; j++) {
        if (array[j] < pivot) {
            swap(array[j], array[i]);
            i++;
        }
    }
    swap(array[high], array[i]); // swap pivot, and array [i + 1]
    return i;
}

void quick_sort(int array[], int low, int high) {

    if (low < high) {
        int pivot = partition(array, low, high);
        quick_sort(array, low, pivot - 1);
        quick_sort(array, pivot + 1, high);
    }
}

// merge sort

void merge_sort(int array[], int size) {

    if (size > 1) {

        int mid = size / 2;
        int left_size = mid;
        int right_size = size - mid;

        int left_array[left_size];
        int right_array[right_size];

        for (int l = 0; l < mid; l++)
            left_array[l] = array[l];

        for (int r = mid; r < size; r++)
            right_array[r - mid] = array[r];

        merge_sort(left_array, left_size);
        merge_sort(right_array, right_size);

        int left_ix = 0;
        int right_ix = 0;
        int total_ix = 0;

        while (left_ix < left_size && right_ix < right_size) {

            if (left_array[left_ix] < right_array[right_ix]) {
                array[total_ix++] = left_array[left_ix++];
            } else {
                array[total_ix++] = right_array[right_ix++];
            }
        }
        while (left_ix < left_size) {
            array[total_ix++] = left_array[left_ix++];
        }

        while (right_ix < right_size) {
            array[total_ix++] = right_array[right_ix++];
        }
    }
}

void count_sorting(int array[], int range) {
    int count_array[10] = {0};

    for (int i = 0; i < range; i++) {
        count_array[array[i]]++;
    }
    int a_ix = 0;

    for (int i = 0; i < range; i++) {
        for (int j = 0; j < count_array[i]; j++) {
            array[a_ix++] = i;
        }
    }
}

int max_digit(const int array[], int size) {
    int max = 0;
    for (int ar = 0; ar < size; ar++) {
        if (array[ar] > max)
            max = array[max];
    }
    return (int) log10(max) + 1;
}

void radix_count_sort(int array[], int exp, int size) {

    int j, m, p, count = 0;
    vector<int> pocket[10]; //radix of decimal number is 10

    m = pow(10, exp + 1);
    p = pow(10, exp);

    for (j = 0; j < size; j++) {
        int temp = array[j] % m;
        int index = temp / p;   //find index for pocket array
        pocket[index].push_back(array[j]);
    }

    count = 0;
    for (j = 0; j < 10; j++) {
        //delete from linked lists and store to array
        while (!pocket[j].empty()) {
            array[count] = *(pocket[j].begin());
            pocket[j].erase(pocket[j].begin());
            count++;
        }
    }

}

void radix_sorting(int array[], int size) {

    int max_d = max_digit(array, size);

    for (int exp = 0; exp < max_d; exp++) {
        radix_count_sort(array, exp, size);
    }
}

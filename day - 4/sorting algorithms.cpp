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

void print_vector(vector<int> arr) {
    for (int i : arr)
        cout << i << " ";
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

vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    int count_array[1001] = {0};
    int count_array2[1001] = {0};
    vector<int> ar;

    for (int i = 0; i < arr1.size(); i++) {
        count_array[arr1[i]]++;
    }

    for (int i = 0; i < arr2.size(); i++) {
        count_array2[arr2[i]]++;
    }

    int a_ix = 0;

    for (int i : arr2) {
        for (int j = 0; j < count_array[i]; j++) {
            ar.push_back(i);
        }
        count_array[i] = 0;
    }
    for (int i = 0; i < 1001; i++) {
        for (int j = 0; j < count_array[i]; j++) {
            ar.push_back(i);
        }
    }
    return ar;

}

bool isAnagram(string s, string t) {

    map<char, int> ana_table;
    if (s.length() != t.length()) {
        return false;
    }
    for (char a: s) {
        if (ana_table.find(a) == ana_table.end()){
            ana_table[a] = 1;
        }
        else {
            ana_table[a]++;
        }

    }
    for (char c : s) {
        cout << c << " " << ana_table[c] << endl;
    }
    for (char a: t) {
        if (ana_table.find(a) == ana_table.end())
            return false;
        else {
            ana_table[a]--;
        }
    }
    for (char a: t) {
        if (ana_table[a] > 0)
            return false;
    }
    return true;
}

vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {

    int size = R * C;

    list<vector<int>> res[size];

    vector<vector<int>> ans(size);

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            res[abs(r - r0) + abs(c - c0)].push_back({r, c});
        }
    }
    int index = 0;

    for (int i = 0; i < size; i++) {
        while(!res[i].empty()) {
            ans[index] = *(res[i].begin());
            res[i].erase(res[i].begin());
            index++;
        }
    }

    return ans;
}

void flip(vector<int>& A, int k) {
    for (int i = k - 1; i >= k / 2; i--) {
        swap(A[k - i - 1], A[i]);
    }
}

bool is_sorted(vector<int> &A, int size) {
    for (int i = 1; i < size; i++) {
        if (A[i - 1] > A[i])
            return false;
    }
    return true;
}

vector<int> pancakeSort(vector<int>& A) {
    vector<int> k_list;
    int arr_size =  A.size();

    int right_ix = arr_size;

    int max_index = 0;

    while (!is_sorted(A, arr_size)) {

        if (A[right_ix - 1] < A[right_ix - 2]  ) {
            max_index = right_ix - 1;
        }

        if (A[0] > A[right_ix - 1]) {
            flip(A, right_ix);
            k_list.push_back(right_ix);
            right_ix = arr_size + 1;
            max_index = 0;
        }
        else if (right_ix == 2) {
            flip(A, max_index);
            k_list.push_back(max_index);
            right_ix = arr_size + 1;
            max_index = 0;
        }
        right_ix--;
    }
    return k_list;
}
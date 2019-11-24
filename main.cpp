//
// Created by segni on 19/11/2019.
//
#include "day - 1/triangle stars.cpp"
#include "day - 1/add long nums.cpp"
#include "day - 3/division large numbers.cpp"
#include "day - 2/multiplication - long nums.cpp"
#include "day - 3/test.cpp"
#include "day - 3/calculator.cpp"
#include "day - 4/sorting algorithms.cpp"
using namespace std;

int main () {
    // test big integers

    auto initial = chrono::high_resolution_clock::now();
    test();
    auto final = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<std::chrono::seconds>(final - initial ).count();
    cout << duration << endl;


//    calculator();

//    int array[] = {10, 7, 8, 9, 1, 5};
//    int size = sizeof(array) / sizeof(array[0]);
//    merge_sort(array,  size);
//    print_array(array, size);

    return 0;
}
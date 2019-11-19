//
// Created by segni on 19/11/2019.
//
#include <iostream>

using namespace std;

/**
 * the following function will print an isoceles right angle triangle
 * */
void isoceles() {

    int n;
    cout << "Enter a number: ";
    cin >> n;

    for (int i = 0; i < n; i++) {

        for (int j = 0; j <= i; j++) {

            cout << "*";

        }

        cout << endl;
    }
}


void printSpaces(int row_size, int row) {

    for (int a = 0; a < row_size - row; a++) {
        cout << " ";
    }

}

void printStars(int row) {

    int stars_num = 2 * row + 1;

    for (int j = 0; j < stars_num; j++) {

        cout << "*";

    }
}

void loopsRefactored() {

    int row_size;
    cout << "Enter a number: ";
    cin >> row_size;

    for (int row = 0; row < row_size; row++) {

        printSpaces(row_size, row);

        printStars(row);
        cout << endl;
    }
}

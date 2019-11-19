//
// Created by segni on 19/11/2019.
//

void loops() {

    int n;
    cout << "Enter a number: ";
    cin >> n;

    for (int i = 0; i <= n; i++) {

        for (int a = 0; a < n - i; a++) {
            cout << "";
        }

        for (int j = 0; j <= i; j++) {

            cout << "*";

        }

        for (int j = i; j > 0; j--) {

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

    for (int j = 0; j <= row; j++) {

        cout << "*";

    }


    for (int j = row; j > 0; j--) {

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

//
// Created by segni on 19/11/2019.
// Created by segni on 09/12/2019.
//
#include <iostream>
#include <vector>

using namespace std;

string snow_walking_robot() {
    string user_input;
    cin >> user_input;
    int count[4] = {0};

    char up = 'U';
    char down = 'D';
    char left = 'L';
    char right = 'R';

    for (char chr: user_input) {
        if (chr == up)
            count[0]++;

        if (chr == left)
            count[1]++;

        if (chr == down)
            count[2]++;

        if (chr == right)
            count[3]++;

    }
    int up_down = min(count[0], count[2]);
    int left_right = min(count[1], count[3]);

    int x = 0, y = 0;

    string result;
    string last = "UD";
    char last_c = 'A';
    int lr = 0, ud = 0;
    if (up_down == 0 && left_right != 0)
        left_right = 1;
    else if (left_right == 0 && up_down != 0)
        up_down = 1;

    if (up_down >= 1) up_down++;
    if (left_right >= 1) left_right++;

    if (up_down < 1 && left_right < 1) return "\n";

    while (ud < up_down || lr < left_right) {
        if (last != "UD" && up_down > 0) {
            last = "UD";
            if (y > 0) {
                result.append("D");
                y--;
            } else {
                result.append("U");
                y++;
            }
            ud++;
        } else if (last != "LR" && left_right > 0) {
            last = "LR";
            if (x > 0) {
                result.append("L");
                x--;
            } else {
                result.append("R");
                x++;
            }
            lr++;
        }
    }
    cout << result.length() << endl;
    return result;
}

int main() {
    int times;
    cin >> times;
    for (int i = 0; i < times; i++) {
        cout << snow_walking_robot() << endl;
    }
}
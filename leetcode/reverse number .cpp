//
// Created by segni on 20/12/2019.
//

class Solution {
public:
    long long int reverse(long long int x) {
        long long int  reversed=0;

        while (x!=0){
            reversed = reversed*10 + x % 10;
            if( reversed > INT_MAX || reversed < INT_MIN)
                return 0;
            x /= 10;
        }

        return reversed;
    }
};
//
// Created by segni on 01/01/2020.
//

class Solution {
public:
    int gcd(int a, int b) {
        if (b == 0)
            return a;

        return gcd(b, a % b);
    }
    int lcm(int a, int b) {
        return (a * b) / gcd(a, b);
    }
    void calculate(string expression, int &num, int &den, int neg) {
        int numerator = stoi(expression.substr(0, expression.find('/'))) * neg;
        int denom = stoi(expression.substr(expression.find('/') + 1, expression.length()));
        int gc = lcm(den, denom);
        num = (gc / den) * num + (gc/denom) * numerator;
        den = gc;
    }
    string fractionAddition(string expression) {

        int num = 0, den = 1, numerator, denom, neg = 1;
        char op;

        while (expression.length() > 0) {
            int Pindex = 0, Nindex;
            string a;

            Pindex = expression.find('+') == -1 ? expression.length() : expression.find('+');
            Nindex = expression.find('-') == -1 ? Pindex: expression.find('-');

            int index = min(Pindex, Nindex);

            if (index == 0) {
                if (expression.at(index) == '-')
                    neg = -1;

                expression = expression.substr(index + 1, expression.length());
                continue;
            }

            a = expression.substr(0, index);
            calculate(a, num, den, neg);
            neg = 1;
            expression = expression.substr(index, expression.length());
        }
        string res;

        int GCD = gcd(abs(num), abs(den));
        den /= GCD;
        num /= GCD;
        res.append(to_string(num) + "/" + to_string(den));

        return res;
    }
};
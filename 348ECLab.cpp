#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <sstream>

using namespace std;

double extractNumeric(const string& str);

int main() {
    string input;

    while (true) {
        cout << "Enter a string (or 'END' to quit): ";
        cin >> input;

        if (input == "END") {
            break;
        }

        double number = extractNumeric(input);

        if (number != -999999.99) {
            cout << "The input is: " << fixed << setprecision(4)
                 << number << endl;
        } else {
            cout << "The input is invalid." << endl;
        }
    }

    return 0;
}

double extractNumeric(const string& str) {
    if (str.empty()) {
        return -999999.99;
    }

    bool hasSign = false;
    bool hasDecimal = false;
    bool hasDigits = false;

    for (size_t i = 0; i < str.size(); ++i) {
        char ch = str[i];

        if (ch == '+' || ch == '-') {
            if (i != 0 || hasSign) {
                return -999999.99;
            }
            hasSign = true;
        } else if (ch == '.') {
            if (hasDecimal) {
                return -999999.99;
            }
            hasDecimal = true;
        } else if (isdigit(ch)) {
            hasDigits = true;
        } else {
            return -999999.99;
        }
    }

    if (!hasDigits) {
        return -999999.99;
    }

    stringstream ss(str);
    double result;
    ss >> result;

    return result;
}
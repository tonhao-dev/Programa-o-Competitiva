#include <iostream>
#include <string>

using namespace std;

int main() {
    string number;
    cin >> number;

    int number_of_lucky_digits = 0;
    for(char digit: number) {
        if(digit == '4' || digit == '7') {
            number_of_lucky_digits++;
        }
    }

    string answer = (number_of_lucky_digits == 7 || number_of_lucky_digits == 4) ? "YES" : "NO";
    cout << answer << endl;

    return 0;
}
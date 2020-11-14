#include <iostream>

using namespace std;

int main() {
    int n_testes;
    cin >> n_testes;

    while(n_testes > 0) {
        for(int i = 0; i < n_testes; ++i) {
            int* answers = new int[5];
            int number_of_answers = 0;
            char answer;

            cin >> answers[0] >> answers[1] >> answers[2] >> answers[3] >> answers[4];

            for (int j = 0; j < 5; ++j){
                if(answers[j] <= 127) {
                    number_of_answers++;
                    answer = 'A' + j;
                }
            }

            if(number_of_answers != 1) {
                cout << "*" << endl;
            } else {
                cout << answer << endl;
            }
        }

        cin >> n_testes;
    }

    return 0;
}
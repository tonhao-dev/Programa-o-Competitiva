#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    while(true) {
        double largura, comprimento, raio1, raio2;
        cin >> largura >> comprimento >> raio1 >> raio2;

        if(largura == 0) break;

        int diagonal = (int) sqrt(pow(largura, 2) + pow(comprimento, 2));

        if(diagonal > raio1 * 2 + raio2 * 2) {
            cout << "S" << endl;
        } else {
            cout << "N" << endl;
        }
    }

    return 0;
}
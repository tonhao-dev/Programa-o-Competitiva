#include <iostream>
#include <string>

using namespace std;

int main() {
    char digito_erro;
    string valor_contrato;
    string novo_valor;

    while(true) {
        novo_valor = string();
        cin >> digito_erro >> valor_contrato;

        if(digito_erro == '0' && valor_contrato == "0") {
            return 0;
        }

        bool zero_left = true;
        for(auto x:valor_contrato) {
            if(x != digito_erro && zero_left == false) {
                novo_valor = novo_valor + x;
            }

            if(x != digito_erro && x != '0' && zero_left == true) {
                zero_left = false;
                novo_valor = novo_valor + x;
            }
        }

        if(zero_left) {
            cout << 0 << endl;
        } else {
            cout << novo_valor << endl;
        }
    }
    return 0;
}
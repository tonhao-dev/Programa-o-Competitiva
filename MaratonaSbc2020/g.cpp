#include <bits/stdc++.h>

using namespace std; 

int main() {
    int c, pontuacao = 100, max_pont = 100;

    cin >> c;
    for(int i =0; i<c;++i) {
        int caixa;
        cin >> caixa;
        pontuacao = caixa + pontuacao;
        max_pont = max(pontuacao, max_pont);
    }

    cout << max_pont << endl;

    return 0;
}
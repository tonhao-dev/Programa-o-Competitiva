#include <bits/stdc++.h>
#define debug(x) cout << x << std::endl

using namespace std; 

string caca[50];
int l_caca, c_caca;

void procurarPalavra(string palavra) {
    for(int i = 0; i < l_caca; i++) {
        for(int j = 0; j < c_caca; j++) {
            if(palavra[0] == caca[i][j]) {
                bool igual = true;
                for(int k=i; k<palavra.size(); ++k) {
                    
                }
            }
        }
    }
}

int main() {
    string input;

    getline(cin, input);
    stringstream stream(input);

    int l_caca, c_caca;
    stream >> l_caca >> l_caca;
    
    for(int i = 0; i < l_caca; i++) {
        getline(cin, caca[i]);
    }

    getline(cin, input);
    stringstream stream(input);

    int num_palavras;

    string palavra;
    stream >> num_palavras;
    for(int i = 0; i < num_palavras; i++) {
        getline(cin, palavra);
    }

    return 0;
}
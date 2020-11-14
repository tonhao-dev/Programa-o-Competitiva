#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#define debug(x) cout << x << std::endl

using namespace std;

int main() {
    unsigned long long int l_robo, c_robo;
    unsigned long long int l_arena, c_arena;
    unsigned long long int num_instrucoes;
    string orientacao;

    string input;

    while(true) {
        getline(cin, input);
        stringstream stream(input);

        stream >> l_arena >> c_arena >> num_instrucoes;

        if(l_arena == 0) break;

        string arena[1000];
        for(unsigned long long i = 0; i < l_arena; ++i) arena[i].resize(1000);

        for(unsigned long long int i=0; i < l_arena; ++i) {
            getline(cin, arena[i]);

            for(unsigned long long int j=0; j<c_arena; ++j) {
                if(arena[i][j] == 'N' || arena[i][j] == 'S' || arena[i][j] == 'O' || arena[i][j] == 'L') {
                    l_robo = i;
                    c_robo = j;

                    orientacao = arena[i][j];
                }
            }
        }

        string instrucoes;
        instrucoes.resize(100000);
        getline(cin, instrucoes);

        unsigned long long int num_figurinhas = 0;

        for(unsigned long long int i = 0; i < num_instrucoes; ++i) {
            if(instrucoes[i] == 'E') {
                if(orientacao == "N") orientacao = 'O';
                else if(orientacao == "O") orientacao = 'S';
                else if(orientacao == "S") orientacao = 'L';
                else if(orientacao == "L") orientacao = 'N';
            }
            if(instrucoes[i] == 'D') {
                if(orientacao == "N") orientacao = 'L';
                else if(orientacao == "L") orientacao = 'S';
                else if(orientacao == "S") orientacao = 'O';
                else if(orientacao == "O") orientacao = 'N';
            }
                
            unsigned long long int nova_linha, nova_coluna;
            if(instrucoes[i] == 'F') {
                if(orientacao == "N") {
                    nova_linha = l_robo - 1;
                    nova_coluna = c_robo;
                }
                if(orientacao == "L") {
                    nova_linha = l_robo;
                    nova_coluna = c_robo + 1;
                }
                if(orientacao == "S") {
                    nova_linha = l_robo + 1;
                    nova_coluna = c_robo;
                }
                if(orientacao == "O") {
                    nova_linha = l_robo;
                    nova_coluna = c_robo - 1;
                }
            }

            if(nova_linha >= 0 && nova_linha < l_arena && nova_coluna >= 0 && nova_coluna < c_arena && arena[nova_linha][nova_coluna] != '#') {
                l_robo = nova_linha;
                c_robo = nova_coluna;
            }

            if(arena[l_robo][c_robo] == '*') {
                num_figurinhas++;
                arena[l_robo][c_robo] = '.';
            }
        }

        cout << num_figurinhas << endl;
    }
    return 0;
}
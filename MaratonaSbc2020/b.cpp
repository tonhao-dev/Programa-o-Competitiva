#include <bits/stdc++.h>
#define debug(x) cout << x << std::endl

using namespace std; 

int main() {
    vector<vector<int> > arena(50);
    for(int i = 0; i < 50; ++i) {
        arena[i].resize(50);
    }

    int num_navios;
    cin >> num_navios;
    char saida = 'Y';

    for(int i = 1; i <= num_navios; ++i) {
        int orientacao, tamanho, i_navio, j_navio;
        cin >> orientacao >> tamanho >> i_navio >> j_navio;
        
        if(orientacao == 0) {
            for(int j=j_navio; j<tamanho + j_navio; j++) {
                if(j > 10) {
                    saida = 'N';
                }

                if(arena[i_navio][j] == 1) {
                    saida = 'N';
                } else {
                    arena[i_navio][j] = 1;
                }
            }
        } else {
            for(int j=i_navio; j< tamanho + i_navio; ++j) {
                if(j > 10) {
                    saida = 'N';
                }

                if(arena[j][j_navio] == 1) {
                    saida = 'N';
                } else {
                    arena[j][j_navio] = 1;
                }
            }
        }
        
    }

    cout << saida << endl;

    return 0;
}
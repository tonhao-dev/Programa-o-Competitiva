#include <iostream>
#include  <bits/stdc++.h>
#define debug(x) cout << x << std::endl

using namespace std; 

int main(){
	string input;
    int saque='E';
    int esq=0, dir=0;
    int gamesEsq=0, gamesDir=0;

    getline(cin, input);

    for(int i=0; i<input.length(); ++i) {
        if(input[i] == 'S' && saque == 'E') {
            esq++;
        } else if(input[i] == 'S' && saque == 'D') {
            dir++;
        } else if(input[i] == 'R' && saque == 'E') {
            dir++;
            saque = 'D';
        } else if(input[i] == 'R' && saque == 'D') {

            esq++;
            saque = 'E';
        }
        if(esq - dir >= 2 && esq >= 5) {
            gamesEsq++;
            esq = 0;
            dir = 0;
        }
        if(dir - esq >= 2 && dir >= 5) {
            gamesDir++;
            esq = 0;
            dir = 0;
        }

        if(esq == 10) {
            gamesEsq++;
            esq = 0;
            dir = 0;
        } else if(dir == 10) {
            gamesDir++;
            esq = 0;
            dir = 0;
        }

        if(input[i] == 'Q') {
            if(gamesEsq == 2) {
                cout << gamesEsq << " (winner) - " << gamesDir << endl;
            } else if(gamesDir == 2) {
                cout << gamesEsq << " - " << gamesDir << " (winner)" << endl;
            } else {
                cout << gamesEsq << " (" << esq;
            if(saque == 'E') cout << "*";
            cout << ") - " << gamesDir << " (" << dir;
            if(saque == 'D') cout << "*";
            cout << ")" << endl;
            }
        }
    }

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

class No
{
public:
    bool visitado;
    vector<int> vizinhos;
};

class Grafo
{
public:
    int num_vertices;
    vector<No> nos;

    Grafo(int num_vertices) {
        this->num_vertices = num_vertices;
        this->nos.resize(num_vertices);
    }

    void adicionarAresta(int v_origem, int v_destiono) {
        this->nos[v_origem].vizinhos.push_back(v_destiono);
        this->nos[v_destiono].vizinhos.push_back(v_origem);
    }

    void bfs(int no_corrente) {
        queue<int> fila;

        while(true) {
            if(this->nos[no_corrente].visitado == false) {
                cout << "Visitando vertice: " << no_corrente << endl;
                this->nos[no_corrente].visitado = true;
            }

            for(int i=0; i<this->nos[no_corrente].vizinhos.size(); ++i) {
                int vizinho = this->nos[no_corrente].vizinhos[i];
                if(this->nos[vizinho].visitado == false) {
                    cout << "Visitando vertice: " << vizinho << endl;
                    fila.push(vizinho);
                    this->nos[vizinho].visitado = true;
                }
            }

            if(fila.empty() == false) {
                no_corrente = fila.front();
                fila.pop();
            } else {
                break;
            }
        }
    }
};

int main()
{
    Grafo grafo(100);

    grafo.adicionarAresta(0, 2);
    grafo.adicionarAresta(0, 3);

    grafo.adicionarAresta(2, 3);
    grafo.adicionarAresta(2, 8);

    grafo.adicionarAresta(3, 8);

    grafo.adicionarAresta(8, 1);
    grafo.adicionarAresta(8, 10);
    
    grafo.adicionarAresta(10, 4);
    grafo.adicionarAresta(10, 7);

    grafo.adicionarAresta(7, 4);

    grafo.adicionarAresta(4, 9);

    grafo.adicionarAresta(9, 5);
    grafo.adicionarAresta(9, 6);

    grafo.adicionarAresta(6, 5);

    grafo.bfs(0);

    // for(int i=0; i<7; i++) {
    //     cout << "No " << i << " : ";
    //     for(auto vizinho: grafo.nos[i].vizinhos) {
    //         cout << vizinho << " ";
    //     }
    //     cout << " | Visitado: " << grafo.nos[i].visitado;
    //     cout << endl;
    // }
    return 0;
}
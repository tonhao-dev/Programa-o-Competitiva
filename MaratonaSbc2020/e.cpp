#include <bits/stdc++.h>
#define debug(x) cout << x << std::endl

using namespace std;

int anfitriao, menor_idade, maior_idade;

class No
{
public:
    bool visitado;
    int idade;
    int num_festas;
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

        for(int i = 0; i < num_vertices; ++i) {
            this->nos[i].num_festas = 0;
        }
    }

    void adicionarAresta(int v_origem, int v_destiono) {
        this->nos[v_origem].vizinhos.push_back(v_destiono);
        this->nos[v_destiono].vizinhos.push_back(v_origem);
    }

    void dfs(int no_corrente) {
        stack<int> pilha;
        // cout << "VIsitado" << endl;
        // debug(this->nos[no_corrente].visitado);

        while(true) {
            if(this->nos[no_corrente].visitado == false) {
                if(this->nos[no_corrente].idade >= menor_idade && this->nos[no_corrente].idade <= maior_idade) {
                    // // debug(this->nos[no_corrente].idade);
                    // debug(menor_idade);
                    // debug(maior_idade);

                    cout << "no_corrente: " << no_corrente << endl;
                    this->nos[no_corrente].num_festas++;
                }
                
                this->nos[no_corrente].visitado = true;
                pilha.push(no_corrente);
            }

            // Buscar por um vizinho nao visitado
            bool achou = false;
            for(int no_vizinho: this->nos[no_corrente].vizinhos) {
                // Achou um vizinho nao visitado
                if(this->nos[no_vizinho].visitado == false && this->nos[no_vizinho].idade < this->nos[no_corrente].idade) {
                    cout << "Nos" << endl;
                    debug(no_corrente);
                    debug(this->nos[no_corrente].idade);
                    debug(no_vizinho);
                    debug(this->nos[no_vizinho].idade);
                    
                    achou = true;
                    no_corrente = no_vizinho;
                }
            }

            if(achou == false) {
                // Caso nao encontre vizinho NAO visitado entao faz o backtracking
                pilha.pop();

                // Não ha mais nos a serem visitados
                if(pilha.empty()) break;

                // Se nao achou entao o elemento que agora esta no topo da pilha
                // e o novo no corrente
                no_corrente = pilha.top();
            }
        }
    }
};

int main()
{
    int num_empregados, num_festas;
    cin >> num_empregados >> num_festas;

    Grafo grafo(num_empregados + 1);

    for(int i = 0; i < num_empregados; ++i) {
        int idade, gerente;
        cin >> idade >> gerente;

        grafo.nos[i+1].idade = idade;
        
        if(i+1 != 1) {
            grafo.adicionarAresta(i+1, gerente);   
        }
    }

    grafo.nos[0].idade = 1000000;

    for(int i = 0; i < num_festas; ++i) {
        cin >> anfitriao >> menor_idade >> maior_idade;

        for(int j = 0; j < num_empregados; ++j) {
            grafo.nos[j+1].visitado = false;
        }

        grafo.dfs(anfitriao);
    }

    for(int i=1; i<= num_empregados; ++i) {
        cout << grafo.nos[i].num_festas << " ";
    }

    cout << endl;

    return 0;
}
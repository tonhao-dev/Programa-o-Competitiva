#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int num_amigos, num_garrafas, ml_por_garraga;
    int num_limoes, num_cortes, g_sal;
    int ml_uma_bebida, g_sal_bebida;

    cin >> num_amigos >> num_garrafas >> ml_por_garraga >> num_limoes >> num_cortes >> g_sal >> ml_uma_bebida >> g_sal_bebida;

    int ml_por_bebida = (num_garrafas * ml_por_garraga) / ml_uma_bebida;
    int num_pedacos_limao = (num_limoes * num_cortes);
    int sal_por_bebida = (g_sal / g_sal_bebida);

    int num_bebidas = min(ml_por_bebida, num_pedacos_limao);
    
    num_bebidas = min(num_bebidas, sal_por_bebida);

    cout << (num_bebidas / num_amigos) << endl;

    return 0;
}

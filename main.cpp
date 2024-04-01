#include <iostream>
#include <cmath> // Para funções matemáticas

using namespace std;

// Função para calcular o custo baseado no número de unidades
double calcularCusto(int unidades) {
    double custo;
    if (unidades <= 100) {
        custo = 800 + 0.16 * unidades - 0.0006 * pow(unidades, 2) + 0.000003 * pow(unidades, 3);
    } else {
        // Calculando o custo marginal em x = 100
        double custoMarginal100 = 0.16 - 0.0012 * 100 + 0.000009 * pow(100, 2);
        // Calculando o custo para 100 unidades
        double custoEm100 = 800 + 0.16 * 100 - 0.0006 * pow(100, 2) + 0.000003 * pow(100, 3);
        // Aplicando a taxa de variação linear para unidades acima de 100
        custo = custoEm100 + custoMarginal100 * (unidades - 100);
    }
    return custo;
}

int main() {
    int unidades;
    cout << "Digite a quantidade de unidades: ";
    cin >> unidades;

    double precoVenda = 5.00; // Definindo o preço de venda por unidade
    double custoTotal = calcularCusto(unidades);
    double receitaTotal = precoVenda * unidades;
    double lucroTotal = receitaTotal - custoTotal;

    cout << "Custo Total: R$ " << custoTotal << endl;
    cout << "Receita Total: R$ " << receitaTotal << endl;
    cout << "Lucro Total: R$ " << lucroTotal << endl;

    return 0;
}

#include <iostream>
#include <string>
using namespace std;

typedef struct {
    string nome;
    float salario;
    float media;
} Funcionario;

void InfoFuncionario(Funcionario empresa[], int& aux);
void CalculaMedia(Funcionario empresa[], int aux);
void Relatorio(Funcionario empresa[], int aux);

int main() {
    Funcionario empresa[100];
    int aux = 0;
    char resp;

    do {
        InfoFuncionario(empresa, aux);
        cout << "mais um funcionario(s/n): ";
        cin >> resp;
        cin.ignore();
    } while (resp != 'n');

    CalculaMedia(empresa, aux);
    cout << "== FUNCIONARIOS COM SALARIO ACIMA DA MEDIA=="<<endl;
    Relatorio(empresa, aux);

    return 0;
}

void InfoFuncionario(Funcionario empresa[], int& aux) {
    
    cout << "Nome do funcionario: ";
    getline(cin, empresa[aux].nome);

    cout << "Salario: ";
    cin >> empresa[aux].salario;

    aux++;
}

void CalculaMedia(Funcionario empresa[], int aux) {
    float soma = 0;
    for (int i = 0; i < aux; i++) {
        soma += empresa[i].salario;
    }
     empresa[0].media = soma / aux;
     cout << "Media salarial da empresa: " << empresa[0].media<<endl;

}

void Relatorio(Funcionario empresa[], int aux) {
    for (int i = 0; i < aux; i++) {
        if (empresa[i].salario > empresa[0].media) {
            cout << empresa[i].nome << " - " << empresa[i].salario << endl;
        }
    }
}

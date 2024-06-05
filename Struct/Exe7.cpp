#include <iostream>
#include <string>

using namespace std;

typedef struct
{
    string nome;
    float valorvenda, salario, comissao;
    int qntvendida;

} vendedor;

void infovendedor(vendedor[], int&);
void calculasalario(vendedor[], int);
void relatorio(vendedor[], int);

int main()
{
    vendedor vendedores[10];
    int aux = 0;
    char resp;

    do
    {
        infovendedor(vendedores, aux);
        cout << "mais um vendedor? (s/n): " << endl;
        cin >> resp;
        cin.ignore(); 
    } while (resp != 'n');

    calculasalario(vendedores, aux);
    relatorio(vendedores, aux);

    return 0;
}

void infovendedor(vendedor vendedores[], int& aux)
{
    cout << "Nome do Vendedor: ";
    getline(cin, vendedores[aux].nome);

    cout << "Quantidade vendida: ";
    cin >> vendedores[aux].qntvendida;

    cout << "Valor da venda: ";
    cin >> vendedores[aux].valorvenda;

    cout << "Salario Fixo: ";
    cin >> vendedores[aux].salario;

    aux++;
}

void calculasalario(vendedor vendedores[], int aux)
{
    for (int i = 0; i < aux; i++)
    {
        if (vendedores[i].qntvendida < 15)
        {
            vendedores[i].comissao = 0.15;
        }
        else if (vendedores[i].qntvendida < 30)
        {
            vendedores[i].comissao = 0.22;
        }
        else
        {
            vendedores[i].comissao = 0.3;
        }
    }
}

void relatorio(vendedor vendedores[], int aux)
{
    for (int i = 0; i < aux; i++)
    {
        cout << "nome: " << vendedores[i].nome << endl;
        cout << "Quantidade vendida: " << vendedores[i].qntvendida << endl;
        cout << "Valor da venda: " << vendedores[i].valorvenda << endl;
        cout << "Comissao: " << vendedores[i].comissao * 100 << "%" << endl;
        cout << "Salario Fixo: " << vendedores[i].salario << endl;
        cout << "Salario total: " << (vendedores[i].salario * (1 + vendedores[i].comissao)) << endl;
        cout << endl;
    }
}

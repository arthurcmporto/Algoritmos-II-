#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <iomanip>
#include <cctype>
#include <locale>
#define TMAX 10
using namespace std;

void IncluirProduto(string[], string[], float[], int[], int&, bool[], string[]);
void ConsultarItem(string[], string[], float[], int[], int&);
void AquisicaoItem(string[], int[], int&);
void VendaItem(string[], string[], string, float[], int[], int&, bool[], string[]);
void Relatorio(string[], string[], float[], int[], int&, string[]);
bool verificaFormatoData(const string&);
bool EstaForaDaValidade(const string& );
bool contemApenasLetras(const string& );


int main()
{
    setlocale (LC_ALL,"Portuguese");
    int opcao, VetQuantidade[TMAX], total = 0;
    string VetProdutos[TMAX], VetValidade[TMAX], data;
    float VetPrecos[TMAX];
    bool VetPerecivel[TMAX];
    string VetDataCompra[TMAX];

    do
    {
        cout << "Data(dd/mm/aaaa): " << endl;
        getline(cin, data);

        if (!verificaFormatoData(data))
        {
            cout << "A data não está no formato correto." << endl;
        }
    }
    while(!verificaFormatoData(data));

    do
    {
        cout << endl;
        cout << "[MERCADINHO]" << endl;
        cout << "1) INCLUIR ITEM" << endl;
        cout << "2) CONSULTAR ITEM" << endl;
        cout << "3) COMPRA DE ITEM" << endl;
        cout << "4) VENDER ITEM" << endl;
        cout << "5) RELATÓRIO" << endl;
        cout << "0) SAIR" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;
        system("cls");

        switch (opcao)
        {
        case 0:
            cout<<"VOLTE SEMPRE :)"<<endl;
            break;

        case 1:
            IncluirProduto(VetProdutos, VetValidade, VetPrecos, VetQuantidade, total, VetPerecivel, VetDataCompra);
            break;
        case 2:
            ConsultarItem(VetProdutos, VetValidade, VetPrecos, VetQuantidade, total);
            break;
        case 3:
            AquisicaoItem(VetProdutos, VetQuantidade, total);
            break;
        case 4:
            VendaItem(VetProdutos, VetValidade, data, VetPrecos, VetQuantidade, total, VetPerecivel, VetDataCompra);
            break;
        case 5:
            Relatorio(VetProdutos, VetValidade, VetPrecos, VetQuantidade, total, VetDataCompra);
            break;

        default:
            cout << "Opção inválida!" << endl;
            break;
        }
    }
    while (opcao != 0);

    return 0;
}


bool verificaFormatoData(const string& data)
{
    if (data.length() != 10)
    {
        return false;
    }

    for (int i = 0; i < 10; i++)
    {
        if (i == 2 || i == 5)
        {
            if (data[i] != '/')
            {
                return false;
            }
        }
        else
        {
            if (!isdigit(data[i]))
            {
                return false;
            }
        }
    }
    int dia = stoi(data.substr(0, 2));
    int mes = stoi(data.substr(3, 2));
    int ano = stoi(data.substr(6, 4));

    if (dia < 1 || dia > 31 || mes < 1 || mes > 12 || ano < 1900 || ano > 2099)
    {
        return false;
    }

    return true;
}

bool EstaForaDaValidade(const string& dataValidade)
{
    auto agora = chrono::system_clock::now();
    time_t dataAtual = chrono::system_clock::to_time_t(agora);
    struct tm tmDataAtual = *localtime(&dataAtual);

    struct tm tmDataValidade = {};
    stringstream ss(dataValidade);
    ss >> get_time(&tmDataValidade, "%d/%m/%Y");

    if (ss.fail())
    {

        return false;
    }

    time_t dataValidadeTime = mktime(&tmDataValidade);

    return difftime(dataAtual, dataValidadeTime) > 0;
}

bool contemApenasLetras(const string& produto)
{
    for (char c : produto)
    {
        if (!isalpha(c) && c != ' ')
        {
            return false;
        }
        return true;
    }
}
void IncluirProduto(string VetProdutos[], string VetValidade[], float VetPrecos[], int VetQuantidade[], int& total, bool VetPerecivel[], string VetDataCompra[])
{
    bool produtoExiste;


    if (total < TMAX)
    {
        cout << "\n=== Incluir Produto ===" << endl;

        do
        {
            cout << "Nome do produto: ";
            cin.ignore();
            getline(cin, VetProdutos[total]);

            produtoExiste = false;

            for (int i = 0; i < total; i++)
            {
                if (VetProdutos[i] == VetProdutos[total])
                {
                    produtoExiste = true;
                    break;
                }
            }

            if (produtoExiste)
            {
                cout << "Produto já cadastrado!" << endl;
                return;
            }

            if (!contemApenasLetras(VetProdutos[total]))
            {
                cout << "O nome do produto deve conter apenas letras." << endl;
            }
            else if (VetProdutos[total].empty() || VetProdutos[total][0] == ' ')
            {
                cout << "O nome do produto não pode começar com um espaço em branco." << endl;
            }
        }
        while (!contemApenasLetras(VetProdutos[total]) || VetProdutos[total].empty() || VetProdutos[total][0] == ' ');

        cout << "O produto é perecível? (1 - Sim, 0 - Não): ";
        cin >> VetPerecivel[total];
        cin.ignore();

        if (VetPerecivel[total])
        {
            do
            {
                cout << "Data de Validade (dd/mm/aaaa): ";

                getline(cin, VetValidade[total]);
                if (!verificaFormatoData(VetValidade[total]))
                {
                    cout << "A data não está no formato correto." << endl;
                }
            }
            while(!verificaFormatoData(VetValidade[total]));

        }
        else
        {
            VetValidade[total] = "";
        }
        do
        {
            cout << "Preço do Produto: ";
            cin >> VetPrecos[total];
            if(VetPrecos[total]< 1)
                cout<<"Valor: "<<VetPrecos[total]<<" é inválido"<<endl;
        }
        while(VetPrecos[total]< 1);

        do
        {
            cout << "Quantidade: ";
            cin >> VetQuantidade[total];
            if(VetQuantidade[total]< 1)
                cout<<"A quantidade: "<<VetQuantidade[total]<<" é inválida"<<endl;
        }
        while(VetQuantidade[total]< 1);

        VetDataCompra[total] = "";

        total++;

        cout << "Produto incluido com sucesso!" << endl;
    }
    else
    {
        cout << "Lista de produtos está cheia. Não é possível adicionar mais produtos." << endl;
    }
}

void ConsultarItem(string VetProdutos[], string VetValidade[], float VetPrecos[], int VetQuantidade[], int& total)
{
    cout << "\n=== Buscar Produto ===" << endl;

    string busca;
    bool encontrado = false;
    do
    {
        cout << "Digite o nome do Produto que deseja buscar: " << endl;
        cin.ignore();
        getline(cin, busca);
        if (!contemApenasLetras(busca))
        {
            cout << "O nome do produto deve conter apenas letras." << endl;
        }
        else if (busca.empty() || busca[0] == ' ')
        {
            cout << "O nome do produto não pode começar com um espaço em branco." << endl;
        }
    }
    while (!contemApenasLetras(busca) || busca.empty() || busca[0] == ' ');

    for (int i = 0; i < total; i++)
    {
        if (busca == VetProdutos[i])
        {
            encontrado = true;
            cout << "Quantidade: " << VetQuantidade[i] << endl;
            cout << "Preço: " << VetPrecos[i] << endl;
            if (!VetValidade[i].empty())
            {
                cout << "Validade: " << VetValidade[i] << endl;
            }
            break;
        }
    }

    if (!encontrado)
    {
        cout << "Produto não encontrado!" << endl;
    }
}

void AquisicaoItem(string VetProdutos[], int VetQuantidade[], int& total)
{
    string busca;
    int mais = 0;
    bool encontrado = false;
    cout << "\n=== Comprar Produto ===" << endl;
    do
    {
        cout << "Digite o nome do Produto que deseja buscar: " << endl;
        cin.ignore();
        getline(cin, busca);
        if (!contemApenasLetras(busca))
        {
            cout << "O nome do produto deve conter apenas letras." << endl;
        }
        else if (busca.empty() || busca[0] == ' ')
        {
            cout << "O nome do produto não pode começar com um espaço em branco." << endl;
        }
    }
    while (!contemApenasLetras(busca) || busca.empty() || busca[0] == ' ');


    for (int i = 0; i < total; i++)
    {
        if (busca == VetProdutos[i])
        {
            cout << "Quantidade que deseja acrescentar: " << endl;
            cin >> mais;
            VetQuantidade[i] += mais;
            cout << "Nova quantidade atualizada: " << VetQuantidade[i];
            encontrado = true;
            break;
        }
    }

    if (!encontrado)
    {
        cout << "Produto não encontrado!" << endl;
    }
}

void VendaItem(string VetProdutos[], string VetValidade[], string data, float VetPrecos[], int VetQuantidade[], int& total, bool VetPerecivel[], string VetDataCompra[])
{
    int menos = 0;
    string busca;
    string confirmacao;
    bool encontrado = false;
    cout << "\n=== Vender Produto ===" << endl;
do
    {
        cout << "Digite o nome do Produto que deseja buscar: " << endl;
        cin.ignore();
        getline(cin, busca);
        if (!contemApenasLetras(busca))
        {
            cout << "O nome do produto deve conter apenas letras." << endl;
        }
        else if (busca.empty() || busca[0] == ' ')
        {
            cout << "O nome do produto não pode começar com um espaço em branco." << endl;
        }
    }
    while (!contemApenasLetras(busca) || busca.empty() || busca[0] == ' ');


    for (int i = 0; i < total; i++) {
        if (busca == VetProdutos[i]) {
            encontrado = true;
            if (VetQuantidade[i] == 0) {
                cout << "Sem produto no estoque!" << endl;
                break;
            } else {
                if (VetPerecivel[i] && EstaForaDaValidade(VetValidade[i])) {
                    cout << "Produto fora da validade!" << endl;
                    break;
                }

                cout << "Quantidade que deseja comprar: ";
                cin >> menos;

                if (VetQuantidade[i] >= menos) {
                    cout << "Produto: " << VetProdutos[i] << endl;
                    cout << "Quantidade: " << menos << endl;
                    cout << "Valor unitario: " << VetPrecos[i] << endl;
                    cout << "Valor final: " << VetPrecos[i] * menos << endl;

                    cout << "Deseja confirmar a compra? (sim/nao): ";
                    cin.ignore();
                    getline(cin, confirmacao);

                    if (confirmacao == "sim") {
                        VetQuantidade[i] -= menos;
                        VetDataCompra[i] = data;

                        cout << "Compra confirmada!" << endl;
                    } else {
                        cout << "Compra cancelada!" << endl;
                    }
                } else {
                    cout << "Quantidade insuficiente em estoque!" << endl;
                }

                break;
            }
        }
    }

    if (!encontrado) {
        cout << "Produto nao encontrado!" << endl;
    }
}

void Relatorio(string VetProdutos[], string VetValidade[], float VetPrecos[], int VetQuantidade[], int& total, string VetDataCompra[])
{
    cout << "\n=== Relatório ===" << endl;
    for (int i = 0; i < total - 1; i++)
    {
        for (int j = 0; j < total - i - 1; j++)
        {
            if (VetProdutos[j] > VetProdutos[j + 1])
            {
                swap(VetProdutos[j], VetProdutos[j + 1]);
                swap(VetValidade[j], VetValidade[j + 1]);
                swap(VetPrecos[j], VetPrecos[j + 1]);
                swap(VetQuantidade[j], VetQuantidade[j + 1]);
                swap(VetDataCompra[j], VetDataCompra[j + 1]);
            }
        }
    }

    for (int i = 0; i < total; i++)
    {
        cout << "Nome: " << VetProdutos[i] << "| Quantidade: " << VetQuantidade[i] << "| Preço R$: " << VetPrecos[i];
        if (!VetValidade[i].empty())
        {
            cout << "| Validade: " << VetValidade[i];
        }
        if (!VetDataCompra[i].empty())
        {
            cout << "| Data da Compra: " << VetDataCompra[i];
        }
        cout << endl;
    }
}

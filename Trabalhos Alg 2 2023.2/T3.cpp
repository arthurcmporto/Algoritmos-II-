#include <iostream>
#include <fstream>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <locale.h>

using namespace std;

typedef struct{
    int codigo;
    char marcaModelo[50];
    char placa[10];
    char categoria; 
    bool disponivel;
    int quantidadeLocacoes;
}Veiculo;

typedef struct{
    char dataLocacao[11];
    char cpfCliente[12];
    int codigoVeiculo;
    int quantidadeDias;
    bool ativa;
}Locacao;

bool validarCPF(string cpf);
void salvarFrota(const Veiculo veiculos[], int numVeiculos);
void carregarFrota(Veiculo veiculos[], int& numVeiculos);
void salvarLocacoes(const Locacao locacoes[], int numLocacoes);
void carregarLocacoes(Locacao locacoes[], int& numLocacoes);
void incluirVeiculo(Veiculo veiculos[], int& numVeiculos);
void listarVeiculosDisponiveis(const Veiculo veiculos[], int numVeiculos);
void realizarLocacao(Veiculo veiculos[], int numVeiculos, Locacao locacoes[], int& numLocacoes);
void realizarDevolucao(Veiculo veiculos[], int numVeiculos, Locacao locacoes[], int& numLocacoes);
void gerarRelatorio(const Locacao locacoes[], int numLocacoes);

int main() {
    setlocale(LC_ALL, "Portuguese");
    Veiculo veiculos[100]; 
    int numVeiculos = 0;

    Locacao locacoes[1000];
    int numLocacoes = 0;

    carregarFrota(veiculos, numVeiculos);
    carregarLocacoes(locacoes, numLocacoes);

    int opcao;

    do {
        cout << "Menu:"<<endl;
        cout << "1. Incluir Veiculo"<<endl;
        cout << "2. Listar Veiculos Disponiveis"<<endl;
        cout << "3. Realizar Locacao"<<endl;
        cout << "4. Realizar Devolucao"<<endl;
        cout << "5. Gerar Relatorio"<<endl;
        cout << "0. Sair"<<endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                incluirVeiculo(veiculos, numVeiculos);
                break;
            case 2:
                listarVeiculosDisponiveis(veiculos, numVeiculos);
                break;
            case 3:
                realizarLocacao(veiculos, numVeiculos, locacoes, numLocacoes);
                break;
            case 4:
                realizarDevolucao(veiculos, numVeiculos, locacoes, numLocacoes);
                break;
            case 5:
                gerarRelatorio(locacoes, numLocacoes);
                break;
            case 0:
                cout << "Saindo do programa. Até mais!"<<endl;
                break;
            default:
                cout << "Opção inválida. Tente novamente."<<endl;
                break;
        }

    } while (opcao != 0);

    return 1;
}


bool validarCPF(string cpf) {
    if (cpf.length() != 11) {
        return false;
    }

    for (char c : cpf) {
        if (!isdigit(c)) {
            return false;
        }
    }

    int soma = 0, multiplicador = 10;
    for (int i = 0; i < 9; ++i) {
        soma += (cpf[i] - '0') * multiplicador--;
    }
    int primeiroDigito = 11 - (soma % 11);
    if (primeiroDigito > 9) {
        primeiroDigito = 0;
    }

    soma = 0, multiplicador = 11;
    for (int i = 0; i < 10; ++i) {
        soma += (cpf[i] - '0') * multiplicador--;
    }
    int segundoDigito = 11 - (soma % 11);
    if (segundoDigito > 9) {
        segundoDigito = 0;
    }

    return (cpf[9] - '0') == primeiroDigito && (cpf[10] - '0') == segundoDigito;
}


void salvarFrota(const Veiculo veiculos[], int numVeiculos) {
    ofstream arquivo("frota.dad", ios::binary);

    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo de frota." << endl;
        return;
    }

    arquivo.write(reinterpret_cast<const char*>(&numVeiculos), sizeof(numVeiculos));
    arquivo.write(reinterpret_cast<const char*>(veiculos), sizeof(Veiculo) * numVeiculos);

    arquivo.close();
}


void carregarFrota(Veiculo veiculos[], int& numVeiculos) {
    ifstream arquivo("frota.dad", ios::binary);

    if (!arquivo.is_open()) {
        cout << "Arquivo de frota nao encontrado. Criando novo arquivo." << endl;
        return;
    }

    arquivo.read(reinterpret_cast<char*>(&numVeiculos), sizeof(numVeiculos));
    arquivo.read(reinterpret_cast<char*>(veiculos), sizeof(Veiculo) * numVeiculos);

    arquivo.close();
}

void salvarLocacoes(const Locacao locacoes[], int numLocacoes) {
    ofstream arquivo("locados.txt");

    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo de locacoes." << endl;
        return;
    }

    for (int i = 0; i < numLocacoes; ++i) {
        arquivo << locacoes[i].dataLocacao << " "
                << locacoes[i].cpfCliente << " "
                << locacoes[i].codigoVeiculo << " "
                << locacoes[i].quantidadeDias << " "
                << locacoes[i].ativa << endl;
    }

    arquivo.close();
}

void carregarLocacoes(Locacao locacoes[], int& numLocacoes) {
    ifstream arquivo("locados.txt");

    if (!arquivo.is_open()) {
        cerr << "Arquivo de locacoes nao encontrado. Criando novo arquivo." << endl;
        return;
    }

    while (arquivo >> locacoes[numLocacoes].dataLocacao
                  >> locacoes[numLocacoes].cpfCliente
                  >> locacoes[numLocacoes].codigoVeiculo
                  >> locacoes[numLocacoes].quantidadeDias
                  >> locacoes[numLocacoes].ativa) {
        ++numLocacoes;
    }

    arquivo.close();
}

void incluirVeiculo(Veiculo veiculos[], int& numVeiculos) {
    Veiculo novoVeiculo;
    system("cls");

    cout << "Digite o codigo do veiculo: ";
    cin >> novoVeiculo.codigo;

    for (int i = 0; i < numVeiculos; ++i) {
        if (veiculos[i].codigo == novoVeiculo.codigo) {
            cout << "Erro: Veiculo ja cadastrado." << endl;
            return;
        }
    }

    cout << "Digite a marca e modelo: ";
    cin.ignore();
    cin.getline(novoVeiculo.marcaModelo, sizeof(novoVeiculo.marcaModelo));

    cout << "Digite a placa: ";
    cin >> novoVeiculo.placa;

    cout << "Digite a categoria (B-basico, I-intermediario, S-super): ";
    cin >> novoVeiculo.categoria;

    novoVeiculo.disponivel = true;
    novoVeiculo.quantidadeLocacoes = 0;

    veiculos[numVeiculos] = novoVeiculo;
    ++numVeiculos;

    // Salva a frota no arquivo
    salvarFrota(veiculos, numVeiculos);

    cout << "Veiculo cadastrado com sucesso!" << endl;
    system("pause");
    system("cls");
}

void listarVeiculosDisponiveis(const Veiculo veiculos[], int numVeiculos) {
    char categoria;
    system("cls");
    cout << "Digite a categoria (B-basico, I-intermediario, S-super): ";
    cin >> categoria;
    cout << "Veiculos disponiveis na categoria " << categoria << ":" << endl;

    for (int i = 0; i < numVeiculos; ++i) {
        if (veiculos[i].categoria == categoria && veiculos[i].disponivel) {
            cout << "Codigo: " << veiculos[i].codigo << ", Marca e Modelo: " << veiculos[i].marcaModelo << ", Placa: " << veiculos[i].placa << endl;
        }
    }
    system("pause");
    system("cls");
}

void realizarLocacao(Veiculo veiculos[], int numVeiculos, Locacao locacoes[], int& numLocacoes) {
    Locacao novaLocacao;
    system("cls");

    cout << "Digite a data da locacao (formato dd/mm/aaaa): ";
    cin >> novaLocacao.dataLocacao;

    cout << "Digite o CPF do cliente: ";
    cin >> novaLocacao.cpfCliente;
    if(!validarCPF(novaLocacao.cpfCliente)){
        cout << "CPF INVALIDO!"<<endl;
        return;
    }else{

    cout << "Digite o codigo do veiculo desejado: ";
    cin >> novaLocacao.codigoVeiculo;
    }

    bool veiculoEncontrado = false;
    for (int i = 0; i < numVeiculos; ++i) {
        if (veiculos[i].codigo == novaLocacao.codigoVeiculo && veiculos[i].disponivel) {
            veiculoEncontrado = true;
            break;
        }
    }

    if (!veiculoEncontrado) {
        cout << "Erro: Veiculo nao disponivel." << endl;
        system("pause");
        system("cls");
        return;
    }

    cout << "Digite a quantidade de dias da locacao: ";
    cin >> novaLocacao.quantidadeDias;

    novaLocacao.ativa = true;

    for (int i = 0; i < numVeiculos; ++i) {
        if (veiculos[i].codigo == novaLocacao.codigoVeiculo) {
            veiculos[i].disponivel = false;
            veiculos[i].quantidadeLocacoes++;
            break;
        }
    }

    locacoes[numLocacoes] = novaLocacao;
    ++numLocacoes;

    salvarLocacoes(locacoes, numLocacoes);

    cout << "Locacao realizada com sucesso." << endl;
    system("pause");
    system("cls");
}

void realizarDevolucao(Veiculo veiculos[], int numVeiculos, Locacao locacoes[], int& numLocacoes) {
    char cpfCliente[12];
    system("cls");

    cout << "Digite o CPF do cliente para devolucao: ";
    cin >> cpfCliente;
    if(!validarCPF(cpfCliente)){
        cout << "CPF INVALIDO!"<<endl;
        return; 
    } 

    bool locacaoEncontrada = false;
    int indiceLocacao;

    for (int i = 0; i < numLocacoes; ++i) {
        if (strcmp(locacoes[i].cpfCliente, cpfCliente) == 0 && locacoes[i].ativa) {
            locacaoEncontrada = true;
            indiceLocacao = i;
            break;
        }
    }

    if (!locacaoEncontrada) {
        cout << "Erro: Nenhuma locacao encontrada para o CPF informado." << endl;
        system("pause");
        system("cls");
        return;
    }

    cout << "Digite a data da devolucao (formato dd/mm/aaaa): ";
    char dataDevolucao[11];
    cin >> dataDevolucao;

    tm devolucaoTM = {};
    sscanf(dataDevolucao, "%d/%d/%d", &devolucaoTM.tm_mday, &devolucaoTM.tm_mon, &devolucaoTM.tm_year);
    devolucaoTM.tm_mon -= 1;
    devolucaoTM.tm_year -= 1900;

    tm locacaoTM = {};
    sscanf(locacoes[indiceLocacao].dataLocacao, "%d/%d/%d", &locacaoTM.tm_mday, &locacaoTM.tm_mon, &locacaoTM.tm_year);
    locacaoTM.tm_mon -= 1;
    locacaoTM.tm_year -= 1900;

    double multa = 0.0;
    double valorcarro=0.0;
    if (veiculos[indiceLocacao].categoria == 'B' || veiculos[indiceLocacao].categoria == 'b') {
        valorcarro = 100; 
    } else if (veiculos[indiceLocacao].categoria == 'I' || veiculos[indiceLocacao].categoria == 'i') {
        valorcarro = 200; 
    } else if (veiculos[indiceLocacao].categoria == 'S' || veiculos[indiceLocacao].categoria == 's') {
        valorcarro = 300; 
    }

    time_t tempoDevolucao = mktime(&devolucaoTM);
    time_t tempoLocacao = mktime(&locacaoTM);
    double segundosPorDia = 60 * 60 * 24; 
    double diferencaTempo = difftime(tempoDevolucao, tempoLocacao); 
    int diasAtraso = diferencaTempo / segundosPorDia - locacoes[indiceLocacao].quantidadeDias;

    if (diasAtraso > 0) {
        multa = (valorcarro* 0.20) + ((valorcarro * 0.01));
        cout << "Valor do carro R$ " << fixed << setprecision(2) << valorcarro<< endl;
        cout << "Multa de R$ " << fixed << setprecision(2) << multa << " devida devido a devolucao em atraso." << endl;
    }

    
    for (int i = 0; i < numVeiculos; ++i) {
        if (veiculos[i].codigo == locacoes[indiceLocacao].codigoVeiculo) {
            veiculos[i].disponivel = true;
            break;
        }
    }

    
    locacoes[indiceLocacao].ativa = false;

    cout << "Devolucao realizada com sucesso." << endl;
    system("pause");
    system("cls");
}

void gerarRelatorio(const Locacao locacoes[], int numLocacoes) {            //UTILIZAMOS A DATA DO SISTEMA
    system("cls");
    time_t now = time(0);
    tm* currentDate = localtime(&now);
    char dataAtual[11];
    strftime(dataAtual, sizeof(dataAtual), "%d/%m/%Y", currentDate);

    cout << "Relatorio de veiculos para devolucao em " << dataAtual << ":" << endl;

    for (int i = 0; i < numLocacoes; ++i) {
        if (strcmp(locacoes[i].dataLocacao, dataAtual) == 0 && locacoes[i].ativa) {
            cout << "Codigo do veiculo: " << locacoes[i].codigoVeiculo << ", CPF do cliente: " << locacoes[i].cpfCliente << endl;
        }
    }
    system("pause");
    system("cls");
}


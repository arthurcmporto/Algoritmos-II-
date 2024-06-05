#include <iostream>
#include <string>
using namespace std;

typedef struct{
string titulo;
int ano;
}Disco;

typedef struct{
string nome;
int qnt;
Disco discos[10];
}Banda;

void CadastrarBanda(Banda[],int&);
bool VerificaBanda(Banda[],int&);

int main(){

Banda bandas[10];
int aux=0, opcao;

cout << "==PRODUTORA=="<<endl;
cout << "1) Cadastrar Banda"<<endl;

cout << "OPCAO: ";
cin>>opcao;

switch (opcao)
{
case 1:
    CadastrarBanda(bandas,aux);
    break;

default:
    break;
}

    return 0;
}

void CadastrarBanda(Banda bandas[], int& aux){

 cout << "Digite o nome da banda: "<<endl;
 cin.ignore();
 getline(cin,bandas[aux].nome);

 cout << "Quantidade de discos lancados: "<<endl;
 cin>>bandas[aux].qnt;

 aux++;

}

bool VerificaBanda(Banda[],int&){


}
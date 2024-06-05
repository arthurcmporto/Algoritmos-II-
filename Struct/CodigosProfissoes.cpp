#include <iostream>
using namespace std;
#define TMAX 100

typedef struct{
 int codigo;
 string nome;
} TProfissao;

int leiaNLimSup(int);
void leituraReg(TProfissao &);
void leituraVetReg(int, TProfissao []);
string pegaNomeProf(int, TProfissao [], int);

int main(){
  TProfissao profissao[TMAX];
  string nomeprof;
    int codDesejado, n = leiaNLimSup(TMAX);
    leituraVetReg(n, profissao);
 do{
  cout<<"Digite o codigo a pesquisar (-1 sair)"<<endl;
  cin>>codDesejado;
    if(codDesejado > -1){
     nomeprof = pegaNomeProf(n,profissao,codDesejado);
     cout<<"Nome da profissao: "<< nomeprof<< endl;
    }
  }while(codDesejado>=0);
   return 0;
}

int leiaNLimSup (int limSup){
 int n;
 do{
 cout << "Qtde (max" << limSup << ") : " ; cin>>n;
 }while(n<=0 or n>limSup);
 return n;
}

void leituraReg(TProfissao &prof){
 cout<<"Dados da profissao - Codigo:";
 cin>> prof.codigo;
 cin.ignore();
 cout<<"Nome:";
 getline(cin,prof.nome);
}

void leituraVetReg(int n, TProfissao vetProf[]){
 for (int i=0; i<n; i++)
 leituraReg(vetProf[i]);
}

string pegaNomeProf(int n, TProfissao profissao[], int cod){
 int i=0;
 for (int i=0; i<n; i++)
 if(profissao[i].codigo == cod)
 return profissao[i].nome;
 return "nao encontrado"; // caso nao exista, retorna esta msg
}
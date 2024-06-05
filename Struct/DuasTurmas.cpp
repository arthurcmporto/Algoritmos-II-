#include <iostream>

using namespace std;

typedef struct {
string nome;
float notas[4], media;
}Aluno;

void InfoTurma(Aluno[]);
void CalculaMedia(Aluno[]);

int main(){

Aluno tA[20], tB[20];

cout << "==TURMA A=="<<endl;
InfoTurma(tA);
cout << "==TURMA B=="<<endl;
InfoTurma(tB);

CalculaMedia(tA);
CalculaMedia(tB);


    return 0;
}

void InfoTurma(Aluno tA[]){

 for(int i=0;i<2;i++){
    cout << "Nome do Aluno: ";
    getline(cin,tA[i].nome);

    for(int j=0;j<4;j++){
        cout << "Notas do aluno " << tA[i].nome << ": ";
        cin>>tA[i].notas[j];
    }
    cin.ignore();
 }
}

void CalculaMedia(Aluno tA[]){

 for(int i=0;i<2;i++){
    float soma=0;
    for(int j=0;j<4;j++){
        soma+=tA[i].notas[j]; 
    }
    tA[i].media = soma / 4;
    cout << tA[i].nome << " - " << tA[i].media << endl;
 }
}
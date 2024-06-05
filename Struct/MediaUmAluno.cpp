#include <iostream>

using namespace std;

typedef struct{
string nome;
float notas[4], media;
}Aluno;

void infoaluno(Aluno &estudante);
void calculamedia(Aluno estudante);

int main()
{
    Aluno estudante;

    infoaluno(estudante);
    calculamedia(estudante);

    return 0;
}


void infoaluno(Aluno &estudante){

        cout << "Nome do aluno: ";
        cin>> estudante.nome;

        for(int i=0;i<4;i++){
        cout << "Nota do aluno: ";
        cin >> estudante.notas[i];
        }
    }


void calculamedia(Aluno estudante){
float soma=0;

for(int i=0;i<4;i++){
    soma+=estudante.notas[i];
}

estudante.media= soma / 4;

cout << estudante.media;

}

#include <iostream>
#include <cstring>

using namespace std;

int main(){

int tam1, contRotacao=0;
bool achou = false;
char aux;
string palavra1, palavra2;

cout << "Digite uma String: ";
getline(cin,palavra1);
cout << "Digite outra String: ";
getline(cin,palavra2);


tam1=palavra1.size();

if(tam1!= palavra2.size())
 cout << "Estas palavras nao sao permutacoes circulares"<<endl;
else
 do{
    if(palavra1==palavra2)
     achou=true;
    else{
        aux=palavra2.at(0);
        for(unsigned int j=0;j<tam1-1;j++)
            palavra2[j]=palavra2[j+1];

            palavra2[tam1-1]=aux;
 }
 contRotacao++;
 }while(not achou and contRotacao<tam1);

 if(achou)
    cout<<"Estas palavras sao permutacoes circulares"<<endl<<endl;
 else
    cout<<"Estas palavras NAO sao permutacoes circulares"<<endl<<endl;

return 0;
}
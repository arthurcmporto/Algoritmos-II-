#include <iostream>
#include <cstring>

using namespace std;

int main(){

string palavra;
char L1, L2;

cout << "Digite uma Palavra: ";
getline(cin,palavra);

cout << "Digite uma letra: ";
L1=cin.get();

cin.ignore();
cout << "Digite outra letra: ";
L2=cin.get();

for(unsigned int i=0;i<palavra.size();i++){
    if(palavra[i]==L1){
        palavra[i]=L2;
    }
}
    cout << palavra;


return 0;
}
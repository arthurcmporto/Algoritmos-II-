#include <iostream>
#include <cstring>

using namespace std;

int main(){

string Palavra;

cout << "Digite uma Palavra: ";
getline(cin,Palavra);

for(int i=0; i<Palavra.size(); i++)
    if(Palavra[i]=='a')
     Palavra[i]='*';
    
    
for(int i=Palavra.size(); i>=0;i--)
    cout << Palavra[i];


return 0;
}
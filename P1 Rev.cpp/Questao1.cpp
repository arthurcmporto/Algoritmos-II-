#include <iostream>
#include <cstring>

using namespace std;

void PegaSubs(string a, string b, int p, int x);

int main(){


    string a,b;
    int p=0,x=0;

    cout << "Escreva uma String: ";
    getline(cin,a);

    cout << "Digite uma posicao: ";
    cin>>p;

    cout << "quantidade de caracteres: ";
    cin>>x;

     PegaSubs(a,b,p,x);

   
    return 0;
}

void PegaSubs(string a,string b, int p, int x){

    for(unsigned i=p; i<x+p && i<a.length(); i++){
        b+= a.at(i);
    }

    cout << b;
}
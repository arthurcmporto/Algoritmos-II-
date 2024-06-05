#include <iostream>
#include <cstring>

using namespace std;

int main(){

    string palavra;
    bool resp;

    cout << "Digite uma string: ";
    getline(cin,palavra);

    resp=true;
    
    if(!isalpha(palavra[0]))
        resp=false;
    else
        for(unsigned int i=0; i<palavra.size();i++)
         if(!isalpha(palavra.at(i)) and !isdigit(palavra.at(i)) and palavra.at(i)!='_'){
            resp=false;
            break;
         }
         if(resp)
            cout<<"Esta palavra eh identificador"<<endl;
         else
            cout<<"Esta palavra nao eh um identificador"<<endl;
         
    return 0;
}
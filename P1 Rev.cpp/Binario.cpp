#include <iostream>
#include <math.h>
using namespace std;

long int BinarioDecimal(string bin);


int main(){
string bin;

    cout << "Digite uma string: ";
    getline(cin,bin);

cout <<"numero binario: "<< bin;
cout<<endl;
cout <<"Numero decimal: " << BinarioDecimal(bin);

    return 0;
}

long int BinarioDecimal(string bin){
int decimal=0;
int power=0;

for(int i=bin.size()-1;i>=0;i--){
    if(bin[i]=='1'){
        decimal+=pow(2,power);
    }
    power++;
}
return decimal;

}
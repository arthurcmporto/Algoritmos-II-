#include <iostream>
#include <cstring>

using namespace std;

int main(){

string string;
int a, b, max, min;

cout << "Digite uma string: ";
getline(cin,string);

cout << "Digite um numero inteiro: ";
cin >> a;

cout << "Digite outro numero inteiro: ";
cin >> b;

max=a;
if(a<b){
 max=b;
 min=a;
}else
min=b;

for(unsigned int i=min; i<=max; i++)
 cout << string[i];




return 0;
}
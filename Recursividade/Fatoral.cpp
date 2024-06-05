#include <iostream>

using namespace std;

int Fatorial(int);

int main(){

int n;

cout << "Digite um numero inteiro: ";
cin>>n;

cout << "Fatorial de "<<n<<" eh: "<<Fatorial(n);

    return 0;
}

int Fatorial(int n){

if(n==0)
 return 1;

 return n*Fatorial(n-1);

}
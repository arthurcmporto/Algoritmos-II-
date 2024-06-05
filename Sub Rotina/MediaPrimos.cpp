#include <iostream>

using namespace std;

bool ehprimo(unsigned n);
int main(){

int soma=0,cont=0;

for(unsigned i=92; i<=1478;i++)
    if(ehprimo(i)){
        soma+=i;
        cont++;
    }

    cout <<"Quantidade de primos nesse intervalo"<<cont<<endl;
    cout<<"media: "<<soma/cont<<endl;

    return 0;
}

bool ehprimo(unsigned n){
    if(n<=1)
    return false;

    if(n==2 or n==3)
    return true;

    for(int i=2;i<=n/2;i++)
     if(n%i==0)
     return false;
     
     return true;

}
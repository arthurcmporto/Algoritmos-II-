#include <iostream>

using namespace std;

unsigned LeiaNumInteiro();
unsigned long Fatorial(int);
 
int main(){
    
    int n=LeiaNumInteiro();
    cout << "O fatorial de "<<n<< " eh: "<<Fatorial(n);

    return 0;
}

unsigned LeiaNumInteiro(){
    int num;
    do{
        cout <<"Digite um numero inteiro: ";
        cin >> num;
    }while(num<=0);
    return num;
}

unsigned long Fatorial(int n){
    int fatorial=1;

    for(int i=1;i<=n;i++)
        fatorial*=i;

    return fatorial;
}
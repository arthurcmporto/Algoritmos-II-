#include <iostream>

using namespace std;

unsigned LeiaNumInteiro();
unsigned long Fatorial(unsigned);
double expoente(unsigned);

int main(){
    cout<<"numero maximo de termos"<<endl;
    unsigned n=LeiaNumInteiro();

    for(unsigned i=1;i<=n;i++)
        cout << "E com "<<i<<" termos = "<<expoente(i)<<endl;

    return 0;
}

unsigned LeiaNumInteiro(){
    int num;
    do{
        cout << "digite o valor: ";
        cin >> num;
    }while(num<=0);
    return num;
}

unsigned long Fatorial(unsigned n){
    unsigned long fatorial=1;

    for(unsigned i=2;i<=n;i++)
        fatorial*=i;

    return fatorial;
}

double expoente(unsigned n){
double termo, soma=1.0;

    for(int i=2;i<=n;i++){
        termo=1.0/Fatorial(i-1);
        soma+=termo;
    }
return soma;
}
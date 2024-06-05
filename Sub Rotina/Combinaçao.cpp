#include <iostream>

unsigned LeiaNumInteiro();
unsigned long Fatorial(unsigned);
unsigned combinacional(unsigned, unsigned);
using namespace std;

int main(){
unsigned n,r;

    int num=LeiaNumInteiro();

        for(unsigned i=1;i<=num;i++){
            do{
            cout <<"informe o valor de n e r"<<endl;
             n=LeiaNumInteiro();
             r=LeiaNumInteiro();
            }while(r>n);
            cout <<"Combinacao: " << combinacional(n,r)<<endl;
        }

    return 0;
}

unsigned LeiaNumInteiro(){
    int num;
    do{
        cout <<"Informe valor: ";
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

unsigned combinacional(unsigned n, unsigned r){

    return Fatorial(n) / (Fatorial(r) * Fatorial(n-r));

}
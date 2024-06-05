#include <iostream>

using namespace std;

unsigned LeiaNumInteiro();
double potencia(float x, unsigned int y);

int main(){

float x;
int y,n;

cout << "Quantidade de pares" << endl;
n= LeiaNumInteiro();

for(int i=1;i<=n;i++){
    cout << "x (real) - informe valor: ";
     cin>>x;

    cout <<"y (inteiro positivo): "; 
    y=LeiaNumInteiro();

    cout << "potencia de "<<x << " na "<<y<<" = " << potencia(x,y)<<endl;
}


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

double potencia(float x, unsigned int y){
    double result = x;
    for(unsigned int i=2;i<=y;i++)
    result *=x;
    
    return result;
}
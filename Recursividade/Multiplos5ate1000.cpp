#include <iostream>

using namespace std;

int Somaate1000(int);

int main(){

 cout << Somaate1000(1000);
    return 0;
}

int Somaate1000(int n){

    if (n == 0) 
        return 0;
    
       return n+= Somaate1000(n - 5);
}

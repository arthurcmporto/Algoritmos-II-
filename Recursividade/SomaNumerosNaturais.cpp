#include <iostream>

using namespace std;

int SomaNaturais(int n);


int main(){

int n;

cout << "Numero inteiro: ";
cin>>n;

cout << SomaNaturais(n);
    return 0;
}

int SomaNaturais(int n){
    if(n==0){
        return 0;
    }

return n+=SomaNaturais(n-1);


}
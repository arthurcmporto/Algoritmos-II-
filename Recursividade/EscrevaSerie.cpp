#include <iostream>

using namespace std;

void escreserie(int n);

int main()
{
    int n;
    cout<<"n: ";
    cin >> n;
    escreserie(n);
    
    return 0;
}

void escreserie(int n){
    if(n==1){
        cout<<n;
    } else {
        escreserie(n-1);
        
        if(n%2==0){
        cout << n*n;
    } else {
        cout << n ;
    }
    
}
}
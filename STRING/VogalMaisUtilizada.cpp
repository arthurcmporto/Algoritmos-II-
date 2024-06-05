#include <iostream>
#include <cstring>

using namespace std;

int main(){

string frase;
char vogais[]={'a','e','i','o','u'}, vogalmaisfrequente;
int contvogais[5]={0};
int max=0;

cout << "Digite uma frase: ";
getline(cin,frase);

for(unsigned int i=0;i<frase.size();i++){
    for(int j=0;j<5;j++){
      if(frase[i] == vogais[j])
       contvogais[j]++;
    }
}

for(int i=0;i<5;i++){
    if(contvogais[i]>max){
        max=contvogais[i];
        vogalmaisfrequente = vogais[i];
    }
}

cout <<"vogal que mais apareceu foi: " << vogalmaisfrequente << "("<<max<<" "<<"vezes)"<<endl;
    return 0;

}
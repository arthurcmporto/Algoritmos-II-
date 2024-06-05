#include <iostream>

using namespace std;

int leiaNumInteiroIntervalo(int,int);
void CriaVets(int, int[]);
bool VerificaIgual(int,int[],int[]);

int main (){
    int vet1[10], vet2[10];
    int n = leiaNumInteiroIntervalo (1, 10);
    CriaVets(n,vet1);
    CriaVets(n,vet2);  
    
    if(VerificaIgual(n,vet1,vet2)){
        cout << "Os vetores sao iguais!";
    } else {
        cout << "Os vetores sao diferentes!";
    }
    
    
  return 0;
}

int leiaNumInteiroIntervalo (int inf, int sup){
  int n;
  do
    {
      cout << "Informe valor em [" << inf << "," << sup << "]: ";
      cin >> n;
      if (n < inf or n > sup)
	cout << "Nao esta no intervalo solicitado!! " << endl;
    }while (n < inf or n > sup);
    
  return n;
}

void CriaVets(int n, int vet[]){
    for(int i=0;i<n;i++){
        cout << "Valor: ";
        cin>>vet[i];
    }
    
}

bool VerificaIgual(int n, int vet1[], int vet2[]){
    if(n==0){
        if(vet1[n]==vet2[n])
            return true;
        else
            return false;
    }
    
    if(vet1[n-1]!=vet2[n-1]){
        return false;
     }else {
        return VerificaIgual(n-1,vet1,vet2);
    }
    
}

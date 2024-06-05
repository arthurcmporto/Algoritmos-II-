#include <iostream>

using namespace std;

int leiaNumInteiroIntervalo(int,int);
void CriaVet(int, int[]);
bool VerificaElem(int,int[],int);

int main (){
    int vet1[10], elem;
    int n = leiaNumInteiroIntervalo (1, 10);
    CriaVet(n,vet1);
    
      cout << "Digite um valor para buscar: ";
      cin>>elem;
    
    if(VerificaElem(n,vet1,elem)){
        cout << "elemento encontrado!";
    } else {
        cout << "elemento nao encontrado!";
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

void CriaVet(int n, int vet[]){
    for(int i=0;i<n;i++){
        cout << "Valor: ";
        cin>>vet[i];
    }
    
}

bool VerificaElem(int n, int vet1[], int elem){
    if(n==0){
        if(vet1[n]==elem)
            return true;
        else
            return false;
    }
    
    if(vet1[n-1]==elem){
        return true;
     }else {
        return VerificaElem(n-1,vet1,elem);
    }
    
}

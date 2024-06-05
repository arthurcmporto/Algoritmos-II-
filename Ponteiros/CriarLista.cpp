#include <iostream>
#include <cstdlib>

using namespace std;
typedef struct Nodo {
 int valor;
 struct Nodo *prox; // struct Nodo usa-se apenas internamente
} Tipolista;

int main() {
 Tipolista *ptraux, *ptrultimo, *lista = NULL;
 int i=0, x;

 do{
    ptraux= new Tipolista; // aloca memoria para o nodo
     if(ptraux==NULL){
      cout <<"Sem memoria"; cin.get(); exit(1); } // sai
      cout << "Valor: "; cin >> x;
      ptraux->valor=x; // ou (*ptraux).valor=x;
      cout << ptraux->valor << endl;
        if(lista==NULL)
         lista=ptraux;
        else
         ptrultimo->prox=ptraux;
         ptrultimo=ptraux;
    }while(++i<3);

 ptrultimo->prox=NULL; // importante FECHAR a lista

 do{
    ptraux=lista;
    cout << "Nodo no endereco: "<< ptraux;
    cout << "Valor " << ptraux->valor << endl;
    lista=lista->prox;
    delete ptraux;
 }while(lista!=NULL);


 return 0;
}
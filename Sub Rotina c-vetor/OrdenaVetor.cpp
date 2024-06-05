#include <iostream>
using namespace std;

int lerNumInteiroIntervalo(int linf, int lsup);
void CriaVetor(int num, int vet[]);
void OrdenaVetor(int num, int vet[]);
int main(){

    int num=lerNumInteiroIntervalo(1,10);
    int vet[num];
    CriaVetor(num,vet);
    cout<<endl;
    OrdenaVetor(num,vet);



    return 0;
}

int lerNumInteiroIntervalo(int linf, int lsup){
    int n;
    do
    {
        cout << "Qtde de elementos(" << linf << "-" << lsup << "): ";
        cin >> n;
    } while (n < linf or n > lsup);
    return n;
}

void CriaVetor(int num, int vet[]) {
    for (int i = 0; i < num; i++) {
        cout << "Valor: ";
        cin >> vet[i];
    }
    for (int i = 0; i < num; i++) {
        cout << vet[i] << " ";
    }
}

void OrdenaVetor(int num, int vet[]) {
    for (int i = 0; i < num - 1; i++) {
        for (int j = 0; j < num - i - 1; j++) {
            if (vet[j] > vet[j + 1]) {
                int aux = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = aux;
            }
        }
    }
    for (int j = 0; j < num; j++) {
        cout << vet[j] << " ";
    }
}
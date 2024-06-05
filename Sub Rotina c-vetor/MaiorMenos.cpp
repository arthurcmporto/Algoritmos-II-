#include <iostream>
using namespace std;

int lerNumInteiroIntervalo(int linf, int lsup);
void CriaVetor(int num, int vet[]);
int AchaMaior(int num, int vet[]);
int AchaMenor(int num, int vet[]);

int main() {
    int num = lerNumInteiroIntervalo(1, 15);
    int vet[num]; // Vetor para armazenar os valores

    CriaVetor(num, vet);
    cout << endl;
    cout << "MAIOR VALOR: " << "[" << AchaMaior(num, vet) << "]" << endl;
    cout << "MENOR VALOR: " << "[" << AchaMenor(num, vet) << "]" << endl;

    return 0;
}

int lerNumInteiroIntervalo(int linf, int lsup) {
    int n;
    do {
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

int AchaMaior(int num, int vet[]) {
    int maior = vet[0];

    for (int i = 1; i < num; i++)
        if (vet[i] > maior)
            maior = vet[i];

    return maior; 
}

int AchaMenor(int num, int vet[]) {
    int menor = vet[0];

    for (int i = 1; i < num; i++)
        if (vet[i] < menor)
            menor = vet[i];

    return menor; 
}

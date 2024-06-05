#include <iostream>
using namespace std;

int lerNumInteiroIntervalo(int linf, int lsup);
void NomesNotas(int n, string nomes[], float notas[]);
float mediaturma(int n, float notas[]);
void acimamedia(int n, float notas[], string nomes[], float media);
int abaixomedia(int n, float notas[], float media);

int main()
{
    string nomes[20];
    float notas[20];

    cout << "Quantidade de alunos: " << endl;
    int n = lerNumInteiroIntervalo(1, 20);

    NomesNotas(n, nomes, notas);
    float media = mediaturma(n, notas);
    cout << "MEDIA DAS NOTAS: " << media << endl;

    cout << "ALUNOS ACIMA DA MEDIA: ";
    acimamedia(n, notas, nomes, media);

    cout << endl;

    cout << "ALUNOS ABAIXO DA MEDIA: " << abaixomedia(n, notas, media);

    return 0;
}

int lerNumInteiroIntervalo(int linf, int lsup)
{
    int n;
    do
    {
        cout << "Qtde de elementos(" << linf << "-" << lsup << "): ";
        cin >> n;
    } while (n < linf or n > lsup);
    return n;
}

void NomesNotas(int n, string nomes[], float notas[])
{
    cin.ignore(); 
    for (int i = 0; i < n; i++)
    {
        cout << "Nome do aluno: " << endl;
        getline(cin, nomes[i]);

        cout << "Nota do aluno: " << endl;
        cin >> notas[i];
        cin.ignore(); 
    }
}

float mediaturma(int n, float notas[])
{
    float soma = 0;
    for (int i = 0; i < n; i++)
    {
        soma += notas[i];
    }
    return soma / n;
}

void acimamedia(int n, float notas[], string nomes[], float media)
{
    for (int i = 0; i < n; i++)
    {
        if (notas[i] >= media)
        {
            cout << nomes[i] << " ";
        }
    }
}

int abaixomedia(int n, float notas[], float media)
{
    int abaixo = 0;
    for (int i = 0; i < n; i++)
    {
        if (notas[i] < media)
        {
            abaixo++;
        }
    }
    return abaixo;
}

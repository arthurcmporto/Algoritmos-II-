#include <iostream>
#include <cctype>
#include <cstring>
#include <ctime>

using namespace std;

typedef struct{
    string data;
    string diaSemana[5] = {"Segunda","Terca","Quarta","Quinta","Sexta"};
    string hora[7];
    string tipo[7];
    string nome[7];
    string retorno[7];
}Semana;

//SUB ROTINAS PRINCIPAIS
void iniciaSemana(Semana agendaSemana[],int contaDia[]);
void incluirConsulta(Semana agendaSemana[],int contaDia[]);
void exclueConsulta(Semana agendaSemana[], int contDia[]);
void relatorio2(Semana agendaSemana[], int contaDia[]);
void relatorioDia(Semana agendaSemana[],int contaDia[]);

// SUB ROTINAS AUXILIARES
bool validaData(string data);
bool validaHora(string busca);
bool checaHorario(string hora);
bool verificaNum(string x, string minN, string maxN);
int encontraDataR(string dia, int numSem, Semana agendaSemana[]);
int buscaDataRec(string dia, int numSem, Semana agendaSemana[]);
int buscaCompRec(string hrInicial, int numSem, int consEncontrada, Semana agendaSemana[], int contaDia[]);
void exclueCompRec(int numSem, int contaDia[], int compEncontrado, Semana agendaSemana[]);

void armazenaTipo(string tipo, Semana agendaSemana[], int numSem, int contaDia[]);
void armazenaRet(string ret, Semana agendaSemana[], int numSem, int contaDia[]);

int main()
{
    Semana agendaSemana[5];
    int opcao,contaDia[5]={0};
    while(opcao !=6){
    cout<<" ------ AGENDA DA SEMANA ------ "<<endl;
    cout<<"1) Nova semana. "<<endl;
    cout<<"2) Nova Consulta. "<<endl;
    cout<<"3) Excluir Consulta. "<<endl;
    cout<<"4) Consultar Dia. "<<endl;
    cout<<"5) Relatorio Geral. "<<endl;
    cout<<"6) Sair. "<<endl;
    cout<<endl<<"Opcao: ";
    cin>>opcao;



   switch(opcao){
    case 1:
       iniciaSemana(agendaSemana,contaDia);
       break;
    case 2:
        incluirConsulta(agendaSemana,contaDia);
        break;
    case 3:
        exclueConsulta(agendaSemana,contaDia);
        break;
    case 4:
        relatorioDia(agendaSemana,contaDia);
        break;
    case 5:
        relatorio2(agendaSemana,contaDia);
   }
}
    return 0;
}
void iniciaSemana(Semana agendaSemana[],int contaDia[]){
char confirma;
bool verif;
string data;
    system("cls");
    cout<<"Deseja abrir uma nova semana?"<<endl;
    cout<<"ATENCAO - Vai perder uma agenda caso ja exista!"<<endl;
    cout <<"S/N: ";
    cin>> confirma;
    if(toupper(confirma)=='S'){
    cin.ignore();
        for(int i=0;i<5;i++){
        contaDia[i] =0;
        for(int j=0;j<7;j++){
                agendaSemana[i].hora[j] = {""};
                agendaSemana[i].tipo[j] = {""};
                agendaSemana[i].nome[j] = {""};
                agendaSemana[i].retorno[j] = {""};
            }
        }

    do{
        cout<<"_____________________________________"<<endl;
        cout<<endl<<"Digite o dia em que a semana se inicia (DD/MM/AAAA): ";
        getline(cin,data);
        verif = validaData(data);
    }while(verif == false);
    agendaSemana[0].data = data;
    cout<<"Agenda da semana iniciada."<<endl;

    }
}

bool validaData(string data){

    int dia,mes,ano;

    if(data.size() !=10 )
        return false;

    if(data[2]!='/' || data[5] != '/')
        return false;

    dia = stoi(data.substr(0,2));
    mes = stoi(data.substr(3,2));
    ano = stoi(data.substr(6,4));


    if (mes <1 || mes >12)
        return false;

    if (dia <1 || dia > 31)
        return false;


    if((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia >30)
        return false;

    if (mes == 2 && dia >28)
        return false;

    if(ano <0)
        return false;

    return true;

}

void incluirConsulta(Semana agendaSemana[],int contaDia[]){
    string dia,hora,tipo,ret;
    int numSem = 5, cont =0;
    bool verif,verif2,verifH,verifica;

    system("cls");
    cin.ignore();
    cout<<endl<<"Dia da Consulta(DD/MM/AAAA): ";
    getline(cin,dia);
    numSem = encontraDataR(dia,numSem,agendaSemana);
    if(numSem <0){
        cout<<"Dia invalido."<<endl;
    }else{
        do{
            system("cls");
            cout<<"Horario da Consulta (**h**): ";
            getline(cin,hora);
            verif = validaHora(hora);
            verifH = checaHorario(hora);
        }while(verif == false || verifH == false);
            cout<<endl<<"Nome do Paciente: ";
            getline(cin,agendaSemana[numSem].nome[contaDia[numSem]]);
        do{
            cout<<endl<<"Consulta eh por:"<<endl;
            cout<<"1 - Particular"<<endl;
            cout<<"2 - Convenio"<<endl;
            cout<<"Opcao: ";
            cin>>tipo;
            verif = verificaNum(tipo,"1","2");
        }while(verif == false);
        armazenaTipo(tipo,agendaSemana,numSem,contaDia);
        do{
            cout<<endl<<"Eh retorno:"<<endl;
            cout<<"1 - Sim"<<endl;
            cout<<"2 - Nao"<<endl;
            cout<<"Opcao: ";
            cin>>ret;
            verif2 = verificaNum(ret,"1","2");
        }while(verif == false);
        armazenaRet(ret,agendaSemana,numSem,contaDia);
        agendaSemana[numSem].hora[contaDia[numSem]] = hora;
        cont = contaDia[numSem];
        contaDia[numSem]++;
        cout << "Consulta adicionada com Sucesso!"<<endl;
    }
}

int encontraDataR(string dia, int numSem, Semana agendaSemana[]) {
    if (numSem < 0) {
        return -1; 
    }

    if (dia == agendaSemana[numSem].data) {
        return numSem; 
    }

    return encontraDataR(dia, numSem - 1, agendaSemana); 
}

bool verificaNum(string x, string minN, string maxN){
    int num, menor, maior;
    if(x == "")
        return false;
    else
    if(!isdigit(x.at(0)))
        return false;
    num = atoi(x.c_str());
    menor = atoi(minN.c_str());
    maior = atoi(maxN.c_str());
    if(num<menor or num>maior)
            return false;
    return true;
}
void armazenaTipo(string tipo, Semana agendaSemana[], int numSem, int contaDia[]){
    if(tipo == "1")
        agendaSemana[numSem].tipo[contaDia[numSem]] = "Particular.";
    else
        if(tipo == "2")
            agendaSemana[numSem].tipo[contaDia[numSem]] = "Convenio.";
}
void armazenaRet(string ret, Semana agendaSemana[], int numSem, int contaDia[]){
    if(ret == "1")
        agendaSemana[numSem].retorno[contaDia[numSem]] = "Sim.";
    else
        if(ret == "2")
            agendaSemana[numSem].retorno[contaDia[numSem]] = "Nao.";
}
bool checaHorario(string hora){
    int horas = stoi(hora.substr(0, 2));
    int minutos = stoi(hora.substr(3, 2));
    if (horas < 8 || horas > 12 || minutos < 0 || minutos > 59) {
        return false;
    }

    return true;
}
bool validaHora(string busca){
    if(busca == ""){
        return false;
    }
    if(busca.size() != 5){
        return false;
    }
    if(!isdigit(busca.at(0)) and !isdigit(busca.at(1)) and !isdigit(busca.at(3)) and !isdigit(busca.at(4))){
       return false;
    }
    if(busca.at(2) != 'h')
        return false;

    return true;
}

void relatorioDia(Semana agendaSemana[],int contaDia[]){
string dataBusca;
int diaSem =5;

    system("cls");
    cin.ignore();
    cout<<"Dia que deseja ver os compromissos (DD/MM/AAA: ";
    getline(cin,dataBusca);
    diaSem = encontraDataR(dataBusca,diaSem,agendaSemana);
    if(diaSem <0){
        cout <<"Dia da Semana invalido";
    }else{
        if(contaDia[diaSem]<=0){
            cout<<"Dia sem Compromisso.";
        }else{
            cout << "_____ RELATORIO _____" <<endl;
            cout<<agendaSemana[diaSem].data<<endl;
            cout<<endl;
            cout<<"Dia: "<< agendaSemana[diaSem].diaSemana[diaSem] << endl;
            cout<<endl;
            for(int i=0; i<contaDia[diaSem]; i++){
                cout << "-------------------------------------" << endl;
                cout << "Paciente: " << agendaSemana[diaSem].nome[i] << endl;
                cout << "Hora: " << agendaSemana[diaSem].hora[i] << endl;
                cout << "Tipo: " << agendaSemana[diaSem].tipo[i] << endl;
                cout << "Retorno?: " << agendaSemana[diaSem].retorno[i] << endl;

                cout << "-------------------------------------" << endl;
            }
        }
    }
}

void exclueConsulta(Semana agendaSemana[], int contDia[]) {
    string dataEx, horario;
    int consEncontrada, numSem=5;
    bool verif;

    system("cls");
    cin.ignore();
    cout << "Dia para excluir compromisso [xx/xx/xxxx]: ";
    getline(cin, dataEx);
    numSem = buscaDataRec(dataEx, numSem, agendaSemana);
    if (numSem < 0) {
        cout << "Dia da semana Inválido!";
        getchar();
    } else {
        consEncontrada = contDia[numSem] - 1;
        do {
            system("cls");
            cout << "----------------------------------------------------" << endl;
            cout << "Horario que deseja excluir o compromisso [xxhxx]: ";
            getline(cin, horario);
            verif = validaHora(horario); 
            system("cls");
            cout << "----------------------------------------------------" << endl;
        } while (!verif);
        consEncontrada = buscaCompRec(horario, numSem, consEncontrada, agendaSemana, contDia);
        if (consEncontrada < 0) {
            cout << "Horário Inexistente!" << endl;
            getchar();
        }
        if (consEncontrada >= 0){
            exclueCompRec(numSem, contDia, consEncontrada, agendaSemana);
            cout << "Horario Excluido!";
            getchar();
        }
    }
}

int buscaDataRec(string dia, int numSem, Semana agendaSemana[]) {
    if (numSem < 0)
        return -1;

    if (dia == agendaSemana[numSem].data)
        return numSem;

    return buscaDataRec(dia, numSem - 1, agendaSemana);
}

int buscaCompRec(string hrInicial, int numSem, int consEncontrada, Semana agendaSemana[], int contaDia[]) {
    if (consEncontrada < 0)
        return -1;
    if (hrInicial == agendaSemana[numSem].hora[consEncontrada]) {
        return consEncontrada;
    }

    return buscaCompRec(hrInicial, numSem, consEncontrada - 1, agendaSemana, contaDia);
}

void exclueCompRec(int numSem, int contaDia[], int compEncontrado, Semana agendaSemana[]) {
    if (compEncontrado >= 0) {
        for (int i = compEncontrado; i < contaDia[numSem]; i++) {
            agendaSemana[numSem].nome[i] = agendaSemana[numSem].nome[i + 1];
            agendaSemana[numSem].hora[i] = agendaSemana[numSem].hora[i + 1];
            agendaSemana[numSem].tipo[i] = agendaSemana[numSem].tipo[i + 1];
            agendaSemana[numSem].retorno[i] = agendaSemana[numSem].retorno[i + 1];
        }
    }
    agendaSemana[numSem].nome[contaDia[numSem] - 1] = "";
    agendaSemana[numSem].hora[contaDia[numSem] - 1] = "";
    agendaSemana[numSem].tipo[contaDia[numSem] - 1] = "";
    agendaSemana[numSem].retorno[contaDia[numSem] - 1] = "";
    contaDia[numSem]--;
}

void relatorio2(Semana agendaSemana[], int contaDia[]){
    system("cls");
    for(int i=0; i<5; i++){
        cout << agendaSemana[i].data << endl;
        cout << "Dia: " << agendaSemana[i].diaSemana[i] << endl;
        if(contaDia[i] <=0){
            cout <<  "-------------------------------------" << endl;
            cout <<  "Dia sem compromissos!" << endl;
            cout <<  "-------------------------------------" << endl;
            getchar();
        }
        for(int j=0; j<contaDia[i]; j++){
            cout << "-------------------------------------" << endl;
            cout << "Hora Inicial: " << agendaSemana[i].hora[j] << endl;
            cout << "Nome: " << agendaSemana[i].nome[j] << endl;
            cout << "Tipo: " << agendaSemana[i].tipo[j] << endl;
            cout << "Retorno: " << agendaSemana[i].retorno[j] << endl;
            cout << "-------------------------------------" << endl;
            getchar();
        }
        getchar();
        system("cls");
    }
}
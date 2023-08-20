#include <iostream>
#include <vector>

using namespace std;

struct Mes
{
    int num;
    string nome;
    string abrv;
    int numDias;

    void insere(int numMes, string nomeMes, string abrvMes, int numDiasMes)
    {
        num = numMes;
        nome = nomeMes;
        abrv = abrvMes;
        numDias= numDiasMes;
    }
};

bool verificaBissexto(int a);
int calculaDias(vector<Mes> &v, int m, int d);
void mostra(vector<Mes> &v, int m, int d, int a);

int main()
{
    setlocale(LC_ALL, "portuguese");

    int ano, mes ,dia;
    Mes janeiro, fevereiro, marco, abril, maio, junho, julho, agosto, setembro, outubro, novembro, dezembro;
    vector<Mes> meses;
    bool teste;

    janeiro.insere(1, "Janeiro", "jan", 31);
    fevereiro.insere(2, "Fevereiro", "fev", 28);
    marco.insere(3, "Março", "mar", 31);
    abril.insere(4, "Abril", "abr", 30);
    maio.insere(5, "Maio", "mai", 31);
    junho.insere(6, "Junho", "jun", 30);
    julho.insere(7, "Julho", "jul", 31);
    agosto.insere(8, "Agosto", "ago", 31);
    setembro.insere(9, "Setembro", "set", 30);
    outubro.insere(10, "Outubro", "out", 31);
    novembro.insere(11, "Novembro", "nov", 30);
    dezembro.insere(12, "Dezembro", "dez", 31);

    do
    {
        cout << "Informe o ano: ";
        cin >> ano;
        fflush(stdin);

        if(verificaBissexto(ano))
            fevereiro.numDias = 29;

        teste = true;

        cout << "Informe o mes: ";
        cin >> mes;
        fflush(stdin);

        cout << "Informe o dia: ";
        cin >> dia;
        fflush(stdin);

        if((mes > 12 || mes < 1) || (dia < 1 || dia > 31))
        {
            cout << "\nERRO: Mês e/ou dia inválidos!";
            getchar();
            system("cls");

            teste = false;
        }

    }while(!teste);

    meses.reserve(12);
    meses.push_back(janeiro);
    meses.push_back(fevereiro);
    meses.push_back(marco);
    meses.push_back(abril);
    meses.push_back(maio);
    meses.push_back(junho);
    meses.push_back(julho);
    meses.push_back(agosto);
    meses.push_back(setembro);
    meses.push_back(outubro);
    meses.push_back(novembro);
    meses.push_back(dezembro);

    mostra(meses, mes, dia, ano);

    return 0;
}

bool verificaBissexto(int a)
{
    if(a%400==0)
        return true;
    else
    {
        if(a%4==0 && a%100!=0)
            return true;
        else
            return false;
    }
}

int calculaDias(vector<Mes> &v, int m, int d)
{
    int diasTranscorridos = 0;
    diasTranscorridos += d;

    for(int i =0; i < v.size(); i++)
    {
        if(m == v[i].num)
        {
            for(int j = i -1; j >= 0; j--)
                diasTranscorridos += v[j].numDias;
        }
    }

    return diasTranscorridos;
}

void mostra(vector<Mes> &v, int m, int d, int a)
{
    cout << "\nTotal de dias transcorridos no ano de " << a << ": " << calculaDias(v, m, d) << "\n";
    cout << "Dia informado.............................: " << d << "\n";
    cout << "Mes informado.............................: " << m << "\n";
    cout << "Nome do mes...............................: " << v[m-1].nome << "\n";
    cout << "Abreviatura do mes........................: " << v[m-1].abrv << "\n";
    cout << "Total de dias do mes......................: " << v[m-1].numDias << "\n";
}

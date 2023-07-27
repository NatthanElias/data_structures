#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct Conta
{
    int num;
    string nome;
    float saldo;

    void insere(int cnum, string cnome, float csaldo)
    {
        num = cnum;
        nome = cnome;
        saldo = csaldo;
    }
};

bool validaNumConta(vector<Conta> &v, int n, int &i);
void cadastrar(vector<Conta> &v);
void visualizar(vector<Conta> &v);
void depositar(vector<Conta> &v);
void sacar(vector<Conta> &v);
void fazPix(vector<Conta> &v);

int main()
{
    setlocale(LC_ALL, "portuguese");

    int menu;
    vector<Conta> contas;
    contas.reserve(10);

    do
    {
        cout << "#############Menu#############\n";
        cout << "1- Cadastrar contas\n";
        cout << "2- Visualizar dados da conta\n";
        cout << "3– Depositar\n";
        cout << "4– Sacar\n";
        cout << "5– Pix\n";
        cout << "6– Sair\n";
        cin >> menu;
        fflush(stdin);
        system("cls");

        switch(menu)
        {
            case 1:
                cadastrar(contas);
                break;
            case 2:
                visualizar(contas);
                break;
            case 3:
                depositar(contas);
                break;
            case 4:
                sacar(contas);
                break;
            case 5:
                fazPix(contas);
                break;
            case 6:
                break;
            default:
                cout << "ERRO: Opcao invalida!";
                getchar();
                system("cls");
        }

    } while(menu != 6);

    return 0;
}

bool validaNumConta(vector<Conta> &v, int n, int &i)
{
    for( i; i < v.size(); i++)
    {
        if(n == v[i].num)
            return true;
    }
    return false;
}

void cadastrar(vector<Conta> &v)
{
    Conta c;
    int n;
    string name;
    float s;

    if(v.size() < 10)
    {
        int i = 0;

        cout << "Informe o numero da conta(8 digitos): ";
        cin >> n;
        fflush(stdin);

        cout << "\nInforme o nome do cliente: ";
        getline(cin, name);
        fflush(stdin);

        cout << "\nInforme o saldo da conta: ";
        cin >> s;
        fflush(stdin);

        system("cls");

        if(!validaNumConta(v, n, i))
        {
            c.insere(n, name, s);
            v.push_back(c);
        }
        else
        {
            cout << "ERRO: Numero de conta ja existente!\n";
            getchar();
            system("cls");
        }
    }
    else
    {
        cout << "\nERRO: Numero maximo de contas excedido!\n";
        getchar();
        system("cls");
    }

}

void visualizar(vector<Conta> &v)
{
    int n, indice = 0;

    cout << "Informe o numero da conta(8 digitos): ";
    cin >> n;
    fflush(stdin);

    if(validaNumConta(v, n, indice))
    {
        cout << "----------------------------" << endl;
        cout << "Conta: " << v[indice].num << endl;
        cout << "Cliente: " << v[indice].nome << endl;
        cout << "Saldo: " << v[indice].saldo << endl;
        cout << "----------------------------" << endl;
        getchar();
        system("cls");
    }
    else
    {
        cout << "\nERRO: Numero de conta informado é invalido!\n";
        getchar();
        system("cls");
    }
}

void depositar(vector<Conta> &v)
{
    int n, d, indice = 0;

    cout << "Informe o numero da conta(8 digitos): ";
    cin >> n;
    fflush(stdin);

    cout << "Informe o valor a ser depositado: ";
    cin >> d;
    fflush(stdin);

    if(validaNumConta(v, n, indice))
    {
         v[indice].saldo += d;
         system("cls");
    }
    else
    {
        cout << "\nERRO: Numero de conta informado é invalido!\n";
        getchar();
        system("cls");
    }
}

void sacar(vector<Conta> &v)
{
    int n, s, indice = 0;

    cout << "Informe o numero da conta(8 digitos): ";
    cin >> n;
    fflush(stdin);

    cout << "Informe o valor a ser sacado: ";
    cin >> s;
    fflush(stdin);

    if(validaNumConta(v, n, indice))
    {
        if(s > 0 && s != 3 && s != 1)
        {
            v[indice].saldo -= s;
            system("cls");
        }
        else
        {
            cout << "ERRO: Valor de saque invalido! Informe um valor maior que 0 e diferente de 1 e 3";
            getchar();
            system("cls");
        }
    }
    else
    {
        cout << "\nERRO: Numero de conta informado é invalido!\n";
        getchar();
        system("cls");
    }
}

void fazPix(vector<Conta> &v)
{
    int n1, n2, indice1 = 0, indice2 = 0;
    float p;

    cout << "Informe o numero da conta de origem(8 digitos): ";
    cin >> n1;
    fflush(stdin);

    cout << "Informe o numero da conta de destino(8 digitos): ";
    cin >> n2;
    fflush(stdin);

    cout << "Informe o valor do pix: ";
    cin >> p;
    fflush(stdin);

    if(validaNumConta(v, n1, indice1) && validaNumConta(v, n2, indice2))
    {
        if(v[indice1].saldo > 0.00)
        {
            v[indice1].saldo -= p;
            v[indice2].saldo += p;
            system("cls");
        }
        else
        {
            cout << "\nERRO: Saldo negativo!\n";
            getchar();
            system("cls");
        }
    }
    else
    {
        cout << "\nERRO: Numero de uma das contas informado é invalido!\n";
        getchar();
        system("cls");
    }
}

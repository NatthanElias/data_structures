#include <iostream>

using namespace std;

void lerValor(int &v);
void mostraValor(int q[], int c[], int v);
void sacarValor(int v, int q[], int c[], int i);

int main()
{
    setlocale(LC_ALL, "portuguese");

    int cedulas[6] = {100, 50, 20, 10, 5, 2};
    int valor, qtd[6] = {};
    bool testeErro;

    do
    {
    testeErro = false;
    lerValor(valor);

    int i =0;

    if(valor == 0)
    {
        cout << "\nERRO: O valor não pode ser 0.\n";
        getchar();
        system("cls");
        testeErro = true;
    }
    else if(valor == 3 || valor == 1)
    {
        cout << "\nERRO: Insira um valor maior que 1 e diferente de 3.\n";
        getchar();
        system("cls");
        testeErro = true;
    }
    else
    {
        sacarValor(valor, qtd, cedulas, i);
        mostraValor(qtd, cedulas, valor);
    }
    }while(testeErro == true);

    return EXIT_SUCCESS;
}

void lerValor(int &v)
{
    cout << "Informe o valor a ser sacado: ";
    cin >> v;
    fflush(stdin);
}

void sacarValor(int v, int q[], int c[], int i)
{
    while(v > 0)
    {
        int res = 0;

        res = v/c[i];

        if(res > 0)
        {
            v = v - c[i];
            q[i]++;
            if(v < 5)
            {
                if(v%2==0)
                {
                    while(v > 0)
                    {
                        q[5]++;
                        v = v - c[5];
                    }
                    return;
                }
                else
                {
                    v = v + c[i];
                    q[i]--;
                    i++;
                }
            }
        }
        else
            i++;
    }
}

void mostraValor(int q[], int c[], int v)
{
    cout << "\nSaque " << v << ",00: ";
    for(int i=0; i<6; i++)
    {
        if(q[i] > 0)
        {
             cout << q[i] << " NOTA(S) DE " << c[i] << ", ";
        }
    }
    cout << "\n";
}

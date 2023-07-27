#include <iostream>
#include <ctime>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

void geraVec(vector<int> **v, int **n, int **v1);
void localiza(vector<int> **v, vector<int> **sobra, int **n);
void mostraVet(vector<int> **v);
void mostraSobra(vector<int> **s);

int main()
{
    setlocale(LC_ALL, "portuguese");
    srand(time(NULL));

    int *n = new int;
    int *menu = new int;
    vector<int> *vec = new vector<int>;
    vector<int> *sobra = new vector<int>;
    int *vet1 = new int[*n];
    bool *teste = new bool(false);
    bool *teste2 = new bool(false);

    do
    {
        system("cls");
        cout << "####MENU####\n";
        cout << "0 – Sair\n";
        cout << "1 – Gerar valores para o vetor\n";
        cout << "2 – Localiza valor\n";
        cout << "3 – Mostra elementos do vetor vet\n";
        cout << "4 – Mostrar elementos do vetor sobra\n";
        cin >> *menu;
        fflush(stdin);

        switch(*menu)
        {
            case 0:
                system("cls");
                cout << "Programa finalizado!\n";
                break;
            case 1:
                system("cls");
                *teste = true;
                geraVec(&vec, &n, &vet1);
                cout << "Vetor gerado!";
                getchar();
                break;
            case 2:
                system("cls");
                if(*teste)
                {
                    localiza(&vec, &sobra, &n);
                    *teste2 = true;
                }
                else
                    cout << "Primeiro gere o vetor (opção 1)!";
                getchar();
                break;
            case 3:
                system("cls");
                if(*teste)
                    mostraVet(&vec);
                else
                    cout << "Primeiro gere o vetor (opção 1)!";
                getchar();
                break;
            case 4:
                system("cls");
                if(*teste2)
                    mostraSobra(&sobra);
                else
                    cout << "Primeiro gere o vetor sobra(opção 2)!";
                getchar();
                break;
            default:
                system("cls");
                cout << "Opção inválida!";
                getchar();
                break;
        }

    } while((*menu) != 0);

    return 0;
}

void geraVec(vector<int> **v, int **n, int **v1)
{
    (**v).clear();

    cout << "Informe  a dimensão do vetor: ";
    cin >> **n;
    fflush(stdin);

    if(**n <= 50 && **n >= 5)
    {
        int *i = new int(0);
        int *j = new int(0);
        int *igual = new int(0);

        //cout << "\n\n" << **n;

        /*for(*i; *i < **n; (*i)++)
        {
            (*v)->push_back(rand()%10);

            //cout << "\nteste\n";
            for(*j; *j < *i; (*j)++)
            {
                //cout << "\nteste\n";
                    //cout << "\nteste\n";
                    while( ((*v)->begin() + *j) == ((*v)->begin() + *i))
                    {
                        //cout << "\nteste\n";
                    (*v)[*j].pop_back();
                    (*v)[*j].push_back(rand()%10);
                    }
            }
            *j = 0;
        }*/

        do
        {
            *(*v1 + *i) = rand() % 49+1;
            *igual = 0;
            *j = 0;
            //cout << "\nteste\n";
            for(*j; *j < *i; (*j)++)
            {
                if( *(*v1 + *j) == *(*v1 + *i))
                    *igual = 1;
                else
                    *igual = 0;
            }

            if(*igual == 0)
                (*i)++;

        }while(*i < **n);

        //(*v1) -= **n;
        *i = 0;

        for(*i; *i < **n ; (*i)++)
        {
            //cout << **v1 << ", ";
            //(*v1)++;
            (*v)->push_back(**v1);
            (*v1)++;
        }

        /*cout <<  endl << endl << (*v)->size() << endl;

        cout << "\nVetor: ";
        for(auto it =(**v).begin(); it!= (**v).end(); it++)
        {
            cout << *it << ", ";
        }
        cout << endl;*/
    }
    else
    {
        cout << "Dimensão inválida!";
        getchar();
    }

}

void localiza(vector<int> **v, vector<int> **sobra, int **n)
{
    int *k = new int;
    int *i = new int(0);

    cout << "Informe o valor: ";
    cin >> *k;

    auto it = find((**v).begin(), (**v).end(), *k);

    if(*it >= 1 && *it <= 50)
    {
        cout << "Valor " << *it << ", pertence ao vetor e está no endereço de memoria " << &it << endl;
        getchar();
    }
    else
    {
        cout << "Não pertence ao vetor!";
        getchar();
        if((**sobra).size() > **n)
            (**sobra).clear();
        else
            (*sobra)->push_back(*k);
    }

    cout << "\nVetor sobra: ";
    for(auto it2 =(**sobra).begin(); it2!= (**sobra).end(); it2++)
    {
        cout << *it2 << ", ";
    }
}

void mostraVet(vector<int> **v)
{
    cout << "Vetor vet: ";
    for(auto it =(**v).begin(); it!= (**v).end(); it++)
    {
        cout << *it << ", ";
    }
}

void mostraSobra(vector<int> **s)
{
    cout << "Vetor sobra: ";
    for(auto it =(**s).begin(); it!= (**s).end(); it++)
    {
        cout << *it << ", ";
    }
}

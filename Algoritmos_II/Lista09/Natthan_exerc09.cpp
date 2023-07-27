#include <iostream>
#include <ctime>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

void leia(int **n1, int **n2);
void geraVet(int **n1, int **n2, int **v1, int **v2);
void interseccao(int **v1, int **v2, int **n1, int **n2, vector<int> **px3);

main()
{
    setlocale(LC_ALL, "portuguese");
    srand(time(NULL));
    int *tamVetor1 = new int;
    int *tamVetor2 = new int;
    vector<int> *x3 = new vector<int>;

    leia(&tamVetor1, &tamVetor2);

    int *vetor1 = new int[*tamVetor1];
    int *vetor2 = new int[*tamVetor2];

    geraVet(&tamVetor1, &tamVetor2, &vetor1, &vetor2);
    interseccao(&tamVetor1, &tamVetor2, &vetor1, &vetor2, &x3);

    return 0;
}

void leia(int **n1, int **n2)
{
    cout << "Informe a quantidade de elementos do vetor 1: ";
    cin >> **n1;
    fflush(stdin);

    cout << "Informe a quantidade de elementos do vetor 2: ";
    cin >> **n2;
    fflush(stdin);
}


void geraVet(int **n1, int **n2, int **v1, int **v2)
{
    int *i = new int(0);
    int *j = new int(0);
    int *igual = new int(0);

    do
    {
        *(*v1 + *i) = rand() % ((**n1)*(**n2));
        *igual = 0;
        *j = 0;
        for(*j; *j < *i; (*j)++)
        {
            if( *(*v1 + *j) == *(*v1 + *i))
                *igual = 1;
        }

        if(*igual == 0)
            (*i)++;

    }while(*i < **n1);


    *i = 0;
    *j = 0;
    *igual = 0;

    do
    {
        *(*v2 + *i) = rand() % ((**n1)*(**n2));
        *igual = 0;
        *j = 0;
        for(*j; *j < *i; (*j)++)
        {
            if( *(*v2 + *j) == *(*v2 + *i))
                *igual = 1;
        }

        if(*igual == 0)
            (*i)++;

    }while(*i < **n2);

    *i = 0;

    cout << "x1: ";
    for (*i; *i < **n1; (*i)++)
    {
           cout << **v1 << ", ";

           (*v1)++;
    }
    *j = 0;

    cout << "\nx2: ";
    for (*j; *j < **n2; (*j)++)
    {
           cout << **v2 << ", ";

           (*v2)++;
    }

    *v1 -= *i;
    *v2 -= *j;
}


void interseccao(int **n1, int **n2, int **v1, int **v2, vector<int> **px3)
{
    int *i = new int(0);
    int *j = new int(0);

    for (*i; *i < **n1; (*i)++)
    {


        for(*j; *j < **n2; (*j)++)
        {
            //cout << "\n\n" << **v1 << "\n";
            if ((**v1) == (**v2))
            {

                (*px3)->push_back(**v1);
            }
            (*v2)++;
        }
        (*v1)++;
        (*v2) -= *j;
        *j =0;
    }

    *i = 0;

    /*sort( (**px3).begin(), (**px3).end() );
    auto x = unique( (*px3)->begin(), (*px3)->end() );// x eh ponteiro
    (*px3)->resize(distance( (*px3)->begin(),x ));*/

    cout << "\n\nx3: ";
    for(auto it =(**px3).begin(); it!= (**px3).end(); it++)
    {
        cout << *it << ", ";
    }

    /*cout << "\n\n" << (**px3).size();
    cout << "\n\nx3: ";
    for (i; *i < (**px3).size(); (*i)++)
    {
           cout << (**px3).at(*i) << ", ";
    }*/
}

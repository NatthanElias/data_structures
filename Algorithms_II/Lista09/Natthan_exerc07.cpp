#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

//bool existe(int **ppx, int **i, int **inicial);
void geraVet(int **ppx, int **pp2x, int **s);
void mostraVet(int **ppx, int **pp2x, int **s);
void uniao(int **ppx, int **pp2x, vector<int> **x3, int **s);
void maiorMenor(vector<int> **x3);

int main()
{
    setlocale(LC_ALL, "portuguese");
    srand(time(NULL));

    int *tam = new int(10);
    //int *menu = new int;
    int *p = new int[*tam];
    int *p2 = new int[*tam];
    vector<int> *x3 = new vector<int>;

    geraVet(&p, &p2 ,&tam);
    mostraVet(&p, &p2, &tam);
    uniao(&p, &p2,&x3 ,&tam);
    maiorMenor(&x3);

    return 0;
}

/*bool existe(int ***ppx, int **i, int ****inicial)
{
    int *j = new int(0);

    for(*j; *j < **i; (*j)++)
    {

        if((***ppx) == (*(*(*(*inicial))++)))
        {
            return true;
        }

    }
    return false;
}*/

void geraVet(int **ppx, int **pp2x, int **s)
{
    int *i = new int(0);
    //int ***ini = &ppx;

    for(*i; *i < **s; (*i)++)
    {
        **ppx = rand()%20;
        **pp2x = rand()%20;
        (*ppx)++;
        (*pp2x)++;
    }

    *ppx -= *i;
    *pp2x -= *i;
}

void mostraVet(int **ppx, int **pp2x, int **s)
{
    int *i = new int(0);

    cout << "x1: ";
    for(*i; *i < **s; (*i)++)
    {
        cout << **ppx << ", ";
        (*ppx)++;
    }

    *i = 0;

    cout << "\nx2: ";
    for(*i; *i < **s; (*i)++)
    {
        cout << **pp2x << ", ";
        (*pp2x)++;
    }

    *ppx -= *i;
    *pp2x -= *i;
}

void uniao(int **ppx, int **pp2x, vector<int> **x3, int **s)
{
    int *i = new int(0);

    for(*i; *i < **s; (*i)++)
    {
        (*x3)->push_back(**ppx);//(*(*ppx)++)
        (*ppx)++;
    }
    *i = 0;

    for(*i; *i < **s; (*i)++)
    {
        (*x3)->push_back(*(*pp2x)++);
        //(*pp2x)++;
    }

    sort( (**x3).begin(), (**x3).end() );
    auto x = unique( (*x3)->begin(), (*x3)->end() );// x eh ponteiro
    //x3->erase(x,(*x3).end());
    (*x3)->resize(distance( (*x3)->begin(),x ));
    //(*x3)->shrink_to_fit();

    cout << "\n\nx3: ";
    for(auto it =(**x3).begin(); it!= x; it++)
    {
        cout << *it << ", ";
    }
}

void maiorMenor(vector<int> **x3)
{

    int *j = new int(0);
    int *maior = new int(0);

    for(*j; *j < (**x3).size(); (*j)++)
    {
        if((**x3).at(*j) > *maior)
        {
            *maior = (**x3).at(*j);
        }
    }

    cout << "\nMenor: "<< (**x3)[0];
    cout << "\nMaior: "<< *maior << "\n";
}

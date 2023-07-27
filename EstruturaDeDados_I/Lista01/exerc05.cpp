#include <iostream>
#include <vector>

using namespace std;

void lerVet(vector<int> **v);

int main()
{
    setlocale(LC_ALL, "Portuguese");

    vector<int> *vet = new vector<int>;

    lerVet(&vet);

    for(auto it = vet->begin(); it != vet->end(); it++)
        cout << *it << ", ";

    delete vet;

    return 0;
}

void lerVet(vector<int> **v)
{
    int menu;

    do {

    int x;
    cout << "Informe o elemento que deseja inserir no vetor: ";
    cin >> x;
    (*v)->push_back(x);
    fflush(stdin);
    system("cls");

    cout << "Digite 1 caso deseje continuar povoando o vetor, ou outro caracter caso não.";\
    cin >> menu;
    fflush(stdin);
    system("cls");

    } while(menu == 1);

}


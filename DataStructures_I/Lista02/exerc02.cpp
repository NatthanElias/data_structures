#include <iostream>
using namespace std;

#include "pilha.hpp"


int main(void) {
    setlocale(LC_ALL, "Portuguese");

    int menu = 0, tam = 0, val = 0;
    bool teste = false;
    Pilha p1;

    do
    {
    cout << "1 - Criar pilha\n";
    cout << "2 - Inserir\n";
    cout << "3 - Remover\n";
    cout << "4 - Consultar\n";
    cout << "5 - Mostrar\n";
    cout << "0 - Sair\n";
    cin >> menu;
    fflush(stdin);
    system("cls");

    if(!verificaInicializacaoP(&p1) && (menu == 2 || menu == 3 || menu == 4 || menu == 5)) {
        cout << "ERRO: Crie a pilha primeiro";
        getchar();
        system("cls");
        continue;
    }

    switch(menu)
    {
        case 1:
            cout << "Informe o tamanho da pilha:";
            cin >> tam;
            fflush(stdin);
            if(verificaInicializacaoP(&p1))
                destroiP(&p1);
            inicializaP(&p1, tam);
            cout << "Pilha inicializada";
            getchar();
            system("cls");
            break;
        case 2:
            cout << "Informe o valor a ser inserido: ";
            cin >> val;
            if(!buscaP(&p1,val))
            {
                if(!empilhaP(&p1,val)) {
                    cout << "ERRO: A pilha está cheia";
                    getchar();
                }
            }
            else
                cout << "Valor duplicado";
            system("cls");
            break;
        case 3:
            if(vaziaP(&p1))
                cout << "ERRO: A pilha está cheia";
            else
                cout << "O elemento " << desempilhaP(&p1) << " foi removido";
            getchar();
            system("cls");
            break;
        case 4: {
            cout << "Informe o valor a ser consultado: ";
            cin >> val;
            if(!buscaP(&p1, val)) {
                cout << "Valor informado não consta na pilha";
                getchar();
            }
            else
            {
                cout << buscaP(&p1, val) << " está na pilha";
                getchar();
            }
            system("cls");
            break;}
        case 5:
            mostraP(&p1);
            getchar();
            system("cls");
            break;
    }

    }while (menu!=0);

    return 0;
}

#include <iostream>
using namespace std;

#include "filacircular.hpp"
#include "pilha.hpp"

bool testaPrimo(int val);

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    Pilha p;
    Fila primo, par, impar;
    int menu, tam, v, val;

    cout << "Informe a quantidade de numeros que deseja cadastrar: ";
    cin >> tam;
    fflush(stdin);

    inicializaP(&p, tam);
    inicializaF(&primo, tam);
    inicializaF(&par, tam);
    inicializaF(&impar, tam);

    do {
        system("cls");
        cout << "#####MENU#####\n";
        cout << "1- Incluir na pilha\n";
        cout << "2- Remover da pilha\n";
        cout << "3- Mostrar pilha\n";
        cout << "4- Mostrar as filas\n";
        cout << "0- Sair\n";
        cin >> menu;
        fflush(stdin);

        switch(menu) {
            case 1:
                system("cls");
                cout << "Informe o valor que deseja inserir: ";
                cin >> v;
                fflush(stdin);

                empilhaP(&p, v);

                system("cls");
                cout << "Valor inserido com sucesso!";
                getchar();
                break;
            case 2:
                system("cls");
                val = desempilhaP(&p);

                if(testaPrimo(val))
                    enfileiraF(&primo, val);

                if(val%2==0)
                    enfileiraF(&par, val);
                else
                    enfileiraF(&impar, val);

                cout << "Numero removido";
                getchar();
                break;
            case 4:
                system("cls");
                cout << "Primos :";
                mostraF(&primo);

                cout << "\nPares :";
                mostraF(&par);

                cout << "\nImpares :";
                mostraF(&impar);
                getchar();
                break;
            case 3:
                system("cls");
                mostraP(&p);
                getchar();
                break;
        }

    } while(menu != 0);

    destroiP(&p);
    destroiF(&primo);
    destroiF(&par);
    destroiF(&impar);

    return EXIT_SUCCESS;
}

bool testaPrimo(int val) {
    int cont = 0;

    for(int i = 1; i <= val; i++) {
        if(val%i==0)
            cont++;
    }

    if(cont == 2)
        return true;

    return false;
}

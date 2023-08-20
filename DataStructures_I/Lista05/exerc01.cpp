#include <iostream>
using namespace std;

#include "fila-dinamica.hpp"
#include "pilha-dinamica.hpp"


int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    Fila f;
    Pilha p;
    int menu, val;

    do {
        system("cls");
        cout << "#######MENU#######\n";
        cout << "0 - Sair\n";
        cout << "1 - Incluir na fila\n";
        cout << "2 - Remover da fila\n";
        cout << "3 - Mostrar fila\n";
        cout << "4 - Inverter fila\n";
        cin >> menu;
        fflush(stdin);

        switch(menu) {
            case 1:
                system("cls");
                cout << "Informe o valor que deseja inserir na fila: ";
                cin >> val;
                fflush(stdin);

                if(enfileiraF(&f,val))
                    cout << "\nValor inserido com sucesso!";

                getchar();
                break;
            case 2:
                system("cls");
                if(!vaziaF(&f)) {
                    desenfileiraF(&f);
                    cout << "Valor desempilhado";
                }
                else
                    cout << "A pilha está vazia";
                getchar();
                break;
            case 3:
                system("cls");
                mostraF(&f);
                getchar();
                break;
            case 4:
                system("cls");
                if(!vaziaF(&f)) {
                    while(f.fim != nullptr) {
                        val = desenfileiraF(&f);
                        empilhaP(&p, val);
                    }

                    while(p.topo != nullptr) {
                        val = desempilhaP(&p);
                        enfileiraF(&f, val);
                    }

                    cout << "Fila Invertida!";
                }
                else {
                    cout << "A pilha está vazia";
                }
                getchar();
                break;
            default:
                cout << "A opção não existe!";
                break;
        }

    } while(menu!=0);


    destroiF(&f);
    destroiP(&p);

    return EXIT_SUCCESS;
}

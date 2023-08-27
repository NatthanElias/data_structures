#include <iostream>

using namespace std;

#include "tree.hpp"

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    int menu = -1, n = 0;

    leaf_node* root = NULL;

    do {
        system("cls");
        cout << "############MENU############" << endl;
        cout << "0 - Sair           " << endl;
        cout << "1 – Incluir       " << endl;
        cout << "2 – Mostrar pré-ordem" << endl;
        cout << "3 – Mostrar ordem simétrica" << endl;
        cout << "4 – Mostrar pós-ordem" << endl;
        cout << "Digite o número da opção desejada: ";
        cin >> menu;
        fflush(stdin);

        switch(menu) {
        case 0:
            system("cls");
            cout << "Finalizando o programa...\nAté a próxima!";
            getchar();
            break;
        case 1:
            system("cls");
            cout << "Informe o valor a inserir: ";
            cin >> n;
            insertTree(&root, n);
            cout << "Valor inserido!";
            getchar();
            break;
        case 2:
            system("cls");
            printTreePre(root);
            getchar();
            break;
        case 3:
            system("cls");
            printTreeSym(root);
            getchar();
            break;
        case 4:
            system("cls");
            printTreePost(root);
            getchar();
            break;
        default:
            system("cls");
            cout << "Opção invalida";
            getchar();
            break;
        }

    } while(menu != 0);

    return 0;
}

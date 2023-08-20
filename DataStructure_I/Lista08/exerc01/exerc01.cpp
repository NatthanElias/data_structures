#include <iostream>
using namespace std;

#include "lista_string.hpp"


int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    No *lista;
    string str;

    inicializaL(&lista);

    int menu;

    do {
        system("cls");
        cout << "#######MENU#######\n";
        cout << "0 - Sair\n";
        cout << "1 - Verifica vazia\n";
        cout << "2 - Inserir valor Inicio\n";
        cout << "3 - Ler valor inicio\n";
        cout << "4 - Remover inicio\n";
        cout << "5 - Remover valor especifico\n";
        cout << "6 - Buscar valor especifico\n";
        cout << "7 - Mostra lista\n";
        cin >> menu;
        fflush(stdin);

        switch(menu) {
        case 1:
            system("cls");
            if(vaziaL(&lista)) {
                cout << "A lista esta vazia";
                getchar();
            } else {
                cout << "A lista nao esta vazia";
                getchar();
            }
            break;
        case 2:
            system("cls");
            cout << "Informe a string que deseja inserir: ";
            getline(cin, str);
            fflush(stdin);
            insereInicioL(&lista, str);
            system("cls");
            cout << "Valor inserido";
            getchar();
            break;
        case 3:
            system("cls");
            cout << "O valor do inicio é: " << leInicioL(&lista);
            getchar();
            break;
        case 4:
            system("cls");
            removeInicioL(&lista);
            cout << "Valor removido";
            getchar();
            break;
        case 5:
            system("cls");
            cout << "Informe o valor que deseja remover: ";
            getline(cin, str);
            fflush(stdin);
            system("cls");
            removeL(&lista, str);
            cout << "Valor removido";
            getchar();
            break;
        case 6: {
            system("cls");
            cout << "Informe o valor que deseja buscar: ";
            getline(cin, str);
            fflush(stdin);
            system("cls");
            No *busca = buscaL(&lista, str);
            if( busca == NULL)
                cout << "Valor nao encontrado";
            else
                cout << "Valor " << busca << " encotrado";
            getchar();
            break;}
        case 7:
            system("cls");
            mostraL(&lista);
            getchar();
            break;
        default:
            cout << "Opcao invalida!";
            getchar();
        }

    } while(menu != 0);

    destroiL(&lista);

    return 0;
}

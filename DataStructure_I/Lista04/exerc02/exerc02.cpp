#include <iostream>
using namespace std;

struct Aviao {
    int cod;
    int quant;
    string empresa;

    Aviao() {
        cod = 0;
        quant = 0;
        empresa = " ";
    }
};

#include "filacircular_aviao.hpp"


int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    Fila f;
    int menu, tam;

    cout << "Informe o tamanho da pista de decolagem: ";
    cin >> tam;
    fflush(stdin);

    inicializaF(&f, tam);

    do {
        system("cls");
        cout << "#####MENU#####\n";
        cout << "1- Entrada de um novo avi�o para decolar\n";
        cout << "2- Decolagem de um avi�o\n";
        cout << "3- Listar todos os avi�es � espera para decolagem\n";
        cout << "4- Listar as caracter�sticas do pr�ximo avi�o a decolar\n";
        cout << "0- Sair\n";
        cin >> menu;
        fflush(stdin);

        switch(menu) {
            case 1: {
                system("cls");

                Aviao a;

                cout << "Informe o c�digo do avi�o: ";
                cin >> a.cod;
                getchar();
                fflush(stdin);

                cout << "Informe a quantidade de passageiros: ";
                cin >> a.quant;
                getchar();
                fflush(stdin);

                cout << "Informe o nome da empresa: ";
                getline(cin, a.empresa);
                fflush(stdin);

                if(enfileiraF(&f, a)) {
                    system("cls");
                    cout << "Avi�o decolou com sucesso!";
                    getchar();
                } else{
                    system("cls");
                    cout << "ERRO: o Avi�o nao decolou!";
                    getchar();
                }

                break;}
            case 2:
                system("cls");
                desenfileiraF(&f);
                cout << "Aviao desenfileirado!";
                getchar();
                break;
            case 3:
                system("cls");
                mostraF(&f);
                getchar();
                break;
            case 4:
                system("cls");
                Aviao v = espiaF(&f);
                cout << "C�digo: " << v.cod << " || "; //imprime o dado armazenado na fila
                cout << "Passageiros: " << v.quant << " || ";
                cout << "Empresa: " << v.empresa << "\n";
                getchar();
                break;
        }

    }while(menu!=0);

    destroiF(&f);

    return EXIT_SUCCESS;
}

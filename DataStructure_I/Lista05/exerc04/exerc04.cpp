#include <iostream>
using namespace std;

struct Doc {
    string nome;
    int tam;
    int pag;
    int ano;
    char prio;

    Doc() {
        nome = "";
        tam = 0;
        pag = 0;
        ano = 0;
        prio = ' ';
    }
};

#include "fila-dinamica_04.hpp"

int docU = 0, pagU = 0,docP = 0, pagP = 0, docN = 0, pagN = 0;
void infoUnificada();

void mostraNome(Fila u, Fila p, Fila n);
void imprime(Fila *u, Fila *p, Fila *n);

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    Fila u, p, n;
    int menu;

    do {
        system("cls");
        cout << "#######MENU#######\n";
        cout << "0 - Sair\n";
        cout << "1 - Enviar documento para a impressão\n";
        cout << "2 - Mostrar o nome dos documentos armazenados nas filas \n";
        cout << "3 - Imprimir documento\n";
        cout << "4 - Listar as informações sobre as filas de forma unificada\n";
        cout << "5 - Mostrar as informações dos documentos armazenados nas filas\n";
        cin >> menu;
        fflush(stdin);

        switch(menu) {
            case 1:{
                system("cls");

                Doc x;

                cout << "Informe o nome do arquivo: ";
                getline(cin, x.nome);
                fflush(stdin);

                cout << "\n\nInforme o tamanho do arquivo (em MB): ";
                cin >> x.tam;
                fflush(stdin);

                cout << "\n\nInforme quantidade de páginas: ";
                cin >> x.pag;
                fflush(stdin);

                cout << "\n\nInforme o ano em que o arquivo foi criado: ";
                cin >> x.ano;
                fflush(stdin);

                cout << "\n\nInforme a prioridade de impressão (U-urgente, P-prioritário, N-normal)";
                cin >> x.prio;
                fflush(stdin);

                if(x.prio == 'U')
                {
                    enfileiraF(&u, x);
                    docU++;
                    pagU += x.pag;
                }
                else if(x.prio == 'P')
                {
                    enfileiraF(&p, x);
                    docP++;
                    pagP += x.pag;
                }
                else if(x.prio == 'N')
                {
                    enfileiraF(&n, x);
                    docN++;
                    pagN += x.pag;
                }

                break;}
            case 2:
                system("cls");
                mostraNome(u,p,n);
                getchar();
                break;
            case 3:
                system("cls");
                imprime(&u,&p,&n);
                getchar();
                break;
            case 4:
                system("cls");
                infoUnificada();
                getchar();
                break;
            default:
                cout << "A opção não existe!";
                break;
        }

    } while(menu!=0);

    destroiF(&u);
    destroiF(&p);
    destroiF(&n);

    return EXIT_SUCCESS;
}

void mostraNome(Fila u, Fila p, Fila n) {
    cout << "Fila U: ";
    if(vaziaF(&u) == false) //verifica se a fila não está vazia
    {

        cout << "[";

        NoFila *no = u.inicio;
        while (no != NULL) //faça enquanto (no != NULL)
        {
            cout << no->dado.nome;
            no = no->prox;

            if(no != NULL) //verifica se o próximo nó não é nulo (no != NULL)
                cout << ", ";
        }
        cout << "]" << endl;
    }
    else
        cout << "vazia!\n";

    cout << "Fila P: ";
    if(vaziaF(&p) == false) //verifica se a fila não está vazia
    {

        cout << "[";

        NoFila *no = p.inicio;
        while (no != NULL) //faça enquanto (no != NULL)
        {
            cout << no->dado.nome;
            no = no->prox;

            if(no != NULL) //verifica se o próximo nó não é nulo (no != NULL)
                cout << ", ";
        }
        cout << "]" << endl;
    }
    else
        cout << "vazia!\n";

    cout << "Fila N: ";
    if(vaziaF(&n) == false) //verifica se a fila não está vazia
    {

        cout << "[";

        NoFila *no = n.inicio;
        while (no != NULL) //faça enquanto (no != NULL)
        {
            cout << no->dado.nome;
            no = no->prox;

            if(no != NULL) //verifica se o próximo nó não é nulo (no != NULL)
                cout << ", ";
        }
        cout << "]" << endl;
    }
    else
        cout << "vazia!\n";
}

void imprime(Fila *u, Fila *p, Fila *n) {
    NoFila *no;

    if(!vaziaF(u)) {
        no = u->inicio;
        cout <<  "Documento "<< no->dado.nome << " foi imprimido";
        desenfileiraF(u);
        return;
    } else if(!vaziaF(p)) {
        no = p->inicio;
        cout <<  "Documento "<< no->dado.nome << " foi imprimido";
        desenfileiraF(p);
        return;
    } else if(!vaziaF(n)) {
        no = n->inicio;
        cout <<  "Documento "<< no->dado.nome << " foi imprimido";
        desenfileiraF(n);
        return;
    }else
        cout << "Todas as pilhas vazias!";
}

void infoUnificada() {
    cout << "Fila U:\nTotal documentos: " << docU << "\nTotal paginas :" << pagU;
    cout << "\n\nFila P:\nTotal documentos: " << docP << "\nTotal paginas :" << pagP;
    cout << "\n\nFila N:\nTotal documentos: " << docN << "\nTotal paginas :" << pagN;
}

#include <iostream>
#include <iomanip>

using namespace std;

struct Ficha {
    int codigo;
    string nome;
    int idade;
    float saldo;

    Ficha() {
        codigo = 0;
        nome = "";
        idade = 0;
        saldo = 0.0;
    }
};

#include "fila-dinamica.hpp"
#include "pilha-dinamica.hpp"

void criaFicha(Pilha *x);
void adicionaFila(Pilha x, Fila *p, Fila *np, Fila *d);
void mostra(Pilha x, Fila p, Fila np, Fila d);
void deposito(Pilha *px, int cod, float val);
void saque(Pilha *px, int cod, float val);
void atendeCliente(Pilha x, Fila p, Fila np, Fila d);

int main(void) {

    setlocale(LC_ALL, "Portuguese");
    cout << fixed;
    cout.precision(2);

    Pilha cadastro;
    Fila prioritaria, nPrioritaria, devedor;

    int menu;

    do {
        system("cls");
        cout << "#######MENU#######\n";
        cout << "0 - Sair\n";
        cout << "1 - Cadastra cliente\n";
        cout << "2 - Adicionar cliente na fila\n";
        cout << "3 - Mostrar\n";
        cout << "4 - Atender cliente da fila\n";
        cin >> menu;
        fflush(stdin);

        switch(menu) {
        case 0:
            break;
        case 1:
            system("cls");
            criaFicha(&cadastro);
            break;
        case 2:
            system("cls");
            adicionaFila(cadastro, &prioritaria, &nPrioritaria, &devedor);
            getchar();
            break;
        case 3:
            system("cls");
            mostra(cadastro, prioritaria, nPrioritaria, devedor);
            getchar();
            break;
        case 4:
            system("cls");
            atendeCliente(cadastro, prioritaria, nPrioritaria, devedor);
            getchar();
            break;
        default:
            cout << "Opcao invalida!";
            getchar();
        }

    } while(menu != 0);


    destroiP(&cadastro);

    return 0;
}

void criaFicha(Pilha *x) {
    Ficha pessoa;
    Pilha aux;

    cout << "Informe o codigo do cliente: ";
    cin >> pessoa.codigo;
    fflush(stdin);

    if(buscaP(x, pessoa.codigo)) {
        cout << "Codigo repetido!";
        getchar();
        return;
    }
    else {
        cout << "Informe o nome do cliente: ";
        getline(cin, pessoa.nome);
        fflush(stdin);

        cout << "Informe a idade do cliente: ";
        cin >> pessoa.idade;
        fflush(stdin);

        cout << "Informe o saldo do cliente: ";
        cin >> pessoa.saldo;
        fflush(stdin);
    }


    empilhaP(x, pessoa);

    //NoPilha *no = x->topo;
    //NoPilha *noAux = aux.topo;

    string nomeTopo = x->topo->dado.nome;

    while(!vaziaP(x) && pessoa.nome > nomeTopo) {
            empilhaP(&aux, x->topo->dado);
            desempilhaP(x);

            nomeTopo = x->topo->dado.nome;
    }

    //empilhaP(x, pessoa);

    while(!vaziaP(&aux)) {
        empilhaP(x, aux.topo->dado);
        desempilhaP(&aux);
    }

    cout << "Cliente cadastrado com sucesso!";
    getchar();

}

void adicionaFila(Pilha x, Fila *p, Fila *np, Fila *d) {
    int cod;

    cout << "Informe seu código: ";
    cin >> cod;
    fflush(stdin);

    if(buscaP(&x, cod)) {
        NoPilha *no = x.topo;

        while(no != NULL) {

            if(cod == no->dado.codigo){

                if(no->dado.idade > 60)
                {
                    if(buscaF(p, cod)){
                        system("cls");
                        cout << "Cliente já está na fila!";
                        getchar();
                        return;
                    }
                    else
                        enfileiraF(p, cod);

                }
                else if(no->dado.idade < 60 && no->dado.saldo > 0.0)
                {
                    if(buscaF(np, cod)){
                        system("cls");
                        cout << "Cliente já está na fila!";
                        getchar();
                        return;
                    }
                    else
                        enfileiraF(np, cod);
                }
                else if(no->dado.idade < 60 && no->dado.saldo < 0.0) {
                    if(buscaF(d, cod)){
                        system("cls");
                        cout << "Cliente já está na fila!";
                        getchar();
                        return;
                    }
                    else
                        enfileiraF(d, cod);
                }
            }

            no = no->prox;
        }
        cout << "Cliente cadastrado na fila!";
        getchar();

    } else {
        cout << "Cliente não cadastrado!";
        getchar();
    }
}

void mostra(Pilha x, Fila p, Fila np, Fila d) {
    char c;

    cout << "Deseja mostrar Pilha ou Filas (P - Pilha ou F - Filas)?";
    cin >> c;
    fflush(stdin);

    if(c == 'P') {
        if(!vaziaP(&x))
            mostraP(&x);
        else
            cout << "Pilha vazia!";
    }
    else if(c == 'F'){
        if(vaziaF(&p) && vaziaF(&np) && vaziaF(&d))
             cout << "Filas vazias!";
        else {
            cout << "Fila Prioritária: ";
            mostraF(&p);
            cout << "\nFila Não Prioritária: ";
            mostraF(&np);
            cout << "\nFila Devedores: ";
            mostraF(&d);
        }
    }
    else {
        cout << "\nERRO: Informe apenas P ou F";
    }
}

void deposito(Pilha *px, int cod, float val) {
    NoPilha *n = px->topo;

    while(n != NULL) {

        if(n->dado.codigo == cod)
            n->dado.saldo += val;

        n = n->prox;
    }
}

void saque(Pilha *px, int cod, float val) {
    NoPilha *n = px->topo;

    while(n != NULL) {

        if(n->dado.codigo == cod)
            n->dado.saldo -= val;

        n = n->prox;
    }
}

void atendeCliente(Pilha x, Fila p, Fila np, Fila d) {
    int aux = 0, valor = 0;
    float soma;
    char c;
    NoPilha *n = x.topo;

    while(n != NULL) {
        soma += n->dado.saldo;

        n = n->prox;
    }

    float limite = (soma * 80)/100.0;

    if(!vaziaF(&p)) {
        aux = desenfileiraF(&p);
        cout << "Qual operação deseja realizar? (S- Saque ou D- Deposito)";
        cin >> c;
        fflush(stdin);

        if(c == 'S') {
            cout << "Informe  a quantia que deseja sacar: ";
            cin >> valor;
            fflush(stdin);

            if(valor <= limite)
            {
                saque(&x, aux, valor);
                cout << "Saque realizado";
                getchar();
            }
            else
                cout << "ERRO:O limite atual para saque é " << limite;

        }
        else if(c == 'D') {
            cout << "Informe  a quantia que deseja depositar: ";
            cin >> valor;
            fflush(stdin);

            deposito(&x, aux, valor);
        }
        return;
    }
    else if(!vaziaF(&np)) {
        aux = desenfileiraF(&np);
        cout << "Qual operação deseja realizar? (S- Saque ou D- Deposito)";
        cin >> c;
        fflush(stdin);

        if(c == 'S') {
            cout << "Informe  a quantia que deseja sacar: ";
            cin >> valor;
            fflush(stdin);

            if(valor <= limite)
            {
                saque(&x, aux, valor);
                cout << "Saque realizado";
                getchar();
            }
            else
                cout << "ERRO:O limite atual para saque é " << limite;

        }
        else if(c == 'D') {
            cout << "Informe  a quantia que deseja depositar: ";
            cin >> valor;
            fflush(stdin);

            deposito(&x, aux, valor);
        }
        return;
    }
    else if(!vaziaF(&d)){
        aux = desenfileiraF(&d);
        cout << "Qual operação deseja realizar? (S- Saque ou D- Deposito)";
        cin >> c;
        fflush(stdin);

        if(c == 'S') {
            cout << "Informe  a quantia que deseja sacar: ";
            cin >> valor;
            fflush(stdin);

            if(valor <= limite)
            {
                saque(&x, aux, valor);
                cout << "Saque realizado";
                getchar();
            }
            else
                cout << "ERRO:O limite atual para saque é " << limite;

        }
        else if(c == 'D') {
            cout << "Informe  a quantia que deseja depositar: ";
            cin >> valor;
            fflush(stdin);

            deposito(&x, aux, valor);
        }
        return;
    }
    else
    {
        cout << "Todas as filas estão vazias!";
        return;
    }
}

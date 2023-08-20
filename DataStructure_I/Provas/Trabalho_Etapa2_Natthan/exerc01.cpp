#include <iostream>
#include <fstream>
#include <unistd.h>
#include <iomanip>
using namespace std;
#include "lista.hpp"

void mostra(Lista *lista, char c);
void mostraDif(Lista *L1, Lista *L2);
float mediana(Lista *listaPrinc);
int conta(int n, Lista *lista);
Lista * moda(Lista *lista);

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    cout << fixed;
    cout.precision(2);

    ifstream f;
    f.open("entrada.txt", ios::in);

    string op;

    Lista *L1 = new Lista();
    Lista *L2 = new Lista();

    string aux;
    string aux2;
    int n;
    char c;

    while(!f.eof()) {

        op = "";
        f >> op;

        if(op == "adiciona") {

            f >> aux;
            f >> n;

            if(aux == "L1"){
                insereFinalL(L1, n);
                cout << "O número " << n << " foi adicionado na lista L1\n";
            }
            else if(aux == "L2"){
                insereFinalL(L2, n);
                cout << "O número " << n << " foi adicionado na lista L2\n";
            }

        }
        else if(op == "mostra") {

            f >> aux;
            f >> c;

            if(aux == "L1") {
                cout << "L1 (" << c << "): ";
                mostra(L1, c);
            }
            else if(aux == "L2") {
                cout << "L2 (" << c << "): ";
                mostra(L2, c);
            }
        }
        else if(op == "mostraDif") {

            f >> aux;
            f >> aux2;


            /*if(vaziaL(L1)||vaziaL(L2)) {
                cout << "VAZIA";
            }else */
            if(aux == "L1") {
                cout << "L1 - L2: ";
                if(vaziaL(L1))
                    cout << "VAZIA\n";
                else
                    mostraDif(L2, L1);
            }
            else if(aux == "L2") {
                cout << "L2 - L1: ";
                if(vaziaL(L2))
                    cout << "VAZIA\n";
                else
                    mostraDif(L1, L2);
            }
        }
        else if(op == "removeTodos") {
            f >> aux;

            if(aux == "L1") {
                while(!vaziaL(L1)) {
                    removeInicioL(L1);
                }

                cout << "Todos os valor de L1 foram removidos\n";
            }
            else if(aux == "L2") {
                while(!vaziaL(L2)) {
                    removeInicioL(L2);
                }

                cout << "Todos os valor de L2 foram removidos\n";
            }
        }
        else if(op == "mediana") {
            f >> aux;

            float medianaAux = 0.00;
            if(aux == "L1") {
                if(!vaziaL(L1)) {
                    medianaAux = mediana(L1);

                     cout << "Mediana L1: " << medianaAux << "\n";
                }
                else
                    cout << "Erro ao calcular a mediana de L1:  lista vazia!\n";
            }
            else if(aux == "L2") {
                if(!vaziaL(L2)){
                    medianaAux = mediana(L2);

                    cout << "Mediana L2: " << medianaAux << "\n";
                }
                else
                    cout << "Erro ao calcular a mediana de L2:  lista vazia!\n";
            }
        }
        else if(op == "moda") {
            f >> aux;

            if(aux == "L1") {
                cout << "Moda (s) L1: ";
                mostraL(moda(L1));
            }
            else if(aux == "L2") {
                cout << "Moda (s) L2: ";
                mostraL(moda(L2));
            }
        }

        usleep(10000);
    }

    f.close();

    delete(L1);
    delete(L2);

    return 0;
}

void mostra(Lista *lista, char c) {
    Lista *aux = new Lista();
    No *no = lista->inicio;

    if(c == 'I')
        mostraL(lista);
    else if(c == 'C') {
        while(no != NULL) {
            insereOrdenado(aux, no->dado);

            no = no->prox;
        }
        mostraL(aux);
    }
    else if(c == 'D') {
        while(no != NULL) {
            insereOrdenadoDecrescente(aux, no->dado);

            no = no->prox;
        }
        mostraL(aux);
    }

}

void mostraDif(Lista *L1, Lista *L2) {
    No* no = L1->inicio;
    No* no2 = L2->inicio;

    Lista* aux = new Lista();

    while(no != NULL) {

        while(no2 != NULL) {
            if(!buscaL(L1, no2->dado))
                insereOrdenado(aux, no2->dado);

            no2 = no2->prox;
        }

        no = no->prox;
    }

    if(vaziaL(L1))
        mostra(L2,'C');
    else if(vaziaL(L2))
        mostra(L1,'C');
    else if(vaziaL(L1)||vaziaL(L2))
        cout << "AMBAS VAZIAS";
    else
        mostraL(aux);
}

float mediana(Lista *listaPrinc) {
    int meioPos = 0;
    int aux = 0;
    int tam = listaPrinc->tamanho;
    float mediana = -1.00;

    Lista *lista = new Lista();
    No *no = listaPrinc->inicio;

    while(no != NULL) {
        insereOrdenadoDecrescente(lista, no->dado);

        no = no->prox;
    }

    if(tam%2!=0) {
        meioPos = (tam/2);

        mediana = lePosicao(lista, meioPos);
    }
    else {
        meioPos = ((tam+1)/2);
        aux = meioPos - 1;

        mediana = (lePosicao(lista, meioPos) + lePosicao(lista, aux))/2.00;
    }

    return (float)mediana;
}

int conta(int n, Lista *lista) {
    No* no = lista->inicio;

    int cont = 0;

    while(no != NULL) {

        if(no->dado==n)
            cont++;

        no = no->prox;
    }

    return cont;
}

int maior(Lista *lista) {
    No* no = lista->inicio;
    int maior = 0;

    while(no!=NULL) {

        if(maior < no->dado)
            maior = no->dado;

        no = no->prox;
    }

    return maior;
}

Lista* moda(Lista *lista) {
    Lista *aux = new Lista();
    Lista *moda = new Lista();

    No* no = lista->inicio;

    while(no != NULL) {

        insereFinalL(aux, conta(no->dado, lista));

        no = no->prox;
    }

    if(maior(aux) == 1)
        return moda;

    no = lista->inicio;
    No* no2 = aux->inicio;

    while(no != NULL) {
        if(no2->dado==maior(aux)) {
            if(!buscaL(moda,no->dado))
                insereFinalL(moda,no->dado);
        }
        no = no->prox;
        no2 = no2->prox;
    }

    return moda;
}

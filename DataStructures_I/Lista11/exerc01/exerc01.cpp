#include <iostream>
#include <fstream>
using namespace std;
#include "lista_funcionario.hpp"
#include "lista_departamento.hpp"

void cadastrarFunc(int idf, string nome, char sexo, ListaFunc* lista);
void mostraDep(int id, Lista *lista, ListaFunc *listaF);

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    ifstream f;
    f.open("exerc01.txt", ios::in);

    ListaFunc *listaF = new ListaFunc();
    Lista *listaP = new Lista();
    Lista *listaE = new Lista();
    Lista *listaA = new Lista();

    string op;

    while(!f.eof()) {
        f >> op;

        if(op == "cadastrarFunc") {

            int idFunc;
            string nomeFunc;
            char sexoFunc;

            f >> idFunc;
            f >> nomeFunc;
            f >> sexoFunc;

            cadastrarFunc(idFunc, nomeFunc, sexoFunc, listaF);
        }
        else if(op == "mostraFunc") {
            cout << "Funcionarios: ";
            mostraFuncL(listaF);
        }
        else if(op == "addFuncDep") {
            int IDF,IDD;

            f >> IDF;
            f >> IDD;

            NoFunc *funcio = buscaFuncID(listaF, IDF);

            if(funcio == nullptr)
            {
                cout << "Usuário " << IDF << " inexistente.\n";
            }
            else if(IDD < 0 || IDD > 2) {
                cout << "Despertamento " << IDD << " inexistente.\n";
            }
            else {
                if(IDD == 0)
                {
                    if(buscaL(listaP, IDF) != nullptr) {
                        cout << "O funcionário " << funcio->dado.nome << " já está no departamento de produção.\n";
                    }
                    else {
                        insereInicioL(listaP, IDF);
                        cout << "O funcionário " << funcio->dado.nome << " foi adicionado no departamento de produção.\n";
                    }
                }
                else if(IDD == 1) {
                    if(buscaL(listaE, IDF) != nullptr) {
                        cout << "O funcionário " << funcio->dado.nome << " já está no departamento de entregas.\n";
                    }
                    else {
                        insereInicioL(listaE, IDF);
                        cout << "O funcionário " << funcio->dado.nome << " foi adicionado no departamento de entregas.\n";
                    }
                }
                else if(IDD == 2) {
                    if(buscaL(listaA, IDF) != nullptr) {
                        cout << "O funcionário " << funcio->dado.nome << " já está no departamento de Atendimento ao Cliente.\n";
                    }
                    else {
                        insereInicioL(listaA, IDF);
                        cout << "O funcionário " << funcio->dado.nome << " foi adicionado no departamento de Atendimento ao Cliente.\n";
                    }
                }

            }


        }
        else if(op == "mostraDep") {
            int ID;
            f >> ID;

            No* n = new No();

            if(ID == 0) {
                cout << "Departamento Produção: ";

                mostraDep(ID, listaP, listaF);
            }
            else if(ID == 1) {
                cout << "Departamento Entregas: ";

                mostraDep(ID, listaE, listaF);
            }

            else if(ID == 2) {
                cout << "Departamento Atendimento ao cliente: ";

                mostraDep(ID, listaA, listaF);
            }

            else
                cout << "Departamento " << ID << " inexistente.";

            cout << "\n";
            delete(n);
            //fim MostraDep
        }
        else if(op == "removeFunc") {
            int cod;

            f >> cod;

            string aux = buscaFuncID(listaF, cod)->dado.nome;
            bool teste = false;

            if(buscaL(listaA, cod) != NULL) {

                removeL(listaA, cod);
                removeFuncL(listaF, cod);

                teste = true;
            }

            if(buscaL(listaE, cod) != NULL) {

                removeL(listaE, cod);
                removeFuncL(listaF, cod);

                teste = true;

            }

            if(buscaL(listaP, cod) != NULL) {

                removeL(listaP, cod);
                removeFuncL(listaF, cod);

                teste = true;

            }

            if(teste)
                cout << "O funcionario " << aux << " foi removido.\n";

        }


        op = "";
    }

    f.close();

    delete(listaF);
    delete(listaA);
    delete(listaP);
    delete(listaE);

    return 0;
}

void cadastrarFunc(int idf, string nome, char sexo, ListaFunc* lista) {
    Funcionario x;

    x.IDF = idf;
    x.nome = nome;
    x.sexo = sexo;

    if(buscaFuncID(lista, idf) != nullptr) {
        cout << "O funcionário " << x.nome << " não foi cadastrado, pois o código " << x.IDF << " já existe.\n";
        return;
    }

    insereOrdenado(lista, x);

    cout << "O funcionário " << x.nome << "("<< x.IDF << ") foi cadastrado com sucesso!\n";
}

void mostraDep(int id, Lista *lista, ListaFunc *listaF) {
    No *n = lista->inicio;

    while(n != NULL) {
        cout << buscaFuncID(listaF, n->dado)->dado.nome;

        n = n->prox;

        if(n != NULL)
            cout << ", ";
    }
}

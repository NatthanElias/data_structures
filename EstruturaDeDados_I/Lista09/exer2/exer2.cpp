/* ENUNCIADO: Crie as seguintes funções (utilizando as mesmas informações do exercício anterior):
    1) Inverter lista - utilizar lista auxiliar e as funções de inserir no fim, inserir no início, remover do fim, e
remover do início.
    2) Mostrar a lista ordenada pela idade dos funcionários: usar uma lista auxiliar para armazenar os funcionários
ordenados e, em seguida, mostrar a lista auxiliar.
    3) Unir duas listas.
    4) Intersecção de duas listas.
*/

/* DICAS: já estão na questão.
*/

#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

struct Funcionario
{
    int codigo;
    string nome;
    int idade;
    float salario;

    Funcionario()
    {
        codigo = 0;
        nome = " ";
        idade = 0;
        salario = 0.00;
    }
};

#include "lista_descritor-funcionario.hpp"

No* removeInicioL(Lista *lista);
bool insereFinalL(Lista *lista, DadoNoLista valor);
bool inverteL(Lista *lista);
bool ordenaIdade(Lista *lista);
void insereOrdenadoL(Lista *lista, Lista *listaAux, DadoNoLista valor);
void insereOrdenadoListaAuxiliar(Lista *lista, Lista *listaAux);
Lista* unirListas(Lista *lista1, Lista *lista2);
Lista* interseccaoL(Lista *lista1, Lista *lista2);

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    No *aux = nullptr;
    Lista *L1 = new Lista();//executa o construtor (inicializa a lista)....
    Lista *L2 = new Lista();
    Funcionario f1;

    f1.nome = "Artur";
    f1.codigo = 2;
    f1.idade = 19;
    f1.salario = 15000.00;
    insereInicioL(L1, f1);

    f1.nome = "Maria";
    f1.codigo = 1;
    f1.idade = 19;
    f1.salario = 7000.00;
    insereInicioL(L1, f1);

    f1.nome = "João";
    f1.codigo = 3;
    f1.idade = 25;
    f1.salario = 4000.00;
    insereFinalL(L1, f1);

    f1.nome = "Pedro";
    f1.codigo = 4;
    f1.idade = 47;
    f1.salario = 1250.00;
    insereFinalL(L1, f1);

    f1.nome = "Julia";
    f1.codigo = 5;
    f1.idade = 15;
    f1.salario = 1000.00;
    insereFinalL(L1, f1);

    f1.nome = "Lucas";
    f1.codigo = 6;
    f1.idade = 19;
    f1.salario = 15000.00;
    insereInicioL(L2, f1);

    f1.nome = "Maria";
    f1.codigo = 1;
    f1.idade = 19;
    f1.salario = 7000.00;
    insereInicioL(L2, f1);

    f1.nome = "Paulo";
    f1.codigo = 7;
    f1.idade = 25;
    f1.salario = 4000.00;
    insereFinalL(L2, f1);

    f1.nome = "Pedro";
    f1.codigo = 4;
    f1.idade = 47;
    f1.salario = 1250.00;
    insereFinalL(L2, f1);

    f1.nome = "Marcos";
    f1.codigo = 8;
    f1.idade = 15;
    f1.salario = 1000.00;
    insereFinalL(L2, f1);

    cout << "LISTA ORIGINAL:\n";
    mostraL(L1);
    cout << endl;

    inverteL(L1);
    cout << "LISTA INVERTIDA:\n";
    mostraL(L1);
    cout << endl;

    Lista *Laux = new Lista();
    insereOrdenadoListaAuxiliar(L1, Laux);
    cout << "LISTA ORDENADA POR IDADE:\n";
    mostraL(Laux);
    cout << endl;

    Lista *L3 = new Lista();
    L3 = unirListas(L1, Laux);
    cout << "LISTAS UNIDAS:\n";
    mostraL(L3);
    cout << endl;

    cout << "LISTA 1:\n";
    mostraL(L1);
    cout << endl;

    cout << "LISTA 2:\n";
    mostraL(L2);
    cout << endl;

    L3 = interseccaoL(L1, L2);
    cout << "INTERSECÇÃO DE L1 E L2:\n";
    mostraL(L3);
    cout << endl;

    delete(L1); //executa desconstrutor (apaga todos os nós)
    delete(L2);
    delete(L3);
    delete(Laux);
    return EXIT_SUCCESS;
}

No* removeInicioL(Lista *lista)
{
    No *n = lista->inicio;
    if (n->prox == NULL)
    {
        lista->inicio = nullptr;
        lista->fim = nullptr;
    }
    else
        lista->inicio = n->prox;
    lista->tamanho--;

    return n;
}

bool insereFinalL(Lista *lista, DadoNoLista valor)
{
    No *novo = new No();
    if (novo == nullptr)
        return false;

    novo->dado = valor;
    novo->prox = nullptr;  // O novo nó deve apontar para NULL

    if (lista->inicio == nullptr)  // Se a lista estiver vazia
    {
        lista->inicio = novo;
        lista->fim = novo;
    }
    else
    {
        lista->fim->prox = novo;
        lista->fim = novo;
    }

    lista->tamanho++;
    return true;
}

bool inverteL(Lista *lista)
{
    No *n = lista->inicio;
    Lista *Laux = new Lista();
    if (lista->inicio == NULL)
        return false;
    while(n)
    {
        No *nAux = removeInicioL(lista);
        insereInicioL(Laux, nAux->dado);
        n = n->prox;
    }
    n = Laux->inicio;
    while(n)
    {
        No *nAux = removeInicioL(Laux);
        insereFinalL(lista, nAux->dado);
        n = n->prox;
    }
    delete(Laux);
    return true;
}

void insereOrdenadoL(Lista *lista, Lista *listaAux, DadoNoLista valor)
{
    No *novo = new No();
    if (novo == nullptr)
        return;

    novo->dado = valor;
    novo->prox = nullptr;

    if (listaAux->inicio == nullptr) // Se a lista auxiliar estiver vazia
    {
        listaAux->inicio = novo;
        listaAux->fim = novo;
    }
    else
    {
        No *atual = listaAux->inicio;
        No *anterior = nullptr;

        // Percorre a lista auxiliar até encontrar a posição correta de inserção
        while (atual != nullptr && atual->dado.idade < valor.idade)
        {
            anterior = atual;
            atual = atual->prox;
        }

        if (anterior == nullptr) // Inserir no início da lista auxiliar
        {
            novo->prox = listaAux->inicio;
            listaAux->inicio = novo;
        }
        else // Inserir no meio ou no final da lista auxiliar
        {
            anterior->prox = novo;
            novo->prox = atual;
            if (atual == nullptr) // Inserir no final da lista auxiliar
                listaAux->fim = novo;
        }
    }

    listaAux->tamanho++;
}

void insereOrdenadoListaAuxiliar(Lista *lista, Lista *listaAux)
{
    No *atual = lista->inicio;

    while (atual != nullptr)
    {
        insereOrdenadoL(lista, listaAux, atual->dado);
        atual = atual->prox;
    }
}

Lista* unirListas(Lista *lista1, Lista *lista2)
{
    Lista *L3 = new Lista();
    No *n = lista1->inicio;
    while(n)
    {
        insereFinalL(L3, n->dado);
        n = n->prox;
    }
    n = lista2->inicio;
    while(n)
    {
        insereFinalL(L3, n->dado);
        n = n->prox;
    }
    return L3;
}

Lista* interseccaoL(Lista *lista1, Lista *lista2)
{
    Lista *lista3 = new Lista();
    No *n = lista1->inicio;
    while(n)
    {
        if (buscaL(lista2, n->dado) && !buscaL(lista3, n->dado))
        {
            insereFinalL(lista3, n->dado);
        }
        n = n->prox;
    }
    return lista3;
}

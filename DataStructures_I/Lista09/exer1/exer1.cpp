/* ENUNCIADO: Uma empresa possui uma lista com as informações de seus funcionários (nome, código, idade e salário). Com base
nessas informações, crie um programa para gerenciar essa lista de funcionários.
    1) Implemente uma lista simplesmente encadeada, projetada para armazenar os dados dos funcionários da empresa.
    2) Crie um descritor para a lista contendo:
        a) Ponteiro para o primeiro nó da lista
        b) Ponteiro para o último nó da lista
        c) Quantidade de nós
    3) Implemente as seguintes funções:
        a) Função para ler um funcionário do início da lista
        b) Função para remover um funcionário do início da lista
        c) Função para inserir funcionários no início da lista
        d) Função para inserir funcionários no final da lista (usar descritor)
        e) Função para ler um funcionário do final da lista (usar descritor)
        f) Função para imprimir os nós da lista (todos os dados)
        g) Função para imprimir a média dos salários pagos pela empresa
        h) Função para imprimir o nome de todos os funcionários que possuem salário menor que a média
        i) Função para ordenar a lista de funcionários em ordem alfabética
*/

/* DICAS: algumas funções estão no .hpp prontas, o restante será criado no próprio .cpp
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

No* espiaL(Lista *lista);
No* removeInicioL(Lista *lista);
bool insereFinalL(Lista *lista, DadoNoLista valor);
No* espiaUltimoL(Lista *lista);
float mediaSalarios(Lista *lista);
void abaixoMedia(Lista *lista, float media);
void ordemAlfabetica(Lista *lista);

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    No *aux = nullptr;
    Lista *lista = new Lista();//executa o construtor (inicializa a lista)....
    Funcionario f1;

    f1.nome = "Artur";
    f1.codigo = 2;
    f1.idade = 19;
    f1.salario = 15000.00;
    insereInicioL(lista, f1);

    f1.nome = "Artur";
    f1.codigo = 1;
    f1.idade = 19;
    f1.salario = 7000.00;
    insereInicioL(lista, f1);

    aux = espiaL(lista);
    cout << "PRIMEIRO VALOR DA LISTA:\n";
    cout << "Código: " << aux->dado.codigo << endl;
    cout << "Nome: " << aux->dado.nome << endl;
    cout << "Idade: " << aux->dado.idade << endl;
    cout << fixed;
    cout << setprecision(2) << "Salário: R$ " << aux->dado.salario << endl;

    cout << "\nLISTA APÓS ESPIAR: ";
    mostraL(lista);
    cout << endl;
    aux = removeInicioL(lista);
    cout << aux->dado.nome << " removido com sucesso!\n";

    cout << "LISTA APÓS REMOÇÃO DO PRIMEIRO NÓ: ";
    mostraL(lista);
    cout << endl;

    f1.nome = "Pedro";
    f1.codigo = 3;
    f1.idade = 25;
    f1.salario = 4000.00;
    insereFinalL(lista, f1);

    f1.nome = "Alisson";
    f1.codigo = 4;
    f1.idade = 47;
    f1.salario = 1250.00;
    insereFinalL(lista, f1);

    cout << "LISTA APÓS INSERE FINAL: ";
    mostraL(lista);
    cout << endl;

    cout << "ÚLTIMO VALOR DA LISTA:\n";
    aux = espiaUltimoL(lista);
    cout << "Código: " << aux->dado.codigo << endl;
    cout << "Nome: " << aux->dado.nome << endl;
    cout << "Idade: " << aux->dado.idade << endl;
    cout << fixed;
    cout << setprecision(2) << "Salário: R$ " << aux->dado.salario << endl;

    float media = mediaSalarios(lista);
    cout << "\nMÉDIA DOS SALÁRIOS: R$" << media << "\n";

    abaixoMedia(lista, media);

    ordemAlfabetica(lista);

    cout << "LISTA EM ORDEM ALFABÉTICA: ";
    mostraL(lista);
    cout << endl;

    delete(lista); //executa desconstrutor (apaga todos os nós)
    return EXIT_SUCCESS;
}

No* espiaL(Lista *lista)
{
    No *n = lista->inicio;

    if(n == NULL)
        return nullptr;
    return n;
}

No* removeInicioL(Lista *lista)
{
    No *n = lista->inicio;

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

No* espiaUltimoL(Lista *lista)
{
    No *n = lista->fim;

    if(n == NULL)
        return nullptr;
    return n;
}

float mediaSalarios(Lista *lista)
{
    float total = 0.00;
    No *n = lista->inicio;
    while (n != NULL)
    {
        total += n->dado.salario;
        n = n->prox;
    }
    return total / (float)lista->tamanho;
}

void abaixoMedia(Lista *lista, float media)
{
    No *n = lista->inicio;
    cout << "\nFUNCIONÁRIOS QUE RECEBEM ABAIXO DA MÉDIA:\n";
    while (n)
    {
        if (n->dado.salario < media)
        {
            cout << n->dado.nome << "\n";
        }
        n = n->prox;
    }
}

void ordemAlfabetica(Lista *lista)
{
    No* n = lista->inicio;
    Funcionario Faux;
    Funcionario();
    bool ordenado = true;
    do
    {
        ordenado = true;
        n = lista->inicio;
        while(n->prox)
        {
            if(n != NULL && n->prox != NULL && n->dado.nome > n->prox->dado.nome)
            {
                Faux = n->dado;
                n->dado = n->prox->dado;
                n->prox->dado = Faux;
                ordenado = false;
            }
            n = n->prox;
        }
    }
    while(ordenado == false);
}




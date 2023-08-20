/* ENUNCIADO: Uma empresa possui uma lista com as informa��es de seus funcion�rios (nome, c�digo, idade e sal�rio). Com base
nessas informa��es, crie um programa para gerenciar essa lista de funcion�rios.
    1) Implemente uma lista simplesmente encadeada, projetada para armazenar os dados dos funcion�rios da empresa.
    2) Crie um descritor para a lista contendo:
        a) Ponteiro para o primeiro n� da lista
        b) Ponteiro para o �ltimo n� da lista
        c) Quantidade de n�s
    3) Implemente as seguintes fun��es:
        a) Fun��o para ler um funcion�rio do in�cio da lista
        b) Fun��o para remover um funcion�rio do in�cio da lista
        c) Fun��o para inserir funcion�rios no in�cio da lista
        d) Fun��o para inserir funcion�rios no final da lista (usar descritor)
        e) Fun��o para ler um funcion�rio do final da lista (usar descritor)
        f) Fun��o para imprimir os n�s da lista (todos os dados)
        g) Fun��o para imprimir a m�dia dos sal�rios pagos pela empresa
        h) Fun��o para imprimir o nome de todos os funcion�rios que possuem sal�rio menor que a m�dia
        i) Fun��o para ordenar a lista de funcion�rios em ordem alfab�tica
*/

/* DICAS: algumas fun��es est�o no .hpp prontas, o restante ser� criado no pr�prio .cpp
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
    cout << "C�digo: " << aux->dado.codigo << endl;
    cout << "Nome: " << aux->dado.nome << endl;
    cout << "Idade: " << aux->dado.idade << endl;
    cout << fixed;
    cout << setprecision(2) << "Sal�rio: R$ " << aux->dado.salario << endl;

    cout << "\nLISTA AP�S ESPIAR: ";
    mostraL(lista);
    cout << endl;
    aux = removeInicioL(lista);
    cout << aux->dado.nome << " removido com sucesso!\n";

    cout << "LISTA AP�S REMO��O DO PRIMEIRO N�: ";
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

    cout << "LISTA AP�S INSERE FINAL: ";
    mostraL(lista);
    cout << endl;

    cout << "�LTIMO VALOR DA LISTA:\n";
    aux = espiaUltimoL(lista);
    cout << "C�digo: " << aux->dado.codigo << endl;
    cout << "Nome: " << aux->dado.nome << endl;
    cout << "Idade: " << aux->dado.idade << endl;
    cout << fixed;
    cout << setprecision(2) << "Sal�rio: R$ " << aux->dado.salario << endl;

    float media = mediaSalarios(lista);
    cout << "\nM�DIA DOS SAL�RIOS: R$" << media << "\n";

    abaixoMedia(lista, media);

    ordemAlfabetica(lista);

    cout << "LISTA EM ORDEM ALFAB�TICA: ";
    mostraL(lista);
    cout << endl;

    delete(lista); //executa desconstrutor (apaga todos os n�s)
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
    novo->prox = nullptr;  // O novo n� deve apontar para NULL

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
    cout << "\nFUNCION�RIOS QUE RECEBEM ABAIXO DA M�DIA:\n";
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




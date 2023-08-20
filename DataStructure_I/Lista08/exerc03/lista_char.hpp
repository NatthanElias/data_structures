#ifndef _HPP_LISTA_DINAMICA
#define _HPP_LISTA_DINAMICA

typedef char DadoNoLista;

struct No
{
    DadoNoLista dado;
    struct No *prox;
};


void inicializaL(No **lista)
{
    *lista = NULL;
}

bool vaziaL(No **lista)
{
    if( (*lista) == NULL )
        return true;
    else
        return false;
}

/// excluir todos os elementos da lista
void destroiL(No **lista)
{
    No *n = *lista;
    while (n != NULL)
    {
        No *aux  = n;
        n = n->prox;
        delete aux;
    }
    *lista = NULL;
}

void mostraL(No **lista)
{
    No *n = *lista;

    cout << "L:{";
    while(n != NULL ) /// enquanto n não for NULL fica no laço
    {
        cout << n->dado;
        n = n->prox;

        if(n != NULL)
            cout << ", ";
    }
    cout << "}\n";
}

//insere no início da lista
bool insereInicioL(No **lista, DadoNoLista valor)
{

    No *novo = new No(); // aloca memória para o nó
    if (novo == NULL)
        return false;

    novo->dado = valor;
    novo->prox = *lista;
    *lista = novo;

    return true;
}

//retorna o valor do primeiro elemento da lista SEM removê-lo
DadoNoLista leInicioL(No **lista)
{
    DadoNoLista dado;
    dado = 0;//se DadoNoLista for uma struct, inicializar os atributos!

    if(vaziaL(lista) == false)
        dado = (*lista)->dado; //atribui o dado do início da lista para a variável dado

    return dado;
}

//retorna o valor do primeiro elemento da lista e REMOVE o elemento
DadoNoLista removeInicioL(No **lista)
{
    No* aux;
    DadoNoLista dado;
    dado = 0;//se DadoNoLista for uma struct, inicializar os atributos!

    if(vaziaL(lista) == false)
    {
        dado = (*lista)->dado; //atribui o dado do início da lista para a variável dado
        aux = *lista; //pega a referenccia do primeiro nó, o qual será removido

        *lista = (*lista)->prox; //atualiza o início da lista para o próximo elemento

        delete aux;
    }

    return dado;
}




///remover um nó da lista com um valor específico
bool removeL(No **lista, DadoNoLista valor)
{
    No *anterior = NULL;
    No *atual = *lista;
    ///fica no laço enquanto tiver elementos na lista
    /// e não encontrar o valor procurado
    while(atual!=NULL && atual->dado != valor)
    {
        anterior = atual;
        atual = atual->prox;
    }
    /// pode sair do laço sem encontrar o valor (atual==NULL)
    /// se encontrar -> atual tem o endereço do elemento para excluir
    if(atual == NULL) /// se atual é NULL -> não encontrou
        return false;

    if (anterior == NULL)
    {
        /// o elemento a ser excluído está no início da lista
        *lista = atual->prox;
    }
    else   /// elemento está no meio ou no fim
    {
        anterior->prox = atual->prox;
    }

    /// libera a memória do elemento
    delete(atual);
    return true;
}


No* buscaL(No **lista, DadoNoLista valor)
{
    No *n = *lista;
    while (n != NULL)
    {
        if (n->dado == valor)
            return n;

        n = n->prox;
    }

    return NULL;
}

int totalL(No **lista) {
    int cont = 0;
    No *n = *lista;

    while(n != NULL) {
        cont ++;

        n = n->prox;
    }

    return cont;
}

bool igualL(No **lista1, No **lista2) {
    No* n1 = *lista1;
    No* n2 = *lista2;

    /*if(totalL(lista1) != totalL(lista2)) // FUNCIONA POREM MUITO MAIS LENTO
        return false;*/

    while(n1 != NULL && n2 != NULL) {
        if(n1->dado != n2->dado)
            return false;

        n1 = n1->prox;
        n2 = n2->prox;
    }

    if(n1 || n2)
        return false;

    return true;
}

void insereFinalL(No **lista, DadoNoLista valor) {

    No *novo = new No();
    No *aux = *lista;

    novo->dado = valor;
    novo->prox = NULL;

    if(!vaziaL(lista)) {

        while(aux->prox != NULL)
            aux = aux->prox;

    } else {
        insereInicioL(lista, valor);
        return;
    }


    aux->prox = novo;
}

DadoNoLista leFinalL(No **lista) {
    DadoNoLista dado;
    dado = 0;//se DadoNoLista for uma struct, inicializar os atributos!
    No *aux = *lista;

    if(vaziaL(lista))
        return dado;

    while(aux->prox != NULL)
        aux = aux->prox;

    dado = aux->dado;

    return dado;
}

DadoNoLista removeFinalL(No **lista) {
    DadoNoLista dado;
    dado = 0;//se DadoNoLista for uma struct, inicializar os atributos!

    No *ultimo = *lista;
    No *penultimo = NULL;
    No *aux = NULL;

    if(vaziaL(lista))
        return dado;

    while(ultimo->prox != NULL) {
        penultimo = ultimo;

        ultimo = ultimo->prox;
    }

    if(penultimo == NULL) {
        dado = ultimo->dado;
        delete(ultimo);
        *lista = NULL;

        return dado;
    } else {
        dado = ultimo->dado;
        delete(ultimo);
        penultimo->prox = NULL;

        return dado;
    }
}

DadoNoLista lePosicao(No **lista, int posicao) {
    DadoNoLista dado;
    dado = 0;//se DadoNoLista for uma struct, inicializar os atributos!
    No *aux = *lista;

    if(vaziaL(lista))
        return dado;

    /*if(totalL(lista) < posicao) // FUNCIONA POREM MENOS OTIMIZADO E BUGA
        return dado;

    for(int i = 0; i < posicao; i++)
        aux = aux->prox;*/

    int cont = 0;

    while(aux != NULL) {

        if(cont == posicao) {
            dado = aux->dado;
            return dado;
        }

        cont++;
        aux = aux->prox;
    }

    return dado;
}

void uniao(No **lista1, No **lista2, No **listaSaida) {
    No* n1 = *lista1;
    No* n2 = *lista2;

    destroiL(listaSaida);
    inicializaL(listaSaida);

    while(n1 != NULL) {
        if(buscaL(listaSaida, n1->dado) == NULL)
            insereInicioL(listaSaida, n1->dado);

        n1 = n1->prox;
    }

    while(n2 != NULL) {
        if(buscaL(listaSaida, n2->dado) == NULL )//&& buscaL(listaSaida, n2->dado) == NULL)
            insereFinalL(listaSaida, n2->dado);

        n2 = n2->prox;
    }
}
#endif // _HPP_LISTA_DINAMICA










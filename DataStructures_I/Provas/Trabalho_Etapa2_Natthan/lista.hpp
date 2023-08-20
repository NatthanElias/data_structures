#ifndef _HPP_LISTA_DESCRITOR
#define _HPP_LISTA_DESCRITOR


typedef int DadoNoLista;

struct No
{
    DadoNoLista dado;
    struct No *prox;
    No() // construtor
    {
        prox = nullptr;
    }
};

struct Lista
{
    No *inicio;
    No *fim;
    int tamanho;
    Lista() /// construtor
    {
        //cout << "\n executando o construtor...\n";
        inicio = nullptr;
        fim = nullptr;
        tamanho =0;
    }
    ~Lista() /// desconstrutor /// quando chame delete(ponteiro)
    {

        No *n = inicio;
        while(n != nullptr)
        {
            No *aux = n;
            n = n->prox;
            delete aux;
        }
    }
};


/// quando cout receber uma struct No
ostream& operator<<(ostream& os, const No *n)
{
    /// cout << n
    return os << n->dado;
}

/// quanto cout receber uma struct Lista
ostream& operator << (ostream& os, const Lista *l)
{
    No *n = l->inicio;
    while(n)
    {
        os << n;
        n = n->prox;
        if(n)
            os << ", ";
    }
    return os;
}

bool vaziaL(Lista *lista)
{
    if(lista->inicio == NULL )
        return true;
    else
        return false;
}

void mostraL(Lista *lista)
{
    No *n = lista->inicio;

    if(vaziaL(lista)) {
        cout << "VAZIA\n";
        return;
    }


    while(n != NULL ) /// enquanto n n�o for NULL fica no la�o
    {
        cout << n->dado;
        n = n->prox;

        if(n != NULL)
            cout << ", ";
    }
    cout << "\n";
}

///insere no in�cio da lista
bool insereInicioL(Lista *lista, DadoNoLista valor)
{

    No *novo = new No();
    if (novo == nullptr)
        return false;

    novo->dado = valor;
    novo->prox = lista->inicio;
    lista->inicio = novo;
    lista->tamanho++;
    if (!lista->fim)
        lista->fim = lista->inicio;

    return true;
}


bool removeL(Lista *lista, DadoNoLista valor)
{
    No *anterior = nullptr;
    No *atual = lista->inicio;
    ///fica no la�o enquanto tiver elementos na lista
    /// e n�o encontrar o valor procurado
    while(atual && atual->dado != valor)
    {
        anterior = atual;
        atual = atual->prox;
    }
    /// pode sair do la�o sem encontrar o valor (atual==NULL)
    /// se encontrar >>> atual tem o endere�o do elemento para excluir
    /// NULL == false    >>> !false == true
    if(!atual) /// se atual � NULL >> n�o encontrou
        return false;
    if (!anterior) /// se anterior � igual a NULL
    {
        /// o elemento a ser exclu�do est� no in�cio da lista
        lista->inicio = atual->prox;
        if (!lista->inicio) ///lista ficou vazia ?
            lista->fim = lista->inicio;
    }
    else   /// elemento est� no meio ou no fim
    {
        anterior->prox = atual->prox;
        if (!atual->prox)/// se for retirado �ltimo da lista
            lista->fim = anterior;
    }
    /// libera a mem�ria do elemento
    lista->tamanho--;

    delete(atual);
    return true;

}

No* buscaL(Lista *lista, DadoNoLista valor)
{
    No *n = lista->inicio;

    if(vaziaL(lista))
        return nullptr;

    while (n)
    {
        if (n->dado == valor)
            return n;

        n = n->prox;
    }

    return nullptr;
}

bool inserePosicaoL(Lista *lista, DadoNoLista valor, int posicao)
{
    No *anterior = NULL;
    No *atual = lista->inicio;
    int p = 0;
    while (atual && p!=posicao)
    {
        anterior = atual;
        atual = atual->prox;
        p++;
    }
    if (p != posicao)
        return false; ///significa q n�o encontrou a posi��o

    No *novo = new No();
    novo->dado = valor;
    if(!anterior)/// inclus�o no in�cio da lista
    {
        novo->prox = lista->inicio;
        lista->inicio = novo;

        if (!lista->fim)
            lista->fim = lista->inicio;
    }
    else
    {
        novo->prox = anterior->prox;
        anterior->prox = novo;

        if (!novo->prox) //o n� adicionado est� no final da lista?
            lista->fim = novo;
    }

    lista->tamanho++;

    return true;
}

bool insereOrdenado(Lista *lista, DadoNoLista valor)
{
    No *anterior = NULL;
    No *atual = lista->inicio;

    while(atual!=NULL && atual->dado <= valor)
    {
        anterior = atual;
        atual = atual->prox;
    }

    No* novo = new No();
    novo->dado= valor;

    if(vaziaL(lista)) //lista vazia??
    {
        novo->prox= NULL;
        lista->inicio = novo;
        lista->fim = novo;
        lista->tamanho++;
    }
    else if(anterior!=NULL && atual == NULL) //insere no final da lista
    {
        novo->prox = NULL;
        anterior->prox = novo;
        lista->tamanho++;
        lista->fim = novo;
    }
    else if (anterior == NULL) //inserir no in�cio da lista!
    {
        novo->prox = atual;
        lista->inicio = novo;
        lista->tamanho++;
    }
    else   /// elemento est� no meio ou no fim
    {
        anterior->prox = novo;
        novo->prox = atual;
        lista->tamanho++;
    }

    return true;
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

bool insereOrdenadoDecrescente(Lista *lista, DadoNoLista valor)
{
    No *anterior = NULL;
    No *atual = lista->inicio;

    while(atual!=NULL && atual->dado >= valor)
    {
        anterior = atual;
        atual = atual->prox;
    }

    No* novo = new No();
    novo->dado= valor;

    if(vaziaL(lista)) //lista vazia??
    {
        novo->prox= NULL;
        lista->inicio = novo;
        lista->fim = novo;
        lista->tamanho++;
    }
    else if(anterior!=NULL && atual == NULL) //insere no final da lista
    {
        novo->prox = NULL;
        anterior->prox = novo;
        lista->tamanho++;
        lista->fim = novo;
    }
    else if (anterior == NULL) //inserir no in�cio da lista!
    {
        novo->prox = atual;
        lista->inicio = novo;
        lista->tamanho++;
    }
    else   /// elemento est� no meio ou no fim
    {
        anterior->prox = novo;
        novo->prox = atual;
        lista->tamanho++;
    }

    return true;
}

DadoNoLista lePosicao(Lista *lista, int posicao) {
    DadoNoLista dado;
    dado = 0;//se DadoNoLista for uma struct, inicializar os atributos!
    No *aux = lista->inicio;

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

No* removeInicioL(Lista *lista)
{
    No *n = lista->inicio;

    lista->inicio = n->prox;
    lista->tamanho--;

    return n;
}

#endif // _HPP_LISTA_DESCRITOR




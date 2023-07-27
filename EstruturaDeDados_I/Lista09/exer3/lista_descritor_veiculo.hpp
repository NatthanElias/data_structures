#ifndef _HPP_LISTA_DESCRITOR_VEICULO
#define _HPP_LISTA_DESCRITOR_VEICULO


typedef Veiculo DadoNoLista;

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
        cout << "\n executando o desconstrutor....\n";
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
    return os << n->dado.placa;
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

void mostraL(Lista *lista)
{
    No *n = lista->inicio;

    cout << "L:{";
    while(n != NULL ) /// enquanto n não for NULL fica no laço
    {
        cout << "Placa: " << n->dado.placa << " | Ano: " << n->dado.ano << " | Fabricante: " << n->dado.fabricante << " | Modelo: " << n->dado.modelo;
        n = n->prox;

        if(n != NULL)
            cout << "\n   ";
    }
    cout << "}\n";
}


bool vaziaL(Lista *lista)
{
    if(lista->inicio == NULL )
        return true;
    else
        return false;
}

///insere no início da lista
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
    ///fica no laço enquanto tiver elementos na lista
    /// e não encontrar o valor procurado
    while(atual && atual->dado.placa != valor.placa)
    {
        anterior = atual;
        atual = atual->prox;
    }
    /// pode sair do laço sem encontrar o valor (atual==NULL)
    /// se encontrar >>> atual tem o endereço do elemento para excluir
    /// NULL == false    >>> !false == true
    if(!atual) /// se atual é NULL >> não encontrou
        return false;
    if (!anterior) /// se anterior é igual a NULL
    {
        /// o elemento a ser excluído está no início da lista
        lista->inicio = atual->prox;
        if (!lista->inicio) ///lista ficou vazia ?
            lista->fim = lista->inicio;
    }
    else   /// elemento está no meio ou no fim
    {
        anterior->prox = atual->prox;
        if (!atual->prox)/// se for retirado último da lista
            lista->fim = anterior;
    }
    /// libera a memória do elemento
    lista->tamanho--;

    delete(atual);
    return true;

}

No* buscaPlacaL(Lista *lista, string valor)
{
    No *n = lista->inicio;
    while (n)
    {
        if (n->dado.placa == valor)
            return n;

        n = n->prox;
    }

    return nullptr;
}

No* buscaFabricanteL(Lista *lista, string valor)
{
    No *n = lista->inicio;
    while (n)
    {
        if (n->dado.fabricante == valor)
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
        return false; ///significa q não encontrou a posição

    No *novo = new No();
    novo->dado = valor;
    if(!anterior)/// inclusão no início da lista
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

        if (!novo->prox) //o nó adicionado está no final da lista?
            lista->fim = novo;
    }

    lista->tamanho++;

    return true;
}

void ordenaL(Lista *lista, int tipo)
{
    No* n = lista->inicio;
    Veiculo Faux;
    Veiculo();
    bool ordenado = true;
    do
    {
        ordenado = true;
        n = lista->inicio;
        while(n->prox)
        {
            if (tipo == ANO)
            {
                if(n->dado.ano > n->prox->dado.ano)
                {
                    Faux = n->dado;
                    n->dado = n->prox->dado;
                    n->prox->dado = Faux;
                    ordenado = false;
                }
            }
            else
            {
                if(n->dado.modelo > n->prox->dado.modelo)
                {
                    Faux = n->dado;
                    n->dado = n->prox->dado;
                    n->prox->dado = Faux;
                    ordenado = false;
                }
            }
            n = n->prox;
        }
    }
    while(ordenado == false);

}

bool removePosicaoL(Lista *lista, int posicao)
{
    No *anterior = nullptr;
    No *atual = lista->inicio;
    int p = 0;
    ///fica no laço enquanto tiver elementos na lista
    /// e não encontrar o valor procurado
    while(atual && p != posicao)
    {
        anterior = atual;
        atual = atual->prox;
        p++;
    }
    /// pode sair do laço sem encontrar o valor (atual==NULL)
    /// se encontrar >>> atual tem o endereço do elemento para excluir
    /// NULL == false    >>> !false == true
    if(!atual) /// se atual é NULL >> não encontrou
        return false;
    if (!anterior) /// se anterior é igual a NULL
    {
        /// o elemento a ser excluído está no início da lista
        lista->inicio = atual->prox;
        if (!lista->inicio) ///lista ficou vazia ?
            lista->fim = lista->inicio;
    }
    else   /// elemento está no meio ou no fim
    {
        anterior->prox = atual->prox;
        if (!atual->prox)/// se for retirado último da lista
            lista->fim = anterior;
    }
    /// libera a memória do elemento
    lista->tamanho--;

    delete(atual);
    return true;
}

bool excluiFabricanteL(Lista *lista, string fabricante)
{
    No *n = lista->inicio;
    int i = 0;
    int cont = -1;
    Veiculo v;
    bool removeu = false;
    while (n)
    {
        removeu = false;
        if (n->dado.fabricante == fabricante && n->dado.ano > 2000)
        {
            cont++;
            removePosicaoL(lista, i);
            n = lista->inicio;
            i = 0;
            removeu = true;
        }
        if (removeu == false)
        {
            i++;
            n = n->prox;
        }
    }
    if (cont == 0)
        return false;
    return true;
}

void imprimeVeiculosFiltro(Lista *lista, string fabricante)
{
    No *n = lista->inicio;
    while(n)
    {
        if (n->dado.fabricante == fabricante)
        {
            cout << n;
            cout << "\n";
        }
        n = n->prox;
    }
}



#endif // _HPP_LISTA_DESCRITOR_VEICULO

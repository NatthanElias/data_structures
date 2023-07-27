#ifndef _HPP_LISTA_DESCRITOR_FUNCIONARIOS
#define _HPP_LISTA_DESCRITOR_FUNCIONARIOS


typedef Funcionario DadoNoListaFunc;

struct NoFuncionarios
{
    DadoNoListaFunc dado;
    struct NoFuncionarios *prox;
    NoFuncionarios() // construtor
    {
        prox = nullptr;
    }
};

struct ListaFuncionarios
{
    NoFuncionarios *inicio;
    NoFuncionarios *fim;
    int tamanho;
    ListaFuncionarios() /// construtor
    {
        //cout << "\n executando o construtor...\n";
        inicio = nullptr;
        fim = nullptr;
        tamanho =0;
    }
    ~ListaFuncionarios() /// desconstrutor /// quando chame delete(ponteiro)
    {
        cout << "\n executando o desconstrutor....\n";
        NoFuncionarios *n = inicio;
        while(n != nullptr)
        {
            NoFuncionarios *aux = n;
            n = n->prox;
            delete aux;
        }
    }
};


/// quando cout receber uma struct NoFuncionarios
ostream& operator<<(ostream& os, const NoFuncionarios *n)
{
    /// cout << n
    return os << n->dado.nome;
}

/// quanto cout receber uma struct Lista
ostream& operator << (ostream& os, const ListaFuncionarios *l)
{
    NoFuncionarios *n = l->inicio;
    while(n)
    {
        os << n;
        n = n->prox;
        if(n)
            os << ", ";
    }
    return os;
}

void mostraL(ListaFuncionarios *lista)
{
    NoFuncionarios *n = lista->inicio;

    cout << "L:{";
    while(n != NULL ) /// enquanto n não for NULL fica no laço
    {
        cout << n->dado.nome;
        n = n->prox;

        if(n != NULL)
            cout << ", ";
    }
    cout << "}\n";
}


bool vaziaL(ListaFuncionarios *lista)
{
    if(lista->inicio == NULL )
        return true;
    else
        return false;
}

///insere no início da lista
bool insereInicioL(ListaFuncionarios *lista, DadoNoListaFunc valor)
{

    NoFuncionarios *novo = new NoFuncionarios();
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


bool removeL(ListaFuncionarios *lista, int cod)
{
    NoFuncionarios *anterior = nullptr;
    NoFuncionarios *atual = lista->inicio;
    ///fica no laço enquanto tiver elementos na lista
    /// e não encontrar o valor procurado
    while(atual && atual->dado.codigo != cod)
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

NoFuncionarios* buscaL(ListaFuncionarios *lista, DadoNoListaFunc valor)
{
    NoFuncionarios *n = lista->inicio;
    while (n)
    {
        if (n->dado.codigo == valor.codigo)
            return n;

        n = n->prox;
    }

    return nullptr;
}

bool inserePosicaoL(ListaFuncionarios *lista, DadoNoListaFunc valor, int posicao)
{
    NoFuncionarios *anterior = NULL;
    NoFuncionarios *atual = lista->inicio;
    int p = 0;
    while (atual && p!=posicao)
    {
        anterior = atual;
        atual = atual->prox;
        p++;
    }
    if (p != posicao)
        return false; ///significa q não encontrou a posição

    NoFuncionarios *novo = new NoFuncionarios();
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

NoFuncionarios* insereOrdenadoL(ListaFuncionarios *lista, Funcionario f)
{
   NoFuncionarios *novo = new NoFuncionarios();
   NoFuncionarios *aux = lista->inicio;
   if (buscaL(lista, f))
        return nullptr;
    if (novo == nullptr)
        return nullptr;

    novo->dado = f;
    novo->prox = nullptr;

    if (lista->inicio == nullptr) // Se a lista auxiliar estiver vazia
    {
        lista->inicio = novo;
        lista->fim = novo;
    }
    else
    {
        NoFuncionarios *atual = lista->inicio;
        NoFuncionarios *anterior = nullptr;

        // Percorre a lista auxiliar até encontrar a posição correta de inserção
        while (atual != nullptr && atual->dado.codigo < f.codigo)
        {
            anterior = atual;
            atual = atual->prox;
        }

        if (anterior == nullptr) // Inserir no início da lista auxiliar
        {
            novo->prox = lista->inicio;
            lista->inicio = novo;
        }
        else // Inserir no meio ou no final da lista auxiliar
        {
            anterior->prox = novo;
            novo->prox = atual;
            if (atual == nullptr) // Inserir no final da lista auxiliar
                lista->fim = novo;
        }
    }

    lista->tamanho++;
    return novo;
}


NoFuncionarios* buscaCodigoL(ListaFuncionarios *lista, int cod)
{
    NoFuncionarios *n = lista->inicio;
    while (n)
    {
        if (n->dado.codigo == cod)
            return n;

        n = n->prox;
    }

    return nullptr;
}

bool insereFinalL(ListaFuncionarios *lista, DadoNoListaFunc valor)
{
    NoFuncionarios *novo = new NoFuncionarios();
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

void ordenaL(ListaFuncionarios *lista, int tipo)
{
    NoFuncionarios* n = lista->inicio;
    Funcionario Faux;
    Funcionario();
    bool ordenado = true;
    do
    {
        ordenado = true;
        n = lista->inicio;
        while(n->prox)
        {
            if (tipo == ALFABETICA)
            {
                if(n->dado.nome > n->prox->dado.nome)
                {
                    Faux = n->dado;
                    n->dado = n->prox->dado;
                    n->prox->dado = Faux;
                    ordenado = false;
                }
            }
            else
            {
                if(n->dado.codigo > n->prox->dado.codigo)
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

NoFuncionarios* buscaCidadeL(ListaFuncionarios *lista, string valor)
{
    NoFuncionarios *n = lista->inicio;
    while (n)
    {
        if (n->dado.cidade == valor)
            return n;

        n = n->prox;
    }

    return nullptr;
}

bool excluiCidadeL(ListaFuncionarios *lista, string cidade)
{
    NoFuncionarios *n = lista->inicio;
    int i = 0;
    int cont = -1;
    bool removeu = false;
    while (n)
    {
        removeu = false;
        if (n->dado.cidade == cidade)
        {
            cont++;
            removeL(lista, n->dado.codigo);
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

void imprimeFuncionariosFiltro(ListaFuncionarios *lista, string tipoSanguineo)
{
    NoFuncionarios *n = lista->inicio;
    int cont = 0;
    while(n)
    {
        if (n->dado.tipoSanguineo == tipoSanguineo)
        {
            if(cont == 0)
                cout << "\nFUNCIONÁRIOS DE TIPO SANGUÍNEO " << tipoSanguineo << ": ";
            cont++;
            cout << n;
            cout << "\n";
        }
        n = n->prox;
    }
    if (cont == 0)
    {
        cout << "\nNÃO HÁ FUNCIONÁRIOS COM O TIPO SANGUÍNEO " << tipoSanguineo << " CADASTRADOS!\n";
    }
}


#endif // _HPP_LISTA_DESCRITOR




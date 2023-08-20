#ifndef _HPP_LISTA_DESCRITOR_FUNC
#define _HPP_LISTA_DESCRITOR_FUNC

struct Funcionario
{
    int IDF;
    string nome;
    char sexo;
    Funcionario()
    {
        IDF=0;
        nome="";
        sexo=' ';
    }
    Funcionario(int id, string n, char s)
    {
        IDF=id;
        nome=n;
        sexo=s;
    }

};
typedef Funcionario DadoNoListaFunc;

struct NoFunc
{
    DadoNoListaFunc dado;
    struct NoFunc *prox;
    NoFunc() // construtor
    {
        prox = nullptr;
    }
};

struct ListaFunc
{
    NoFunc *inicio;
    NoFunc *fim;
    int tamanho;
    ListaFunc() /// construtor
    {
        //cout << "\n executando o construtor...\n";
        inicio = nullptr;
        fim = nullptr;
        tamanho =0;
    }
    ~ListaFunc() /// desconstrutor /// quando chame delete(ponteiro)
    {
        NoFunc *n = inicio;
        while(n != nullptr)
        {
            NoFunc *aux = n;
            n = n->prox;
            delete aux;
        }
    }
};

/// quando cout receber uma struct No
ostream& operator<<(ostream& os, Funcionario f)
{
    /// cout << n
    return os << f.nome;
}
ostream& operator<<(ostream& os, const NoFunc *n)
{
    /// cout << n
    os << "Identificador: " << n->dado.IDF << "\n";
    os << "Nome: " << n->dado.nome << "\n";
    os << "Sexo: " << n->dado.sexo << "\n";
    os << "______________________\n";

    return os;
}

/// quanto cout receber uma struct Lista
ostream& operator << (ostream& os, const ListaFunc *l)
{
    NoFunc *n = l->inicio;
    while(n)
    {
        os << n;
        n = n->prox;
        if(n)
            os << ", ";
    }
    return os;
}

void mostraFuncL(ListaFunc *lista)
{
    NoFunc *n = lista->inicio;

    while(n != NULL ) /// enquanto n não for NULL fica no laço
    {
        cout << n->dado.nome;
        n = n->prox;

        if(n != NULL)
            cout << ", ";
    }
    cout << "\n";
}


bool vaziaL(ListaFunc *lista)
{
    if(lista->inicio == NULL )
        return true;
    else
        return false;
}

///insere no início da lista
bool insereInicioL(ListaFunc *lista, DadoNoListaFunc valor)
{

    NoFunc *novo = new NoFunc();
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


bool removeFuncL(ListaFunc *lista, int idFuncionario)
{
    NoFunc *anterior = nullptr;
    NoFunc *atual = lista->inicio;
    ///fica no laço enquanto tiver elementos na lista
    /// e não encontrar o valor procurado
    while(atual && atual->dado.IDF != idFuncionario)
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

NoFunc* buscaFuncID(ListaFunc *lista, int idFunc)
{
    NoFunc *n = lista->inicio;

    //cout << lista->inicio;
    while (n)
    {
        if (n->dado.IDF == idFunc)
            return n;

        n = n->prox;
    }

    return nullptr;
}

bool inserePosicaoL(ListaFunc *lista, DadoNoListaFunc valor, int posicao)
{
    NoFunc *anterior = NULL;
    NoFunc *atual = lista->inicio;
    int p = 0;
    while (atual && p!=posicao)
    {
        anterior = atual;
        atual = atual->prox;
        p++;
    }
    if (p != posicao)
        return false; ///significa q não encontrou a posição

    NoFunc *novo = new NoFunc();
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


bool insereOrdenado(ListaFunc *lista, DadoNoListaFunc valor)
{
    NoFunc *anterior = NULL;
    NoFunc *atual = lista->inicio;

    while(atual!=NULL && atual->dado.IDF <= valor.IDF)
    {
        anterior = atual;
        atual = atual->prox;
    }

    NoFunc* novo = new NoFunc();
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
    else if (anterior == NULL) //inserir no início da lista!
    {
        novo->prox = atual;
        lista->inicio = novo;
        lista->tamanho++;
    }
    else   /// elemento está no meio ou no fim
    {
        anterior->prox = novo;
        novo->prox = atual;
        lista->tamanho++;
    }

    return true;
}



#endif // _HPP_LISTA_DESCRITOR_FUNC




#ifndef _HPP_FILAPJ_DINAMICA
#define _HPP_FILAPJ_DINAMICA


struct NoFilaPJ
{
    OrdemPJ dado; //informacao do nó
    NoFilaPJ *prox; //proximo elemento da fila
};

struct FilaPJ
{
    NoFilaPJ *inicio;
    NoFilaPJ *fim;

    FilaPJ(){ //Construtor. Usado para inicializar os dados das variáveis da struct
        inicio = nullptr;
        fim = nullptr;
    }
};


bool vaziaF(FilaPJ *f)
{
    if (f->inicio == NULL) //verifica se a fila está vazia, ou seja, (f->inicio == NULL)
        return true;
    else
        return false;
}


//Enqueue
bool enfileiraF(FilaPJ *f, OrdemPJ dado)
{
    NoFilaPJ *novo = new NoFilaPJ();
    if (novo == NULL) /// não conseguiu alocar memória (novo == NULL)
        return false;

    novo->dado = dado;
    novo->prox = nullptr;
    if (f->inicio == NULL) //verifica se a fila está vazia, ou seja, (f->inicio == NULL)
        f->inicio = novo;
    else
        f->fim->prox = novo;

    f->fim = novo;
    return true;
}

//Dequeue
OrdemPJ desenfileiraF(FilaPJ *f)
{
    OrdemPJ dado;
	dado.CNPJ = " ";
	dado.placa = " ";

    // se não estiver vazia, retira valor
    if (vaziaF(f) == false) //verifica se a fila não está vazia, ou seja, (f->inicio != NULL)
    {
        dado = f->inicio->dado; //pega o dado armazenado no primeiro nó
        NoFilaPJ *apagar = f->inicio; //guarda o primeiro nó em uma variável auxiliar;
        f->inicio = f->inicio->prox; // atualiza o início da fila
        delete apagar;  // libera a memória

        if (f->inicio == NULL) //verifica se a fila está vazia, ou seja, (f->inicio == NULL)
            f->fim = nullptr;
    }

    return dado;
}

//peek
OrdemPJ espiaF(FilaPJ* f)
{
    OrdemPJ dado;
	dado.CNPJ = " ";
	dado.placa = " ";

    if (vaziaF(f) == false) //verifica se a fila não está vazia, ou seja, (f->inicio != NULL)
    {
        dado = f->inicio->dado;
    }

    return dado;
}

//show
void mostraF(FilaPJ *f)
{
    cout << "Fila: ";

    if(vaziaF(f) == false) //verifica se a fila não está vazia
    {

        cout << "[";

        NoFilaPJ *no = f->inicio;
        while (no != NULL) //faça enquanto (no != NULL)
        {
            cout << "{" << no->dado.CNPJ  << ", " << no->dado.placa << "} ";
            no = no->prox;

            if(no != NULL) //verifica se o próximo nó não é nulo (no != NULL)
                cout << ", ";
        }
        cout << "]" << endl;
    }
    else
        cout << "vazia!\n";
}

// retorna true se o valor existe na fila
// retorna false se o valor não existe na fila
bool buscaF(FilaPJ *f, string placa)
{

    NoFilaPJ *no = f->inicio;
    while (no != NULL) //faça enquanto (no != NULL)
    {
        if(no->dado.placa == placa)
            return true;

        no = no->prox;
    }

    return false;
}

void destroiF(FilaPJ *f)
{

    NoFilaPJ *no = f->inicio;
    while (no != NULL) //faça enquanto (no != NULL)
    {
        NoFilaPJ *apagar = no; //guarda o nó em uma variável auxiliar;

        no = no->prox;

        delete apagar;
    }

    f->inicio = nullptr;
    f->fim = nullptr;
}

#endif // _HPP_FILA_DINAMICA






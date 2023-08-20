#ifndef _HPP_FILAPF_DINAMICA
#define _HPP_FILAPF_DINAMICA


struct NoFilaPF
{
    OrdemPF dado; //informacao do nó
    NoFilaPF *prox; //proximo elemento da fila
};

struct FilaPF
{
    NoFilaPF *inicio;
    NoFilaPF *fim;

    FilaPF(){ //Construtor. Usado para inicializar os dados das variáveis da struct
        inicio = nullptr;
        fim = nullptr;
    }
};


bool vaziaF(FilaPF *f)
{
    if (f->inicio == NULL) //verifica se a fila está vazia, ou seja, (f->inicio == NULL)
        return true;
    else
        return false;
}


//Enqueue
bool enfileiraF(FilaPF *f, OrdemPF dado)
{
    NoFilaPF *novo = new NoFilaPF();
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
OrdemPF desenfileiraF(FilaPF *f)
{
    OrdemPF dado;
	dado.CPF = " ";
	dado.placa = " ";
	dado.revisao = false;

    // se não estiver vazia, retira valor
    if (vaziaF(f) == false) //verifica se a fila não está vazia, ou seja, (f->inicio != NULL)
    {
        dado = f->inicio->dado; //pega o dado armazenado no primeiro nó
        NoFilaPF *apagar = f->inicio; //guarda o primeiro nó em uma variável auxiliar;
        f->inicio = f->inicio->prox; // atualiza o início da fila
        delete apagar;  // libera a memória

        if (f->inicio == NULL) //verifica se a fila está vazia, ou seja, (f->inicio == NULL)
            f->fim = nullptr;
    }

    return dado;
}

//peek
OrdemPF espiaF(FilaPF* f)
{
    OrdemPF dado;
	dado.CPF = " ";
	dado.placa = " ";
	dado.revisao = false;

    if (vaziaF(f) == false) //verifica se a fila não está vazia, ou seja, (f->inicio != NULL)
    {
        dado = f->inicio->dado;
    }

    return dado;
}

//show
void mostraF(FilaPF *f)
{
    cout << "Fila: ";

    if(vaziaF(f) == false) //verifica se a fila não está vazia
    {

        cout << "[";

        NoFilaPF *no = f->inicio;
        while (no != NULL) //faça enquanto (no != NULL)
        {
            cout << "{" << no->dado.CPF  << ", " << no->dado.placa << ", " << no->dado.revisao << "} ";
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
bool buscaF(FilaPF *f, string placa)
{

    NoFilaPF *no = f->inicio;
    while (no != NULL) //faça enquanto (no != NULL)
    {
        if(no->dado.placa == placa)
            return true;

        no = no->prox;
    }

    return false;
}

void destroiF(FilaPF *f)
{

    NoFilaPF *no = f->inicio;
    while (no != NULL) //faça enquanto (no != NULL)
    {
        NoFilaPF *apagar = no; //guarda o nó em uma variável auxiliar;

        no = no->prox;

        delete apagar;
    }

    f->inicio = nullptr;
    f->fim = nullptr;
}

#endif // _HPP_FILA_DINAMICA






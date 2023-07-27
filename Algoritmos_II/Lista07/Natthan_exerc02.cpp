#include <iostream>

using namespace std;

struct Produto
{
    int cod;
    string nome;
    string unidade;
    float valor;
    int qtd;
};

void cadastrar(Produto *v, int *i);
void listar(Produto *v, int *i);
void consultar(Produto *v, int *i);
void vender(Produto *v, int *i);

int main()
{
    setlocale(LC_ALL, "portuguese");
    cout << fixed;
    cout.precision(2);

    Produto estoque[50];
    int menu, indice = -1;

    do
    {
        system("cls");
        cout << "####MENU####\n";
        cout << "0 – Sair\n";
        cout << "1 – Cadastrar produto\n";
        cout << "2 – Listar produtos cadastrados\n";
        cout << "3 – Consultar produto pelo código\n";
        cout << "4 – Vender produto\n";
        cin >> menu;
        fflush(stdin);

        switch(menu)
        {
            case 0:
                system("cls");
                cout << "Programa finalizado!\n";
                break;
            case 1:
                system("cls");
                if(indice > 48)
                {
                    cout << "Limite de cadastros atingido!";
                    getchar();
                    break;
                }
                else
                {
                    cadastrar(estoque, &indice);
                    cout << "\nProduto cadastrado com sucesso!";
                    getchar();
                    break;
                }
            case 2:
                system("cls");
                listar(estoque, &indice);
                getchar();
                break;
            case 3:
                system("cls");
                consultar(estoque, &indice);
                getchar();
                break;
            case 4:
                system("cls");
                vender(estoque, &indice);
                getchar();
                break;
            default:
              system("cls");
              cout << "Opcao invalida!";
              getchar();
              break;
        }

    } while(menu != 0);

    return 0;
}

void cadastrar(Produto *v, int *i)
{
    (*i)++;

    cout << "Informe o codigo do produto: ";
    cin >> v[*i].cod;
    fflush(stdin);

    cout << "Informe o nome do produto: ";
    getline(cin, v[*i].nome);
    fflush(stdin);

    cout << "Informe a unidade de medida: ";
    getline(cin, v[*i].unidade);
    fflush(stdin);

    cout << "Informe o valor do produto: ";
    cin >> v[*i].valor;
    fflush(stdin);

    cout << "Informe a quantidade no estoque: ";
    cin >> v[*i].qtd;
    fflush(stdin);
}

void listar(Produto *v, int *i)
{
    int j, *pj = &j;

    for(*pj = 0; *pj <= *i; (*pj)++)
    {
        cout << "Codigo: " << v[*pj].cod << "\n";
        cout << "Nome: " << v[*pj].nome << "\n";
        cout << "Unidade: " << v[*pj].unidade << "\n";
        cout << "Valor: " << v[*pj].valor << "\n";
        cout << "Quantidade: " << v[*pj].qtd << "\n";
        cout << "------------------------\n";
    }
}

void consultar(Produto *v, int *i)
{
    int aux, j, *pj = &j;
    bool t = false;

    cout << "Informe o codigo do produto que deseja consultar: ";
    cin >> aux;

    for(*pj = 0; *pj <= *i; (*pj)++)
    {
        if(aux == v[*pj].cod)
        {
            t = true;
            cout << "\nCodigo: " << v[*pj].cod << "\n";
            cout << "Nome: " << v[*pj].nome << "\n";
            cout << "Unidade: " << v[*pj].unidade << "\n";
            cout << "Valor: " << v[*pj].valor << "\n";
            cout << "Quantidade: " << v[*pj].qtd << "\n";
            getchar();
            return;
        }
    }

    if(!t)
    {
        cout << "ERRO: Codigo informado invalido!";
        getchar();
    }
}

void vender(Produto *v, int *i)
{
    int x, y, j, *pj = &j;
    bool t = false;

    cout << "Informe o codigo: ";
    cin >> x;

    cout << "Informe a quantidade: ";
    cin >> y;

    for(*pj = 0; *pj <= *i; (*pj)++)
    {
        if(x == v[*pj].cod)
        {
            t = true;
            if(y <= v[*pj].qtd)
            {
                v[*pj].qtd -= y;
                cout << "Venda realizada!";
                getchar();
                return;
            }
            else
            {
                cout << "ERRO: Temos apenas " << v[*pj].qtd << " itens no estoque!\n";
                getchar();
                return;
            }

        }
    }

    if(!t)
    {
        cout << "ERRO: Codigo informado invalido!";
        getchar();
    }
}

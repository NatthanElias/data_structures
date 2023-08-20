#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>

using namespace std;

void tamanho_vetor(int **qtd);
void gerar (int *v, int **t, int **l);
void mostrar (int *v, int **t);
void consultar (int *v, int *s, int **t, int **leu_2, int **c);

main()
{
    setlocale(LC_ALL, "Portuguese");
    int *tam = new int, *menu = new int;
    int *leu = new int(-1), *leu2 = new int(-1), *cont = new int(0);
    tamanho_vetor(&tam);
    int *vet = new int[*tam];
    int *sobra = new int[*tam];
    do
    {
        system("cls");
        cout << "MENU DE OPÇÕES" << endl;
        cout << "0- SAIR" << endl;
        cout << "1- GERAR VALORES" << endl;
        cout << "2- LOCALIZAR VALOR" << endl;
        cout << "3- MOSTRAR VETOR 'vet'" << endl;
        cout << "4- MOSTRAR VETOR 'sobra'" << endl;
        cout << "\nSUA ESCOLHA: ";
        cin >> *menu;
        fflush(stdin);
        switch(*menu)
        {
        case 0:
            system("cls");
            cout << "PROGRAMA FINALIZADO COM SUCESSO!";
            break;

        case 1:
            system("cls");
            gerar(vet, &tam, &leu);
            cout << "VETOR GERADO COM SUCESSO!";
            getchar();
            break;

        case 2:
            system("cls");
            if (*leu == -1)
                cout << "É NECESSÁRIO GERAR ELEMENTOS PARA O VETOR!";
            else
            {
                consultar(vet, sobra, &tam, &leu2, &cont);
            }
            getchar();
            break;
        case 3:
            system("cls");
            if (*leu == -1)
                cout << "É NECESSÁRIO GERAR ELEMENTOS PARA O VETOR!";
            else
            {
                cout << "ELEMENTOS DO VETOR: ";
                mostrar(vet, &tam);
            }
            getchar();
            break;
        case 4:
            system("cls");
            if (*leu2 == -1)
                cout << "É NECESSÁRIO EXECUTAR A OPÇÃO 2 PRIMEIRAMENTE!" << endl;
            else if (*cont == 0)
                cout << "O VETOR SOBRA NÃO POSSUI NENHUM ELEMENTO!" << endl;
            else
            {
                mostrar(sobra, &cont);
            }
            getchar();
            break;

        default:
            system("cls");
            cout << "VALOR INVÁLIDO!";
            getchar();
        }
    }
    while(*menu != 0);
}

void tamanho_vetor(int **qtd)
{
    do
    {
        cout << "INFORME A QUANTIDADE DE ELEMENTOS DO VETOR: ";
        cin >> (**qtd);
        fflush(stdin);
        if(**qtd < 5 || **qtd > 50)
        {
            cout << "\nTAMANHO DO VETOR É INVÁLIDO.";
            getchar();
            system("cls");
        }
    }
    while(**qtd < 5 || **qtd > 50);
}

void gerar (int *v, int **t, int **l)
{
    (**l)++;
    srand(time(NULL));

    int *i = new int;
    int *j = new int;
    int *aux = new int;
    int *flag = new int;
    int *pv = new int[**t];

    pv = v;

    for (*i = 0; *i < **t; (*i)++)
    {
        *aux = rand() % 5 + 1;
        if (*i == 0)
            *v = *aux;
        else
        {
            *flag = 0;
            for (*j = 0; *j < *i; (*j)++)
            {
                if (*pv == *aux)
                {
                    *flag = 1;
                    //cout << "\nGerou duplicado " << *aux << endl;
                    break;
                }
                pv++;
            }
            pv -= *j;
            if (*flag == 0)
                *v  = *aux;
            else
            {
                (*i)--;
                v--;
            }
        }
        v++;
    }
    delete i;
    delete j;
    delete aux;
    delete flag;
}

void mostrar (int *v, int **t)
{
    int *i = new int;
    for (*i = 0; *i < **t; (*i)++)
    {
        cout << *v << ", ";
        v++;
    }
    v -= *i;
    delete i;
}


void consultar (int *v, int *s, int **t, int **leu_2, int **c)
{
    if (**c == **t)
        **c = 0;

    (**leu_2)++;
    int *num = new int;
    int *i = new int;
    int *j = new int(0);
    cout << "\nINFORME O VALOR QUE DESEJA CONSULTAR: ";
    cin >> *num;
    fflush(stdin);
    for (*i = 0; *i < **t; (*i)++)
    {
        if (*num == *v)
        {
            (*j)++;
            break;
        }
        v++;
    }
    if (*j == 0)
    {
        cout << "\nO VALOR " << *num << " NÃO PERTENCE AO VETOR" << endl;
        s += **c;
        *s = *num;
        (**c)++;
        cout << "VALOR INCLUÍDO NO VETOR SOBRA COM SUCESSO.";
    }
    else
    {
        cout << "\nO VALOR " << *num << " PERTENCE AO VETOR" << endl;
        cout << "SUA POSIÇÃO NA MEMÓRIA É: " << v << endl;
    }
    delete num;
    delete i;
    delete j;
}


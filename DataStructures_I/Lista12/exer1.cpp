#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <ctime>
#include <string>

using namespace std;

enum
{
    ALFABETICA = 1,
    CODIGO = 2
};

struct Funcionario
{
    int codigo;
    string nome;
    char sexo;
    string cidade;
    int anoNascimento;
    string tipoSanguineo;   // A+, B+, AB+, O+, A-, B-, AB-, O-
    Funcionario()
    {
        codigo = 0;
        nome = " ";
        sexo = ' ';
        cidade = " ";
        anoNascimento = 0;
        tipoSanguineo = " ";
    }
};

#include "lista_funcionarios.hpp"
#include "menu.hpp"

int contagemFunc(ListaFuncionarios* lista);

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    int opcao = 0;
    ifstream myFile("cadastro.txt");
    ListaFuncionarios* L1 = new ListaFuncionarios();   // lista com todas as infos dos funcion�rios
    /// leitura de arquivos e inser��o na lista

    while(!myFile.eof())
    {
        Funcionario f;
        string codigo;
        string ano;
        string sexo;
        if (getline(myFile, codigo, '#') &&
                getline(myFile, f.nome, '#') &&
                getline(myFile, sexo, '#') &&
                getline(myFile, f.cidade, '#') &&
                getline(myFile, ano, '#') &&
                getline(myFile, f.tipoSanguineo))
        {
            f.codigo = std::stoi(codigo);
            f.sexo = (char)sexo[0];
            f.anoNascimento = std::stoi(ano);

            insereFinalL(L1, f);
        }
    }
    myFile.close();
    do
    {
        menu(&opcao);
        system("cls");
        if (opcao == 1)
        {
            cout << "OP��O ESCOLHIDA - MOSTRAR FUNCION�RIOS (1)\n\n";
            cout << L1 << "\n";
            system("pause");
            system("cls");
        }
        else if (opcao == 2)
        {
            int tipo = 0;
            do
            {
                cout << "OP��O ESCOLHIDA - ORDENAR LISTA DE VE�CULOS (2)\n\n";
                cout << "TIPO DE ORDENA��O\n";
                cout << "- ORDEM ALFAB�TICA(1)\n";
                cout << "- PELO C�DIGO (2)\n";
                cout << "SUA ESCOLHA: ";
                cin >> tipo;
                fflush(stdin);
                if (tipo != ALFABETICA && tipo != CODIGO)
                {
                    cout << "TIPO INV�LIDO!\n";
                    system("pause");
                    system("cls");
                }
            }
            while(tipo != ALFABETICA && tipo != CODIGO);
            ordenaL(L1, tipo);
            system("pause");
            system("cls");
        }
        else if (opcao == 3)
        {
            int cod = 0;
            cout << "OP��O ESCOLHIDA - REMOVER FUNCION�RIO(3)\n\n";
            cout << "C�DIGO DO FUNCION�RIO: ";
            cin >> cod;
            fflush(stdin);
            NoFuncionarios *nAux = buscaCodigoL(L1, cod);
            if (nAux == nullptr)
            {
                cout << "FUNCION�RIO DE C�DIGO " << cod << " N�O CADASTRADO!\n";
            }
            else
            {
                removeL(L1, cod);
                cout << "FUNCION�RIO DE C�DIGO " << cod << " REMOVIDO COM SUCESSO!\n";
            }
            cout << endl;
            system("pause");
            system("cls");
        }
        else if (opcao == 4)
        {
            string cidade = " ";
            cin.ignore();   // para limpar o buffer e n�o dar erro no getline
            cout << "OP��O ESCOLHIDA - REMOVER FUNCION�RIOS DE UMA CIDADE (4)\n\n";
            cout << "CIDADE: ";
            getline(cin, cidade);
            fflush(stdin);
            NoFuncionarios* nAux = buscaCidadeL(L1, cidade);
            if (nAux == nullptr)
            {
                cout << "N�O H� FUNCION�RIOS DE " << cidade << " CADASTRADOS!\n";
            }
            else
            {
                excluiCidadeL(L1, cidade);
                cout << "FUNCION�RIO(S) DE " << cidade << " REMOVIDO(S) COM SUCESSO!\n";
            }
            cout << endl;
            system("pause");
            system("cls");
        }
        else if (opcao == 5)
        {
            cout << "OP��O ESCOLHIDA - MOSTRAR INFORMA��ES DOS FUNCION�RIOS (5)\n\n";
            cout << "N�MERO DE FUNCION�RIOS: " << L1->tamanho << "\n";
            int total = contagemFunc(L1);
            cout << "N�MERO DE FUNCION�RIOS ACIMA DE 29 ANOS: " << total << "\n";
            cout << endl;
            system("pause");
            system("cls");
        }
        else if (opcao == 6)
        {
            string tipoSanguineo;
            cin.ignore();
            do
            {
            cout << "OP��O ESCOLHIDA - FILTRAR POR TIPO SANGU�NEO (6)\n\n";
                cout << "TIPO SANGU�NEO: ";
                cin >> tipoSanguineo;
                fflush(stdin);
                if (tipoSanguineo != "A+" &&
                        tipoSanguineo != "A-" &&
                        tipoSanguineo != "B+" &&
                        tipoSanguineo != "B-" &&
                        tipoSanguineo != "O+" &&
                        tipoSanguineo != "O-" &&
                        tipoSanguineo != "AB+" &&
                        tipoSanguineo != "AB-")
                {
                    cout << "\nTIPO SANGU�NEO INV�LIDO!\n";
                    system("pause");
                    system("cls");
                }
            }
            while(tipoSanguineo != "A+" &&
                    tipoSanguineo != "A-" &&
                    tipoSanguineo != "B+" &&
                    tipoSanguineo != "B-" &&
                    tipoSanguineo != "O+" &&
                    tipoSanguineo != "O-" &&
                    tipoSanguineo != "AB+" &&
                    tipoSanguineo != "AB-");
            imprimeFuncionariosFiltro(L1, tipoSanguineo);
            cout << endl;
            system("pause");
            system("cls");
        }
        else if (opcao == 7)
        {
            break;
        }
        else
        {
            cout << "OP��O INV�LIDA!\n";
            system("pause");
            system("cls");
        }
    }
    while(opcao != 7);

    cout << "PROGRAMA ENCERRADO COM SUCESSO!\n";

    delete(L1);
    return EXIT_SUCCESS;
}

int contagemFunc(ListaFuncionarios* lista)
{
    time_t t = time(NULL);
    tm* timePtr = localtime(&t);
    int total = 0, idadeObj = 29;
    NoFuncionarios* n = lista->inicio;

    while (n)
    {
        if (timePtr->tm_year + 1900 - n->dado.anoNascimento > idadeObj)
            total++;
        n = n->prox;
    }
    return total;
}

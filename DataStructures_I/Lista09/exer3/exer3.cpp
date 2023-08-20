/* ENUNCIADO: Fa�a um programa de uma empresa de carros, em que ela mant�m uma lista de ve�culos com os seguintes dados (placa, ano, fabricante,
modelo). Ao iniciar, a leitura de um arquivo texto "cadastro.txt" � realizada. Exemplo de arquivo texto:
            abc1256#2000#volkswagen#fusca#
            xyz5566#1975#willys#rural#
            klw6598#2015#fiat#uno#
    Cada linha armazena os dados de um ve�culo, separados pelo delimitador '#' e estruturado da seguinte forma: placa (string), ano (int), fabricante
(string) e modelo (string).
    A cada linha do arquivo texto lida, o sistema cria um registro de um ve�culo e realiza a inser��o no in�cio da lista de ve�culos.
    Ap�s a leitura do arquivo texto e a cria��o da lista contendo os dados dos ve�culos, o sistema exibe o seguinte menu de opera��es:
    1 - Mostrar lista de ve�culos
    2 - Ordenar lista de ve�culos - o sistema solicita  ao usu�rio o tipo de exibi��o da lista,se deve ser ordenada pelo ano (ordem crescente)
    ou pelo modelo (ordem alfab�tica);
    3 - Remover um ve�culo da lista - o sistema solicita ao usu�rio a placa, e o programa remove da lista o ve�culo
    4 - Remover ve�culos com base no fabricante e no ano: o sistema solicita ao usu�rio o nome do fabricante e, em seguida, todos os ve�culos
cujo o ano de fabrica��o � superior a 2000 e pertencem ao fabricante informado devem ser removidos da lista.
    5 - Filtrar ve�culo - o usu�rio informa o nome do fabricante e o sistema mostra a placa dos ve�culos que s�o do fabricante informado.
*/

/* DICAS: j� est�o na quest�o.
*/

#include <iostream>
#include<fstream>
#include <cstring>
#include <iomanip>

using namespace std;

enum
{
    ANO = 1,
    MODELO = 2
};

struct Veiculo
{
    string placa;
    int ano;
    string fabricante;
    string modelo;

    Veiculo()
    {
        placa = " ";
        ano = 0;
        fabricante = " ";
        modelo = " ";
    }
};

#include "menu.hpp"
#include "lista_descritor_veiculo.hpp"

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    ifstream myFile("cadastro.txt");
    string linha = " ";
    string dado = " ";
    Veiculo v1;
    Lista* L = new Lista();
    int opcao = 0;

    if (myFile.is_open())
    {
        while(getline(myFile, linha))
        {
            stringstream ss(linha);
            getline(ss, dado, '#');
            v1.placa = dado;
            getline(ss, dado, '#');
            v1.ano = stoi(dado);
            getline(ss, dado, '#');
            v1.fabricante = dado;
            getline(ss, dado, '#');
            v1.modelo = dado;
            insereInicioL(L, v1);
        }
    }
    myFile.close();

    do
    {
        menu(&opcao);
        system("cls");
        if (opcao == 1)
        {
            cout << "OP��O ESCOLHIDA - MOSTRAR LISTA DE VE�CULOS (1)\n\n";
            mostraL(L);
            cout << endl;
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
                cout << "- POR ANO (1)\n";
                cout << "- POR MODELO (2)\n";
                cout << "SUA ESCOLHA: ";
                cin >> tipo;
                fflush(stdin);
                if (tipo != 1 && tipo != 2)
                {
                    cout << "TIPO INV�LIDO!\n";
                    system("pause");
                    system("cls");
                }
            }
            while(tipo != 1 && tipo != 2);
            ordenaL(L, tipo);
            system("pause");
            system("cls");
        }
        else if (opcao == 3)
        {
            string placa;
            cout << "OP��O ESCOLHIDA - REMOVER VE�CULO DA LISTA (3)\n\n";
            cout << "PLACA DO VE�CULO: ";
            cin >> placa;
            fflush(stdin);
            No *nAux = buscaPlacaL(L, placa);
            if (nAux == nullptr)
            {
                cout << "VE�CULO N�O ENCONTRADO!\n";
            }
            else
            {
                removeL(L, nAux->dado);
                cout << "VE�CULO DE PLACA " << placa << " REMOVIDO COM SUCESSO!\n";
            }
            cout << endl;
            system("pause");
            system("cls");
        }
        else if (opcao == 4)
        {
            string fabricante = " ";
            cout << "OP��O ESCOLHIDA - REMOVER VE�CULO DA LISTA COM BASE NO FABRICANTE (4)\n\n";
            cout << "FABRICANTE: ";
            cin >> fabricante;
            fflush(stdin);
            No* nAux = buscaFabricanteL(L, fabricante);
            if (nAux == nullptr)
            {
                cout << "FABRICANTE N�O REGISTRADO!\n";
            }
            else
            {
                if (!excluiFabricanteL(L, fabricante))
                {
                    cout << "N�O H� CARROS DESSE FABRICANTE COM ANO ACIMA DE 2000!\n";
                }
                else
                {
                    cout << "VE�CULO(S) REMOVIDO(S) COM SUCESSO!\n";
                }
            }
            cout << endl;
            system("pause");
            system("cls");

        }
        else if (opcao == 5)
        {
            string fabricante = " ";
            cout << "OP��O ESCOLHIDA - FILTRAR VE�CULOS POR FABRICANTE (5)\n\n";
            cout << "FABRICANTE: ";
            cin >> fabricante;
            fflush(stdin);
            No* nAux = buscaFabricanteL(L, fabricante);
            if (nAux == nullptr)
            {
                cout << "FABRICANTE N�O REGISTRADO!\n";
            }
            else
            {
                cout << "\nPLACAS DO(S) VE�CULO(S) DA " << fabricante << ":\n";
                imprimeVeiculosFiltro(L, fabricante);
            }
            cout << endl;
            system("pause");
            system("cls");
        }
        else if (opcao == 6)
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
    while(opcao != 6);

    cout << "PROGRAMA ENCERRADO COM SUCESSO!\n";

    delete(L);
    return EXIT_SUCCESS;
}



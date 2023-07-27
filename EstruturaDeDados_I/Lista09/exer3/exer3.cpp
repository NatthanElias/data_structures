/* ENUNCIADO: Faça um programa de uma empresa de carros, em que ela mantém uma lista de veículos com os seguintes dados (placa, ano, fabricante,
modelo). Ao iniciar, a leitura de um arquivo texto "cadastro.txt" é realizada. Exemplo de arquivo texto:
            abc1256#2000#volkswagen#fusca#
            xyz5566#1975#willys#rural#
            klw6598#2015#fiat#uno#
    Cada linha armazena os dados de um veículo, separados pelo delimitador '#' e estruturado da seguinte forma: placa (string), ano (int), fabricante
(string) e modelo (string).
    A cada linha do arquivo texto lida, o sistema cria um registro de um veículo e realiza a inserção no início da lista de veículos.
    Após a leitura do arquivo texto e a criação da lista contendo os dados dos veículos, o sistema exibe o seguinte menu de operações:
    1 - Mostrar lista de veículos
    2 - Ordenar lista de veículos - o sistema solicita  ao usuário o tipo de exibição da lista,se deve ser ordenada pelo ano (ordem crescente)
    ou pelo modelo (ordem alfabética);
    3 - Remover um veículo da lista - o sistema solicita ao usuário a placa, e o programa remove da lista o veículo
    4 - Remover veículos com base no fabricante e no ano: o sistema solicita ao usuário o nome do fabricante e, em seguida, todos os veículos
cujo o ano de fabricação é superior a 2000 e pertencem ao fabricante informado devem ser removidos da lista.
    5 - Filtrar veículo - o usuário informa o nome do fabricante e o sistema mostra a placa dos veículos que são do fabricante informado.
*/

/* DICAS: já estão na questão.
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
            cout << "OPÇÃO ESCOLHIDA - MOSTRAR LISTA DE VEÍCULOS (1)\n\n";
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
                cout << "OPÇÃO ESCOLHIDA - ORDENAR LISTA DE VEÍCULOS (2)\n\n";
                cout << "TIPO DE ORDENAÇÃO\n";
                cout << "- POR ANO (1)\n";
                cout << "- POR MODELO (2)\n";
                cout << "SUA ESCOLHA: ";
                cin >> tipo;
                fflush(stdin);
                if (tipo != 1 && tipo != 2)
                {
                    cout << "TIPO INVÁLIDO!\n";
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
            cout << "OPÇÃO ESCOLHIDA - REMOVER VEÍCULO DA LISTA (3)\n\n";
            cout << "PLACA DO VEÍCULO: ";
            cin >> placa;
            fflush(stdin);
            No *nAux = buscaPlacaL(L, placa);
            if (nAux == nullptr)
            {
                cout << "VEÍCULO NÃO ENCONTRADO!\n";
            }
            else
            {
                removeL(L, nAux->dado);
                cout << "VEÍCULO DE PLACA " << placa << " REMOVIDO COM SUCESSO!\n";
            }
            cout << endl;
            system("pause");
            system("cls");
        }
        else if (opcao == 4)
        {
            string fabricante = " ";
            cout << "OPÇÃO ESCOLHIDA - REMOVER VEÍCULO DA LISTA COM BASE NO FABRICANTE (4)\n\n";
            cout << "FABRICANTE: ";
            cin >> fabricante;
            fflush(stdin);
            No* nAux = buscaFabricanteL(L, fabricante);
            if (nAux == nullptr)
            {
                cout << "FABRICANTE NÃO REGISTRADO!\n";
            }
            else
            {
                if (!excluiFabricanteL(L, fabricante))
                {
                    cout << "NÃO HÁ CARROS DESSE FABRICANTE COM ANO ACIMA DE 2000!\n";
                }
                else
                {
                    cout << "VEÍCULO(S) REMOVIDO(S) COM SUCESSO!\n";
                }
            }
            cout << endl;
            system("pause");
            system("cls");

        }
        else if (opcao == 5)
        {
            string fabricante = " ";
            cout << "OPÇÃO ESCOLHIDA - FILTRAR VEÍCULOS POR FABRICANTE (5)\n\n";
            cout << "FABRICANTE: ";
            cin >> fabricante;
            fflush(stdin);
            No* nAux = buscaFabricanteL(L, fabricante);
            if (nAux == nullptr)
            {
                cout << "FABRICANTE NÃO REGISTRADO!\n";
            }
            else
            {
                cout << "\nPLACAS DO(S) VEÍCULO(S) DA " << fabricante << ":\n";
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
            cout << "OPÇÃO INVÁLIDA!\n";
            system("pause");
            system("cls");
        }
    }
    while(opcao != 6);

    cout << "PROGRAMA ENCERRADO COM SUCESSO!\n";

    delete(L);
    return EXIT_SUCCESS;
}



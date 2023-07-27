#include <iostream>
#include <ctime>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    setlocale(LC_ALL, "portuguese");

    const int tam = 9, espaco = 15, espacoNum = 25;
    const char *produto[] = {"Cachorro quente", "Bauru simples", "Bauru com ovo", "Hambúrger", "Cheeseburguer", "Torrada", "Refrigerante", "Suco Natural", "Água"};
    const float valor[tam] = {15.00, 18.50, 22.00, 26.00, 22.00, 10.00, 7.50, 10.00, 5.00};

    int id, pedido[tam] = {}, incluir, qtd;
    float total=0.00;

    cout << fixed;
    cout.precision(2);

    do {
        cout << "Informe o código do item que deseja adicionar ao pedido: ";
        cin >> id;

        cout << "Informe a quantidade do item: ";
        cin >> qtd;

        switch(id)
        {
        case 10:
            pedido[0] = pedido[0] + qtd;
            break;
        case 11:
            pedido[1] = pedido[1] + qtd;
            break;
        case 12:
            pedido[2] = pedido[2] + qtd;
            break;
        case 13:
            pedido[3] = pedido[3] + qtd;
            break;
        case 14:
            pedido[4] = pedido[4] + qtd;
            break;
        case 15:
            pedido[5] = pedido[5] + qtd;
            break;
        case 1:
            pedido[6] = pedido[6] + qtd;
            break;
        case 2:
            pedido[7] = pedido[7] + qtd;
            break;
        case 3:
            pedido[8] = pedido[8] + qtd;
            break;
        default:
            cout << "\nERRO: O código informado não corresponde a nenhum dos itens do cardápio!\n";
        }

        cout << "\n1 - Incluir mais um item\n2 - Encerrar o pedido\n";
        cin >> incluir;
        system("cls");

    } while (incluir == 1);

    for(int i=0; i<tam; i++)
    {
        total = total + (pedido[i] * valor[i]);
    }

    cout.width(42);
    cout  << left << "Descrição";
    cout.width(espacoNum);
    cout << "QTD";
    cout.width(espaco);
    cout << right << "Valor do item\n";

    for(int i=0; i<tam; i++)
    {
        if(pedido[i] != 0)
    {
        cout.width(43);
        cout << left << produto[i];
        cout.width(espacoNum);
        cout << pedido[i];
        cout.width(espaco-2);
        cout << right << valor[i] << endl;

    }
    }

    cout  << "\nTotal do pedido:";
    cout.width(espaco*4.35);
    cout.fill('.');
    cout << total;

    return EXIT_SUCCESS;
}

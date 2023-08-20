#ifndef _HPP__MENU
#define _HPP_MENU

void menu(int *escolha)
{
    cout << "############## MENU DE OPÇÕES ##############\n\n";
    cout << "1- MOSTRAR LISTA DE VEÍCULOS\n";
    cout << "2- ORDENAR LISTA DE VEÍCULOS\n";
    cout << "3- REMOVER UM VEÍCULO\n";
    cout << "4- REMOVER VEÍCULO POR FABRICANTE E ANO\n";
    cout << "5- FILTRAR VEÍCULO\n";
    cout << "6- SAIR\n";
    cout << "SUA ESCOLHA: ";
    cin >> (*escolha);
    return;
}

#endif // _HPP_MENU

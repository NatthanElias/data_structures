#ifndef _HPP__MENU
#define _HPP_MENU

void menu(int *escolha)
{
    cout << "############## MENU DE OP��ES ##############\n\n";
    cout << "1- MOSTRAR LISTA DE VE�CULOS\n";
    cout << "2- ORDENAR LISTA DE VE�CULOS\n";
    cout << "3- REMOVER UM VE�CULO\n";
    cout << "4- REMOVER VE�CULO POR FABRICANTE E ANO\n";
    cout << "5- FILTRAR VE�CULO\n";
    cout << "6- SAIR\n";
    cout << "SUA ESCOLHA: ";
    cin >> (*escolha);
    return;
}

#endif // _HPP_MENU

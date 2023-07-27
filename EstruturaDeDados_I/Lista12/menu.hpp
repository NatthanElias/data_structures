#ifndef _HPP__MENU
#define _HPP_MENU

void menu(int *escolha)
{
    cout << "############## MENU DE OP��ES ##############\n\n";
    cout << "1- MOSTRAR FUNCION�RIOS\n";
    cout << "2- ORDENAR LISTA DE FUNCION�RIOS\n";   // sistema solicita se ordem alfab�tica ou c�digo (crescente)
    cout << "3- REMOVER UM FUNCION�RIO\n";      // solicita um c�digo ao usu�rio
    cout << "4- REMOVER FUNCION�RIOS DE UMA CIDADE\n";      // solicita a cidade para o usu�rio
    cout << "5- MOSTRAR INFORMA��ES\n";     // n�mero de funcion�rios, n�mero de funcion�rios acima de 29 anos
    cout << "6- FILTRAR FUNCION�RIO\n";     // usu�rio informa o tipo sangu�neo e o sistema mostra os nomes dos funcion�rios que o possuem
    cout << "7- SAIR\n";
    cout << "SUA ESCOLHA: ";
    cin >> (*escolha);
    return;
}

#endif // _HPP_MENU

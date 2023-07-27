#ifndef _HPP__MENU
#define _HPP_MENU

void menu(int *escolha)
{
    cout << "############## MENU DE OPÇÕES ##############\n\n";
    cout << "1- MOSTRAR FUNCIONÁRIOS\n";
    cout << "2- ORDENAR LISTA DE FUNCIONÁRIOS\n";   // sistema solicita se ordem alfabética ou código (crescente)
    cout << "3- REMOVER UM FUNCIONÁRIO\n";      // solicita um código ao usuário
    cout << "4- REMOVER FUNCIONÁRIOS DE UMA CIDADE\n";      // solicita a cidade para o usuário
    cout << "5- MOSTRAR INFORMAÇÕES\n";     // número de funcionários, número de funcionários acima de 29 anos
    cout << "6- FILTRAR FUNCIONÁRIO\n";     // usuário informa o tipo sanguíneo e o sistema mostra os nomes dos funcionários que o possuem
    cout << "7- SAIR\n";
    cout << "SUA ESCOLHA: ";
    cin >> (*escolha);
    return;
}

#endif // _HPP_MENU

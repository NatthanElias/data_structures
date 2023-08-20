#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

int main()
{
    setlocale(LC_ALL, "portuguese");

    char texto[50], aux[50], aux2[50];
    int j = 0, k = 0;

    cout << "Digite um texto qualquer: ";
    gets(texto);
    fflush(stdin);

    for(int i=0; i < strlen(texto); i++)
    {
        if(!isspace(texto[i]))
        {
            aux[j] = texto[i];
            j++;
        }
    }
    j++;
    aux[j] = '\0';

    for(int i = strlen(aux); i >= 0; i--)
    {
        aux2[k] = aux[i];
        k++;
    }
    k++;
    aux2[k] = '\0';

    cout << "\nTexto sem espacos: ";
    for(int i=0; i < strlen(aux); i++)
        cout << aux[i];

    cout << "\nTexto sem espacos e invertido: ";
    for(int i=0; i <= strlen(aux); i++)
        cout << aux2[i];
    cout << endl;

    return EXIT_SUCCESS;
}

#include <iostream>
#include <cstring>
#include <ctype.h>

using namespace std;

void realiza(char **s);

int main()
{
    setlocale(LC_ALL, "portuguese");

    char *str = new char[100];

    realiza(&str);

    cin.get();
}

void realiza(char **s)
{
    cout << "Informe o texto: ";
    gets(*s);
    fflush(stdin);

    int *i = new int(0);
    int *j = new int(0);
    char *straux = new char[100];
    int tam = strlen(*s);

    for(*i = 0; *i < tam; (*i)++)
    {
        //cout << "\nTESTE\n";
        if(isalnum(**s))
        {
            (*straux) = (**s);
            //cout << (*straux);
            straux++;
            (*j)++;
        }
        (*s)++;
    }
    (*s) -= *i;
    straux -= *j;
    *i = 0;

    int tam2 = strlen(straux);

    cout << "\nTexto resultante: ";
    for(*i = 0; *i < tam2; (*i)++)
    {
        (*straux) = toupper(*straux);
        cout << (*straux);
        straux++;
    }
}

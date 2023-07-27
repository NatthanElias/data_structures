#include <iostream>

using namespace std;

void leitura(int &baseB, int &baseS, int &h);
int calcula(int baseB, int baseS, int h);
void mostra(int res);

int main()
{
    setlocale(LC_ALL, "portuguese");

    int a, b, c;

    leitura(a, b,c);
    mostra(calcula(a, b,c));

    return EXIT_SUCCESS;
}

void leitura(int &baseB, int &baseS, int &h)
{
    cout << "Informe a maior base do trap�zio: ";
    cin >> baseB;
    fflush(stdin);

    cout << "Informe a menor base do trap�zio: ";
    cin >> baseS;
    fflush(stdin);

    cout << "Informe a altura do trap�zio: ";
    cin >> h;
    fflush(stdin);
}

int calcula(int baseB, int baseS, int h)
{
    int res;

    res = ((baseB + baseS) * h) /2;

    return res;
}

void mostra(int res)
{
    cout << "\nA �rea do trap�zio �: " << res;
}

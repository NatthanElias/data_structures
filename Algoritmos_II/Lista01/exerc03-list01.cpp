#include <iostream>
#include <ctime>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    setlocale(LC_ALL, "portuguese");

    float h, p, pIdeal, res;
    char sexo;

    cout << fixed;
    cout.precision(1);

    cout << "Informe sua altura: ";
    cin >> h;

    cout << "Informe seu peso: ";
    cin >> p;

    cout << "Informe seu sexo (M – Masculino, F – Feminino): ";
    cin >> sexo;

    if(sexo == 'M' || sexo == 'm')
        pIdeal = (72.7 * h) - 58;
    else if(sexo == 'F' || sexo == 'f')
        pIdeal = (62.1 * h) - 44.7;

    res = p - pIdeal;

    if(fabs(res) <= 3.00)
        cout << "\nVocê está dentro do peso ideal!";
    else if(p < pIdeal - 3.00)
        cout << "\nVocê está abaixo do peso ideal!";
    else if(p > pIdeal + 3.00)
        cout << "\nVocê está acima do peso ideal!";

    return EXIT_SUCCESS;
}

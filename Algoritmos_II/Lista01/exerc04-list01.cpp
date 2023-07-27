#include <iostream>
#include <ctime>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    setlocale(LC_ALL, "portuguese");

    int n1, n2, encerra, cont=0, soma=0;
    float num1;
    char item;

    do {
        cout << "##MENU##\n1 – Potenciação\n2 – Raiz quadrada\n3 – Arredondar o valor seguindo o critério da primeira casa decimal\n4 – Verificar se um valor é primo\n5 – Verificar se um valor é um número perfeito\n\nIforme o número da operação que deseja realizar: ";
        cin >> item;
        system("cls");

        if(item == '1')
        {
            cout << "Informe a base (número inteiro e positivo): ";
            cin >> n1;

            cout << "Informe o expoente (número inteiro e positivo): ";
            cin >> n2;

            system("cls");

            cout << "Resultado: " << pow(n1,n2);
        }
        else if(item == '2')
        {
            cout << "Informe um valor inteiro positivo: ";
            cin >> n1;

            system("cls");

            cout << "Resultado: " << sqrt(n1);
        }
        else if(item == '3')
        {
            cout << "Informe o valor decimal que deseja arrendondar: ";
            cin >> num1;

            system("cls");

            cout << "Resultado: " << round(num1);
        }
        else if(item == '4')
        {
            cout << "Informe o número (inteiro e positivo): ";
            cin >> n1;

            system("cls");

            for(int i = 1; i <= n1; i++)
            {
                if(n1%i==0)
                {
                    cont++;
                }
            }

            if(cont == 2)
            cout << "Resultado: " << n1 << " é primo!";
            else
            cout << "Resultado: " << n1 << " não é primo!";
            cont = 0;
        }
        else if(item == '5')
        {
            cout << "Informe o número (inteiro e positivo): ";
            cin >> n1;

            system("cls");

            for(int i = 1; i < n1; i++)
            {
                if(n1%i==0)
                {
                    soma+=i;
                }
            }

            if(soma == n1)
            cout << "Resultado: " << n1 << " é perfeito!";
            else
            cout << "Resultado: " << n1 << " não é perfeito!";
            soma = 0;
        }

        cout << "\n\n1 - Realizar outra operação\n2 - Encerrar o programa\n";
        cin >> encerra;
        system("cls");

    } while (encerra == 1);

    return EXIT_SUCCESS;
}


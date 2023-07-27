#include <iostream>
#include <iomanip>

using namespace std;

void leitura(int &num);
void verificaPrimo(int num);
int somaAlg(int num);

int main()
{
    setlocale(LC_ALL, "portuguese");

    int id, n=0;
    bool teste = false;

    do
    {
        cout.width(20);
        cout << "#####MENU#####\n";
        cout << "0 – Sair\n";
        cout << "1 – Ler um valor qualquer\n";
        cout << "2 – Verifica primo\n";
        cout << "3 – Soma algarismo\n";
        cin >> id;
        fflush(stdin);
        system("cls");

        if(id == 1)
        {
            leitura(n);
            teste = true;
        }
        else if(teste == true)
        {
            if(id==2)
                verificaPrimo(n);
            else if(id==3)
            {
                if(n > 0 && n <= 999)
                {
                    cout << "O resultado da soma dos algarimos de "  << n << " é: "<< somaAlg(n) << " (Pressione uma tecla qualquer para continuar)";
                    getchar();
                    system("cls");
                }
                else
                {
                    cout << "ERRO: A opção 3 só pode ser acionado se o número for maior que zero e menor ou igual a 999.\n";
                }
            }
            else if(id == 0)
                break;
            else
            {
                cout << "ERRO: Opção inválida!\n";
                getchar();
            }
        }
        else if(id == 0)
            break;
        else
        {
            cout << "ERRO: Opção inválida!\n";
            getchar();
        }

    } while(id != 0);

    return EXIT_SUCCESS;
}

void leitura(int &num)
{
    cout << "Informe um valor inteiro qualquer: ";
    cin >> num;
    fflush(stdin);
    system("cls");
}

void verificaPrimo(int num)
{
    int cont = 0;

        for(int i = 1; i <= num; i++)
        {
            if(num%i==0)
                cont++;
        }

    if(cont == 2)
    {
        cout << "O número "<< num << " é primo!(Pressione uma tecla qualquer para continuar)";
        getchar();
    }
    else
    {
        cout << "O número "<< num << " não é primo! (Pressione uma tecla qualquer para continuar)";
        getchar();
    }
    system("cls");
}

int somaAlg(int num)
{
    int soma=0;

    while(num != 0)
    {
        soma = soma + (num%10);
        num = num/10;
    }

    return soma;
}

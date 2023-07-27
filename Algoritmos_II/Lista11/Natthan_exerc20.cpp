#include <iostream>
#include <fstream>
#include <cstring>
#include <ctime>

using namespace std;

void geraCinco();
void maior();
void menor();
void media();
void parImpar();

int main()
{
    setlocale(LC_ALL,"Portuguese");
    cout << fixed;
    cout.precision(2);
    srand(time(NULL));

    int menu;

    do
    {
        system("cls");
        cout << "####MENU####\n";
        cout << "0 – Sair\n";
        cout << "1 – Gerar 5 numeros\n";
        cout << "2 – Maior valor existente no arquivo\n";
        cout << "3 – Menor valor existente no arquivo\n";
        cout << "4 – Média aritmética dos valores no arquivo\n";
        cout << "5 – Quantidade de números pares e ímpares existentes no arquivo\n";
        cin >> menu;
        fflush(stdin);

        switch(menu)
        {
            case 0:
                system("cls");
                cout << "Programa finalizado!";
                getchar();
                break;
            case 1:
                system("cls");
                geraCinco();
                cout << "Numeros gerados!";
                getchar();
                break;
            case 2:
                system("cls");
                maior();
                getchar();
                break;
            case 3:
                system("cls");
                menor();
                getchar();
                break;
            case 4:
                system("cls");
                media();
                getchar();
                break;
            case 5:
                system("cls");
                parImpar();
                getchar();
                break;
            default:
              system("cls");
              cout << "Opcao invalida!";
              getchar();
              break;
        }

    } while(menu != 0);



}

void geraCinco()
{
    ofstream arquivo;
    arquivo.open("exerc20.txt", ios::out);

    if(arquivo.is_open())
    {
        for(int i = 0; i < 5; i++)
        {
            arquivo << rand()%19+1;
            if(i!=4)
                arquivo << "\n";
        }
    }
    else
        cout << "Erro ao abrir o arquivo";

    arquivo.close();
}

void maior()
{
    char n[5];
    int maior = 0;
    ifstream arquivo;
    arquivo.open("exerc20.txt", ios::in);

    if(arquivo.is_open())
    {
        while(!arquivo.eof())
        {
            arquivo.getline(n, 5);
            if(atoi(n) > maior)
                maior = atoi(n);
        }
    }
    else
        cout << "Erro ao abrir o arquivo";

    arquivo.close();

    cout << "Maior: " << maior;
}

void menor()
{
    char n[5];
    int menor = INT_MAX;
    ifstream arquivo;
    arquivo.open("exerc20.txt", ios::in);

    if(arquivo.is_open())
    {
        while(!arquivo.eof())
        {
            arquivo.getline(n, 5);
            //cout << n << endl;
            if(atoi(n) < menor)
                menor = atoi(n);
        }
    }
    else
        cout << "Erro ao abrir o arquivo";

    arquivo.close();

    cout << "Menor: " << menor;
}

void media()
{
    char n[5];
    float media = 0.00;
    ifstream arquivo;
    arquivo.open("exerc20.txt", ios::in);

    if(arquivo.is_open())
    {
        while(!arquivo.eof())
        {
            arquivo.getline(n, 5);
            media += atoi(n);
        }
    }
    else
        cout << "Erro ao abrir o arquivo";

    arquivo.close();

    cout << "Media: " << media/5.00;
}

void parImpar()
{
    char n[5];
    int par = 0, impar = 0;
    ifstream arquivo;
    arquivo.open("exerc20.txt", ios::in);

    if(arquivo.is_open())
    {
        while(!arquivo.eof())
        {
            arquivo.getline(n, 5);
            if(atoi(n)%2==0)
                par++;
            else
                impar++;
        }
    }
    else
        cout << "Erro ao abrir o arquivo";

    arquivo.close();

    cout << "Numeros pares: " << par << "\nNumeros impares: " << impar;
}

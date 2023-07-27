#include <iostream>
#include <cstring>

using namespace std;

struct Clientes
{
    int cpf;
    char nome[100];
    int nasc;

    void cadastra(int cpfC, string nomeC, int nascC) {
        cpfC = cpf;
        nomeC = nome;
        nascC = nasc;
    }
};

int main() {
    setlocale(LC_ALL, "Portuguese");

    int n;

    cout << "Informe a quantidade de clientes a serem cadastrados: ";
    cin >> n;
    fflush(stdin);
    system("cls");

    Clientes *px = new Clientes[n];

    for(int i = 0; i < n; i++) {
        cout << "Infome o CPF do cliente " << i+1 << ": ";
        cin >> px[i].cpf;
        fflush(stdin);

        cout << "Infome o nome do cliente " <<  i+1 << ": ";
        gets(px[i].nome);
        fflush(stdin);

        cout << "Infome a data de nascimento do cliente " <<  i+1 << ": ";
        cin >> px[i].nasc;
        fflush(stdin);
        system("cls");
    }

    for(int i = 0; i < n; i++) {
        cout << "Cliente " <<  i+1 << endl;
        cout << "CPF: " << px[i].cpf << endl;
        cout << "Nome: " << px[i].nome << endl;
        cout << "Data de nascimento " << px[i].nasc << endl;
        cout << "______________" << endl;
    }

    delete px;

    return 0;
}

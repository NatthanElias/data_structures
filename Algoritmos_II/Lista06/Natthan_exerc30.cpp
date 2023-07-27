#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct DadosAtiv
{
    float peso;
    float horas;
    float distancia;
};

struct Jogador
{
    string nome;
    string clube;
    int idade;
    DadosAtiv x;
    float caloria = 0;
};

void cadastra(vector<Jogador> &v);
void mostra(vector<Jogador> &v);
void velMedia(vector<Jogador> &v);
void distDecresc(vector<Jogador> &vet);
void meioEMenorCal(vector<Jogador> &v);

int main()
{
    setlocale(LC_ALL, "portuguese");

    cout << fixed;
    cout.precision(2);

    vector<Jogador> jogadores;
    int menu = -1;

    do
    {
        system("cls");
        cout << "#############Menu#############\n";
        cout << "0 - Sair\n";
        cout << "1 – Cadastrar atleta\n";
        cout << "2 – Mostrar atletas cadastrados\n";
        cout << "3 – Velocidade média de cada jogador\n";
        cout << "4 – Distância percorrida em ordem decrescente\n";
        cout << "5 – Maior e menor consumo de calorias\n";
        cin >> menu;
        fflush(stdin);

        switch(menu)
        {
            case 1:
                system("cls");
                cadastra(jogadores);
                cout << "Jogador cadastrado com sucesso!\nPressione Enter para prosseguir";
                getchar();
                break;
            case 2:
                system("cls");
                if(jogadores.size() <= 0)
                    cout << "Nenhum item novo foi cadastrado!";
                else
                    mostra(jogadores);
                getchar();
                break;
            case 3:
                system("cls");
                if(jogadores.size() <= 0)
                    cout << "Nenhum item novo foi cadastrado!";
                else
                    velMedia(jogadores);
                getchar();
                break;
            case 4:
                system("cls");
                if(jogadores.size() <= 0)
                    cout << "Nenhum item novo foi cadastrado!";
                else
                    distDecresc(jogadores);
                getchar();
                break;
            case 5:
                system("cls");
                if(jogadores.size() <= 0)
                    cout << "Nenhum item novo foi cadastrado!";
                else
                    meioEMenorCal(jogadores);
                getchar();
                break;
            case 0:
                break;
            default:
                system("cls");
                cout << "ERRO: Opcao invalida!";
                getchar();
        }
    } while(menu != 0);

    return 0;
}

void cadastra(vector<Jogador> &v)
{
    Jogador y;

    cout << "Informe o nome do jogador: ";
    getline(cin, y.nome);
    fflush(stdin);

    cout << "Informe o clube que o jogador atua: ";
    getline(cin, y.clube);
    fflush(stdin);

    cout << "Informe a idade do Jogador: ";
    cin >> y.idade;
    fflush(stdin);

    cout << "Informe o peso do Jogador: ";
    cin >> y.x.peso;
    fflush(stdin);

    cout << "Informe o tempo da atividade(EM HORAS): ";
    cin >> y.x.horas;
    fflush(stdin);

    cout << "Informe a distancia percorrida(EM KM): ";
    cin >> y.x.distancia;
    fflush(stdin);

    v.push_back(y);
}

void mostra(vector<Jogador> &v)
{
    cout << "JOGADORES CADASTRADOS:\n\n";

    for(int i = 0; i < v.size(); i++)
    {
        cout << "Nome: " << v[i].nome << "\n";
        cout << "Clube: " << v[i].clube << "\n";
        cout << "Idade: " << v[i].idade << "\n";
        cout << "Peso: " << v[i].x.peso << " Kg\n";
        cout << "Tempo de atividade: " << v[i].x.horas << " Horas\n";
        cout << "Distancia percorrida: " << v[i].x.distancia << " Km\n";
        cout << "--------------------------------" << "\n";
    }
}

void velMedia(vector<Jogador> &v)
{

    for(int i = 0; i < v.size(); i++)
        cout << "A velocidade média do jogador " << v[i].nome << " é " << v[i].x.distancia/v[i].x.horas << " Km/h\n";
}

void distDecresc(vector<Jogador> &vet)
{
    vector<Jogador> v = vet;
    int maior;

    for(int i = 0; i < v.size()-1; i++)
    {
        maior = i;
        for(int j = i+1; j < v.size(); j++)
        {
            if(v[j].x.distancia > v[maior].x.distancia)
                maior = j;
        }
        if(i != maior)
        {
            Jogador aux = v[i];
            v[i] = v[maior];
            v[maior] = aux;
        }
    }

    cout << "Distancia em ordem decrescente:\n\n";
    for(int i = 0; i < v.size(); i++)
        cout << "O jogador " << v[i].nome << " Percorreu " << v[i].x.distancia << " Km/h\n";
}

void meioEMenorCal(vector<Jogador> &v)
{
    int maior = 0, menor = 0;
    float cal;

    for(int i = 0; i < v.size(); i++)
    {
        cal = 0.00;
        cal = (v[i].x.distancia/v[i].x.horas) * v[i].x.peso * 0.0175;
        v[i].caloria = (v[i].x.horas * 60) * cal;
    }

    for(int i = 1; i < v.size(); i++)
    {
        if(v[i].caloria > v[maior].caloria)
            maior = i;
    }

    for(int i = 1; i < v.size(); i++)
    {
        if(v[i].caloria < v[menor].caloria)
            menor = i;
    }

    cout << "MAIOR CONSUMO:\n";
    cout << "O jogador " << v[maior].nome << " consumiu " << v[maior].caloria << " Calorias\n\n";

    cout << "MENOR CONSUMO:\n";
    cout << "O jogador " << v[menor].nome << " consumiu " << v[menor].caloria << " Calorias\n\n";
}

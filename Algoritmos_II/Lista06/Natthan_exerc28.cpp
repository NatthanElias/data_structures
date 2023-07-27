#include <iostream>
#include <vector>

using namespace std;

struct Habitante
{
    int idade;
    char sexo;
    float sal;
    int numF;

    void insere(int idadeH, char sexoH, float salH, int numFH)
    {
        idade = idadeH;
        sexo = sexoH;
        sal = salH;
        numF = numFH;
    }
};

void cadastrar(vector<Habitante> &v);
float mediaSalMasc(vector<Habitante> &v);
float mediaSalFem(vector<Habitante> &v);
void maiorIdade(vector<Habitante> &v);
void menorIdade(vector<Habitante> &v);
void salMaiorF(vector<Habitante> &v);

int main()
{
    setlocale(LC_ALL, "portuguese");

    vector<Habitante> populacao;
    int menu;

    cadastrar(populacao);
    do
    {
        cout << "#############Menu#############\n";
        cout << "1- Média de salário das pessoas do sexo Masculino\n";
        cout << "2- Média de salário das pessoas do sexo Feminino\n";
        cout << "3– Sexo e salário da pessoa com a maior idade\n";
        cout << "4– Sexo e salário da pessoa com menor idade\n";
        cout << "5– Salário da pessoa com o maior número de filhos\n";
        cout << "6– Sair\n";
        cin >> menu;
        fflush(stdin);
        system("cls");

        switch(menu)
        {
            case 1:
                cout << "Media sal: " << mediaSalMasc(populacao);
                getchar();
                system("cls");
                break;
            case 2:
                cout << "Media sal: " << mediaSalFem(populacao);
                getchar();
                system("cls");
                break;
            case 3:
                maiorIdade(populacao);
                getchar();
                system("cls");
                break;
            case 4:
                menorIdade(populacao);
                getchar();
                system("cls");
                break;
            case 5:
                salMaiorF(populacao);
                getchar();
                system("cls");
                break;
            case 6:
                break;
            default:
                cout << "ERRO: Opcao invalida!";
                getchar();
                system("cls");
        }
    } while(menu != 6);

    return 0;
}

void cadastrar(vector<Habitante> &v)
{
    Habitante x;
    int n, f, q;
    float s;
    char sex;

    do
    {
        err:

        cout << "Idade: ";
        cin >> n;
        fflush(stdin);

        cout << "Sexo(M - Masculino, F- Feminino): ";
        cin >> sex;
        fflush(stdin);

        cout << "Salário: ";
        cin >> s;
        fflush(stdin);

        cout << "Número de filhos: ";
        cin >> f;
        fflush(stdin);

        x.insere(n, sex, s, f);
        v.push_back(x);

        if(sex == 'M' || sex == 'F')
        {
            cout << "\nDeseja cadastrar outro habitate?\n1 - Sim\n0 - Não\n";
            cin >> q;
            fflush(stdin);
            system("cls");
        }
        else
        {
            cout << "\nERRO: Sexo informado invalido! Reinsira os dados de forma correta:\n";
            v.pop_back();
            getchar();
            system("cls");
            goto err;
        }

    } while(q == 1 && (v.size() <= 50));

}

float mediaSalMasc(vector<Habitante> &v)
{
    float y = 0;
    int c = 0;

    for(int i = 0; i < v.size(); i++)
    {
        if(v[i].sexo == 'M')
        {
            y += v[i].sal;
            c++;
        }
    }

    return y / c;
}

float mediaSalFem(vector<Habitante> &v)
{
    float y = 0;
    int c = 0;

    for(int i = 0; i < v.size(); i++)
    {
        if(v[i].sexo == 'F')
        {
            y += v[i].sal;
            c++;
        }
    }

    return y / c;
}

void maiorIdade(vector<Habitante> &v)
{
    int m = 0;

    for(int i = 1; i < v.size(); i++)
    {
        if(v[i].idade > v[m].idade)
            m = i;
    }

    cout << "Sexo da pessoa com maior idade: " << v[m].sexo << "\n";
    cout << "Salário da pessoa com maior idade: " << v[m].sal << "\n";
}

void menorIdade(vector<Habitante> &v)
{
    int m = 0;

    for(int i = 1; i < v.size(); i++)
    {
        if(v[i].idade < v[m].idade)
            m = i;
    }

    cout << "Sexo da pessoa com menor idade: " << v[m].sexo << "\n";
    cout << "Salário da pessoa com menor idade: " << v[m].sal << "\n";
}

void salMaiorF(vector<Habitante> &v)
{
    int m = 0;

    for(int i = 0; i < v.size(); i++)
    {
        if(v[i].numF > m)
            m = i;
    }

    cout << "Salário da pessoa com maior numero de filhos: " << v[m].sal << "\n";
}

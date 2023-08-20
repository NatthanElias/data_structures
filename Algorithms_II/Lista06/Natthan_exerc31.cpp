#include <iostream>
#include <vector>

using namespace std;

struct Aluno
{
    int matricula;
    string nome;
    int turma;
    string curso;
    float media;
    float freq;

    void insere(int mat, string n, int t, string c, float m, float f)
    {
        matricula = mat;
        nome = n;
        turma = t;
        curso = c;
        media = m;
        freq = f;
    }
};

bool validaNumMatricula(vector<Aluno> &v, int n);
void cadastra(vector<Aluno> &v, vector<int> &t);
bool validaTurma(vector<Aluno> &v, int n);
void listar(vector<Aluno> &v);
bool validaCurso(vector<Aluno> &v, string n);
void aprovados(vector<Aluno> &v);
void media(vector<Aluno> &v, vector<int> &t);

int main()
{
    setlocale(LC_ALL, "portuguese");

    cout << fixed;
    cout.precision(2);

    vector<int> turmas;
    vector<Aluno> alunos;
    int menu = -1;

    do
    {
        system("cls");
        cout << "#############Menu#############\n";
        cout << "0 - Sair\n";
        cout << "1 – Cadastrar aluno\n";
        cout << "2 – Listar aluno por turma\n";
        cout << "3 – Listar aprovados por curso\n";
        cout << "4 – Média por turma\n";
        cin >> menu;
        fflush(stdin);

        switch(menu)
        {
            case 1:
                system("cls");
                cadastra(alunos, turmas);
                break;
            case 2:
                system("cls");
                if(alunos.size() <= 0)
                    cout << "ERRO: Nenhum Aluno foi cadastrado ainda!";
                else
                listar(alunos);
                getchar();
                break;
            case 3:
                system("cls");
                if(alunos.size() <= 0)
                    cout << "ERRO: Nenhum Aluno foi cadastrado ainda!";
                else
                    aprovados(alunos);
                getchar();
                break;
            case 4:
                system("cls");
                if(alunos.size() <= 0)
                    cout << "ERRO: Nenhum Aluno foi cadastrado ainda!";
                else
                    media(alunos, turmas);
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

bool validaNumMatricula(vector<Aluno> &v, int n)
{
    for(int i = 0; i < v.size(); i++)
    {
        if(n == v[i].matricula)
            return true;
    }
    return false;
}

bool existeTurma(vector<int> &v, int n)
{
    for(int i = 0; i < v.size(); i++)
    {
        if(n == v[i])
            return true;
    }
    return false;
}

void cadastra(vector<Aluno> &v, vector<int> &t)
{
    Aluno y;

    if(v.size() < 51)
    {
        cout << "Informe o nome do aluno: ";
        getline(cin, y.nome);
        fflush(stdin);

        cout << "Informe o numero de matricula: ";
        cin >> y.matricula;
        fflush(stdin);

        cout << "Informe o numero da turma: ";
        cin >> y.turma;
        fflush(stdin);

        cout << "Informe o nome do curso(SEM ACENTOS, COM C INVES DE Ç): ";
        getline(cin, y.curso);
        fflush(stdin);

        cout << "Informe a media do aluno: ";
        cin >> y.media;
        fflush(stdin);

        cout << "Informe a frequencia(EM PORCENTAGEM) do aluno: ";
        cin >> y.freq;
        fflush(stdin);

        if(!validaNumMatricula(v, y.matricula))
        {
            v.push_back(y);

            if(!existeTurma(t, y.turma))
                t.push_back(y.turma);

            cout << "\nAluno cadastrado com sucesso!\nPressione Enter para prosseguir";
            getchar();
        }
        else
        {
            system("cls");
            cout << "ERRO: Numero de matricula ja cadastrado!\nPressione Enter e informe novamente os dados";
            getchar();
        }
    }
    else
    {
        system("cls");
        cout << "\nERRO: Numero maximo de alunos excedido!\n";
        getchar();
    }
}

bool validaTurma(vector<Aluno> &v, int n)
{
    for(int i = 0; i < v.size(); i++)
    {
        if(n == v[i].turma)
            return true;
    }
    return false;
}

void listar(vector<Aluno> &v)
{
    int n;

    cout << "Informe o numero da turma que deseja exibir:";
    cin >> n;
    fflush(stdin);

    if(validaTurma(v, n))
    {
         for(int i = 0; i < v.size(); i++)
         {
            if(v[i].turma == n)
            {
                cout << "Matricula: " << v[i].matricula << "\n";
                cout << "Nome: " << v[i].nome << "\n";
                cout << "Turma: " << v[i].turma << "\n";
                cout << "Curso: " << v[i].curso << "\n";
                cout << "Média: " << v[i].media << "\n";
                cout << "Frequência: " << v[i].freq << "%\n";
                cout << "--------------------------------" << "\n";
            }
         }
    }
     else
    {
        system("cls");
        cout << "ERRO: Nao ha alunos na turma informada!";
    }
}

bool validaCurso(vector<Aluno> &v, string n)
{
    for(int i = 0; i < v.size(); i++)
    {
        if(n == v[i].curso)
            return true;
    }
    return false;
}

void aprovados(vector<Aluno> &v)
{
    string s;

    cout << "Informe o nome do curso: ";
    getline(cin, s);
    fflush(stdin);
    system("cls");

    cout << "APROVADOS:\n\n";

    for(int i = 0; i < v.size(); i++)
    {
        if((v[i].curso == s) && (v[i].media >= 6.00) && (v[i].freq >= 75.00))
            cout << v[i].nome << "(Media: " << v[i].media << ", Freq: " << v[i].freq << "%)\n";
    }
}

void media(vector<Aluno> &v, vector<int> &t)
{
    float maior, menor;
    float s , cont;

    for(int i = 0; i < t.size(); i++)
    {
        cont = 0.0;
        s = 0.0;
        menor = 0.0;
        maior = 0.0;

        for(int j = 0; j < v.size(); j++)
        {
            if(t[i] == v[j].turma)
            {
                s += v[j].media;

                cont++;

                if(v[j].media > v[maior].media)
                    maior = j;

                if(v[j].media < v[menor].media)
                    menor = j;
            }
        }

        cout << "Turma: " << t[i] << "\n";

        if(menor != 0)
        {
            if(cont == 1)
            {
                cout << "Maior media: " << v[maior].media << "(Aluno: " << v[maior].nome << ")\n";
                cout << "Menor media: " << v[maior].media << "(Aluno: " << v[maior].nome << ")\n";
            }
            else
            {
                cout << "Maior media: " << v[maior].media << "(Aluno: " << v[maior].nome << ")\n";
                cout << "Menor media: " << v[menor].media << "(Aluno: " << v[menor].nome << ")\n";
            }
        }
        else
        {
            menor = maior;
            for(int j = 0; j < v.size(); j++)
            {
                if(t[i] == v[j].turma)
                {
                    if(v[j].media < v[menor].media)
                        menor = j;
                }
            }
            cout << "Maior media: " << v[maior].media << "(Aluno: " << v[maior].nome << ")\n";
            cout << "Menor media: " << v[menor].media << "(Aluno: " << v[menor].nome << ")\n";
        }

        cout << "Media da turma: " << s / cont << "%\n";
        cout << "--------------------------------" << "\n";
    }
}

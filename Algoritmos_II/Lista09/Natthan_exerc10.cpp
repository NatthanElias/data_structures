#include <iostream>
#include <vector>

using namespace std;

struct Aluno
{
    int matricula;
    float n1;
    float n2;
    float n3;

    float p1 = 3.0;
    float p2 = 4.0;
    float p3 = 3.0;
};

void cadastra(vector<Aluno> **pA, int **n);
void mostra(vector<Aluno> **pA);
void mediaMM(vector<Aluno> **pA, float **media);
void acimaMedia(vector<Aluno> **pA, float **media);
void consulta(vector<Aluno> **pA);

int main()
{
    setlocale(LC_ALL, "portuguese");
    cout << fixed;
    cout.precision(2);

    vector<Aluno> *alunos = new vector<Aluno>;
    int *n = new int;
    int *menu = new int;
    float *media = new float[*n];

    do
    {
        system("cls");
        cout << "####MENU####\n";
        cout << "0 – Sair\n";
        cout << "1 – Cadastrar aluno\n";
        cout << "2 – Mostrar alunos cadastrados\n";
        cout << "3 – Mostrar a maior e a menor média ponderada, juntamente com a matrícula do aluno\n";
        cout << "4 – Mostrar quantos alunos possuem média ponderada igual ou superior a 6 e inferior a 6\n";
        cout << "5 – Consultar aluno pela matrícula\n";
        cin >> *menu;
        fflush(stdin);

        switch(*menu)
        {
            case 0:
                system("cls");
                cout << "Programa finalizado!\n";
                break;
            case 1:
                system("cls");
                cadastra(&alunos, &n);
                getchar();
                break;
            case 2:
                system("cls");
                mostra(&alunos);
                getchar();
                break;
            case 3:
                system("cls");
                mediaMM(&alunos, &media);
                getchar();
                break;
            case 4:
                system("cls");
                acimaMedia(&alunos, &media);
                getchar();
                break;
            case 5:
                system("cls");
                consulta(&alunos);
                getchar();
                break;
            default:
                system("cls");
                cout << "Opção inválida!";
                getchar();
                break;
        }

    } while((*menu) != 0);

    return 0;
}

void cadastra(vector<Aluno> **pA, int **n)
{
    Aluno *y = new Aluno;

    cout << "Informe quantos alunos quer cadastrar: ";
    cin >> **n;

    while(**n > 0)
    {
        err:

        cout << "Informe o numero de matricula: ";
        cin >> (*y).matricula;
        fflush(stdin);

        cout << "Informe a nota 1(0-10): ";
        cin >> (*y).n1;
        fflush(stdin);

        cout << "Informe a nota 2(0-10): ";
        cin >> (*y).n2;
        fflush(stdin);

        cout << "Informe a nota 3(0-10): ";
        cin >> (*y).n3;
        fflush(stdin);

        if(((*y).n1 > 0.0 && (*y).n1 < 10.0) && ((*y).n2 > 0.0 && (*y).n2 < 10.0) && ((*y).n3 > 0.0 && (*y).n3 < 10.0))
            (*pA)->push_back(*y);
        else
        {
            system("cls");
            cout << "ERRO: Apenas notas entre 0 e 10!\nPressione Enter e informe novamente os dados";
            getchar();
            goto err;
        }
        (**n)--;
    }
}

void mostra(vector<Aluno> **pA)
{
    int *i = new int(0);

    for(*i; *i < (**pA).size(); (*i)++)
    {
        cout << "Matricula: " << (**pA).at(*i).matricula << "\n";
        cout << "Nota 1: " << (**pA).at(*i).n1 << "\n";
        cout << "Nota 2: " << (**pA).at(*i).n2 << "\n";
        cout << "Nota 3: " << (**pA).at(*i).n3 << "\n";
        cout << "--------------------------------" << "\n";
    }
}

void mediaMM(vector<Aluno> **pA, float **media)
{
    int *i = new int(0);
    int *j = new int(0);
    float *maior = new float(0);
    float *menor = new float(INT_MAX);
    int *posMaior = new int;
    int *posMenor = new int;

    for(*i; *i < (**pA).size(); (*i)++)
    {
        **media = (((**pA).at(*i).n1 * (**pA).at(*i).p1) + ((**pA).at(*i).n2 * (**pA).at(*i).p2) + ((**pA).at(*i).n3 * (**pA).at(*i).p3)) / 10.0;
        (*media)++;
    }
    *media -= *i;
    *i =0;

    for(*i; *i < (**pA).size(); (*i)++)
    {
        if(**media > *maior)
        {
            *maior = **media;
            *posMaior = *i;
        }
        else if(**media < *menor)
        {
            *menor = **media;
            *posMenor = *i;
        }

        (*media)++;
    }
    *media -= *i;

    cout << "Maior media: " << *maior << " | Matricula: " << (**pA).at(*posMaior).matricula;
    cout << "\nMenor media: " << *menor << " | Matricula: " << (**pA).at(*posMenor).matricula;
}

void acimaMedia(vector<Aluno> **pA, float **media)
{
    int *i = new int(0);
    int *contAprov = new int(0);
    int *contReprov = new int(0);

    for(*i; *i < (**pA).size(); (*i)++)
    {
        if(**media >= 6.0)
            (*contAprov)++;
        else
            (*contReprov)++;

        (*media)++;
    }

    cout << "Alunos aprovados: " << *contAprov;
    cout << "\nAlunos reprovados: " << *contReprov;
}

void consulta(vector<Aluno> **pA)
{
    int *i = new int(0);
    int *m = new int;

    cout << "Informe a matricula que deseja consultar: ";
    cin >> *m;
    fflush(stdin);

    for(*i; *i < (**pA).size(); (*i)++)
    {
        if((*m) == ((**pA).at(*i).matricula))
        {
            cout << "Matricula: " << (**pA).at(*i).matricula << "\n";
            cout << "Nota 1: " << (**pA).at(*i).n1 << "\n";
            cout << "Nota 2: " << (**pA).at(*i).n2 << "\n";
            cout << "Nota 3: " << (**pA).at(*i).n3 << "\n";
        }
    }
}

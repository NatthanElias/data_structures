#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

void geraAleatorios(int vet[], int tam, int limite);
bool existe(int valores[], int tam, int valor);
void mostra(int vet[], int tam);
void mostraCrescDesc(int vet[], int tam);
void perc(int vet[], int tam);
void posImp(int vet[], int tam);

int main()
{
    setlocale(LC_ALL, "portuguese");

    const int tam = 10;
    int vet[tam];

    geraAleatorios(vet, tam, 36);
    mostra(vet, tam);
    mostraCrescDesc(vet, tam);
    perc(vet, tam);
    posImp(vet, tam);

    return EXIT_SUCCESS;
}

bool existe(int valores[], int tam, int valor)
{
    for (int i = 0; i <tam; i++)
    {
        if(valores[i] == valor)
            return true;
    }
    return false;
}

void geraAleatorios(int vet[], int tam, int limite)
{
    srand(time(NULL));

    int v;
    for(int i = 0; i<tam; i++)
    {
        v = rand()%limite +15;
        while(existe(vet,i,v))
        {
            v = rand()%limite + 15;
        }
        vet[i] = v;
    }
}

void mostra(int vet[], int tam)
{
    cout << "Vetor: ";
    for(int i = 0; i < tam; i++)
        cout << vet[i] << ", ";
}

void mostraCrescDesc(int vet[], int tam)
{
    int aux;

    for(int i = 0; i < tam; i++)
    {
        for(int j = 0; j < tam-1; j++)
        {
            if(vet[i] < vet[j])
            {
                aux = vet[i];
                vet[i] =  vet[j];
                vet[j] = aux;
            }
        }
    }

    cout << "\n\nVetor crescente: ";
    for(int i = 0; i < tam; i++)
        cout << vet[i] << ", ";

    for(int i = 0; i < tam; i++)
    {
        for(int j = 0; j < tam-1; j++)
        {
            if(vet[i] > vet[j])
            {
                aux = vet[i];
                vet[i] =  vet[j];
                vet[j] = aux;
            }
        }
    }

    cout << "\n\nVetor decrescente: ";
    for(int i = 0; i < tam; i++)
        cout << vet[i] << ", ";
}

void perc(int vet[], int tam)
{
    int pares = 0, impares = 0;

    for(int i = 0; i < tam; i++)
    {
        if(vet[i]%2==0)
            pares++;
        else
            impares++;
    }

    int resP = (pares*100)/tam ;
    int resI = (impares*100)/tam;

    cout << "\n\nPercentual pares: " << resP << "%" << "\n\nPercentual impares: " << resI << "%";
}

void posImp(int vet[], int tam)
{
    int cont = 0, aux[tam/2];

    cout << "\n\nElementos nos índices ímpares: ";
    for(int i = 1; i < tam; i+=2)
    {
             aux[cont] = vet[i];
             cont++;
    }

    for(int v : aux)
        cout << v << ", ";
    cout << "\n";
}

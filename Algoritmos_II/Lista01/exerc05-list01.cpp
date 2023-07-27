#include <iostream>
#include <ctime>
#include <iomanip>
#include <cmath>
using namespace std;

bool existe(int valores[], int tam, int valor)
{
    for (int i = 0; i <tam; i++)
    {
        if(valores[i] == valor)
            return true;
    }
    return false;
}

void geraAleatorios(int vet[], int quantvet, int limite)
{
    srand(time(NULL));

    int v;
    for(int i = 0; i<quantvet; i++)
    {
        v = rand()%limite +15;
        while(existe(vet,i,v))
        {
            v = rand()%limite + 15;
        }
        vet[i] = v;
    }
}

main()
{
    setlocale(LC_ALL, "portuguese");

    int vet[10], aux, contImpar=0, contPar=0, percentPar, percentImpar, soma;
    float media;

    geraAleatorios(vet,10,35);
    cout << "Vetor:";
    for (int i = 0; i < 10; i++)
    {
        cout << vet[i] << ", ";
    }

    for(int i = 0; i < 10; i++)
    {
        for (int j = 0; j< 10; j++)
        {
            if (vet[i] > vet [j])
            {
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
            }
        }
    }
    cout << endl << endl;
    cout << "Vetor em ordem decrescente: ";
    for (int i = 0; i < 10; i++)
    {
        cout << vet[i] << ", ";
    }

    for (int i = 0; i<10; i++){
        soma += vet[i];
        if (vet[i]%2 == 0)
            contPar++;
        else
            contImpar++;
    }

    percentImpar = (contImpar*100.0)/10;
    percentPar = (contPar*100.0)/10;

    media = soma/10.0;

    cout << "\n\nPorcentagem de números Ímpares: " << percentImpar << "%";
    cout << "\n\nPorcentagem de números Pares: " << percentPar << "%";
    cout << "\n\nA soma total é: " << soma;
    cout << "\n\nA média é: " << media;
}

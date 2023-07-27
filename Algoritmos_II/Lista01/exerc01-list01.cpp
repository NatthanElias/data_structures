#include <iostream>
#include <ctime>
#include <iomanip>
#include <cmath>
using namespace std;

#define TAM 10

int main()
{
    setlocale(LC_ALL, "portuguese");
    srand(time(NULL));

    cout << fixed;
    cout.precision(2);

    float V[TAM], aux =0;

    for(int i=0; i<TAM; i++)
        V[i] = (rand()%50)*1.145;

    cout << "Vetor A: ";
    for(int i=0; i<TAM; i++)
        cout << V[i] << ", ";

    for(int i=0; i<(TAM-1); i++)
    {
        for(int j=i; j<TAM; j++)
        {
            if(V[i] > V[j])
            {
                aux = V[i];
                V[i] = V[j];
                V[j] = aux;
            }
        }
    }

    cout << "\n\nVetor A ordenado: ";
    for(int i=0; i<TAM; i++)
        cout << V[i] << ", ";

    cout.precision(0);

    cout << "\n\nVetor A arrendondado para cima: ";
    for(int i=0; i<TAM; i++)
        cout << ceil(V[i]) << ", ";

    cout << "\n\nVetor A arrendodado para baixo: ";
    for(int i=0; i<TAM; i++)
        cout << floor(V[i]) << ", ";

    cout << "\n\nVetor A arrendondado conforme critério da segunda casa decimal: ";
    for(int i=0; i<TAM; i++)
        cout << round(V[i]) << ", ";
    cout << endl;

    return 0;
}

#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    int *vet = new int[10];

    for(int i = 0; i < 10; i++)
    {
        *(vet + i) = rand()%31+20;
    }

    for(int i = 0; i < 10; i++)
    {
        cout << *vet << ", ";
        vet++;
    }

    delete[] vet;

    return 0;
}

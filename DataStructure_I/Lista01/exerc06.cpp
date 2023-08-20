#include <iostream>
#include <ctime>

using namespace std;

float* soma(float **m1, float **m2, int m, int n);

int main() {
    srand(time(NULL));

    int m, n;

    cout << "Informe a quantidade de linhas: ";
    cin >> m;
    fflush(stdin);

    cout << "Informe a quantidade de colunas: ";
    cin >> n;
    fflush(stdin);

    float *mat1 = new float[m*n];
    float *mat2 = new float[m*n];

    for(int i = 0; i < (m*n); i++) {
        mat1[i] = rand()/100.00;
        mat2[i] = rand()/100.00;
    }

    cout << "Matriz 1: \n";
    for(int i = 0; i < (m*n); i++) {
        if(i%n==0&&i!=0)
            cout << "\n";

        cout << mat1[i] << "\t";
    }

    cout << "\n\nMatriz 2: \n";
    for(int i = 0; i < (m*n); i++) {
        if(i%n==0&&i!=0)
            cout << "\n";

        cout << mat2[i] << "\t";
    }

    float *res = new float[m*n];
    res = soma(&mat1,&mat2, m,n);

    cout << "\n\nMatriz soma: \n";
    for(int i = 0; i < (m*n); i++) {
        if(i%n==0&&i!=0)
            cout << "\n";

        cout << res[i] << "\t";
    }

    delete mat1;
    delete mat2;
    delete res;

    return 0;
}

float* soma(float **m1, float **m2, int m, int n) {

    float *sum = new float[m*n];

    for(int i = 0; i < (m*n); i++) {
        *(sum+i) = *(*m1+i) + *(*m2+i);
    }

    return sum;
}

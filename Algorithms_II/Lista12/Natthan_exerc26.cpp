#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<string>
#include<bits/stdc++.h>

using namespace std;

struct produto {
    string nome;
    int codigo;
    int qtd;
    float valor;
};

string outSpace(string nome);
string informarNome();
float informarNum(string tipo, string tipoMaiusc, int permiteNulo);
void verificaCodigo(int cont, produto P[50]);
void cadastrar(int *cont, produto P[50]);
void gravarD(int cont, produto P[50]);
void mostrarProduto(produto P);
void lerD(int cont, produto P[50]);
void lerDcomZeroE(int cont, produto P[50]);
void consultar(int cont, produto P[50]);
void vender(int cont, produto P[50]);

main() {
    setlocale(LC_ALL, "Portuguese");
    produto P[50];
    int menu = -1, cont = 0;
    do
    {
        system("cls");
        cout << "##############MENU DE OPÇÕES#############" << endl;
        cout << "# 0 - Sair                              #" << endl;
        cout << "# 1 - Incluir um novo produto           #" << endl;
        cout << "# 2 - Vender produto                    #" << endl;
        cout << "# 3 - Listar produto com estoque zerado #" << endl;
        cout << "# 4 - Listar todos os produtos          #" << endl;
        cout << "# 5 - Consultar produto                 #" << endl;
        cout << "#########################################" << endl;
        cout << "Sua escolha: ";
        cin >> menu;
        fflush(stdin);
        system("cls");
        switch(menu)
        {
            case 0:
                cout << "Programa finalizado.";
            break;

            case 1:
                cadastrar(&cont, P);
                gravarD(cont, P);
            break;

            case 2:
                if(cont == 0)
                    cout << "Cadastre um produto para realizar está opção!";
                else {
                    vender(cont, P);
                    getchar();
                }
            break;

            case 3:
                if(cont == 0)
                    cout << "Cadastre um produto para realizar está opção!";
                 else
                    lerDcomZeroE(cont, P);
            break;

            case 4:
                if(cont == 0)
                    cout << "Cadastre um produto para realizar está opção!";
                else
                    lerD(cont, P);
            break;

             case 5:
                if(cont == 0)
                    cout << "Cadastre um produto para realizar está opção!";
                else {
                    consultar(cont, P);
                    getchar();
                }
            break;

            default :
                cout << "Opção inválida.";
                break;
        };
        getchar();
    }
    while(menu != 0);

}

string outSpace(string nome) {
	string N = "";
	char arr[nome.length() + 1];

	int spc = -1;
	strcpy(arr, nome.c_str());
	for(int i = 0; i < nome.length(); i++) {
		if(arr[i] == ' ') {
            if(spc == 0)
                spc = 1;
		}
		else {
		    if(spc != 0) {
                if(spc == 1)
                    N += ' ';
                    spc = 0;
		    }
            N += arr[i];
		}
	} return N;
}

string informarNome() {
    string nome = "";
    do {
        cout << "> Informe o nome do produto: ";
        getline(cin, nome);
        nome = outSpace(nome);
        if(nome == "")
            cout << "Insira um nome!\n";
        else
            break;
    } while(true);
    return nome;
}

float informarNum(string tipo, string tipoMaiusc, int permiteNulo) {
    float num;
    do {
        cout << "> Informe " << tipo << ": ";
        cin >> num;
        if(num < 0)
            cout << tipoMaiusc << " não pode ser um valor negativo!\n";

        else if(num == 0 && !permiteNulo)
            cout << tipoMaiusc << " não pode ser um valor nulo!\n";

        else
            break;
    } while(true);
    return num;
}

void verificaCodigo(int cont, produto P[50]) {
    do {
        int codigo = (int)(informarNum("código", "Código", 1));
        int codigoUnico = 1;
        for(int i = 0; i < cont; i++) {
            if(P[i].codigo == codigo) {
                codigoUnico = 0;
                cout << "Esse código já foi inserido!\n";
                break;
            }
        }
        if(codigoUnico) {
            cout << "Código adicionado! -> " << codigo << "\n\n";
            P[cont].codigo = codigo;
            break;
        }
    } while(true);
}


void cadastrar(int *cont, produto P[50]) {
    // Informando o nome
    string nome = informarNome();
    P[*cont].nome = nome;
    cout << "Nome adicionado! -> " << nome << "\n\n";
    // Informando o codigo
    verificaCodigo(*cont, P);
    // Informando a quantidade
    int qtd = (int)(informarNum("quantidade", "Quantidade", 1));
    P[*cont].qtd = qtd;
    cout << "Quantidade adicionada! -> " << qtd << "\n\n";
    // Informando o valor
    float valor = informarNum("valor", "Valor", 1);
    P[*cont].valor = valor;
    cout << "Valor adicionado! -> " << valor << "\n\n";
    *cont += 1;
    getchar();
}

void gravarD(int cont, produto P[50]) {
    ofstream write;
    write.open("produtos.txt");
    for(int i = 0; i < cont; i++) {
        write << P[i].nome << "# Código: " << P[i].codigo << "# Valor: " << P[i].valor << "# Quantidade: " << P[i].qtd << " ; ";
    } write.close();
}

void mostrarProduto(produto P) {
    cout << "> " << P.nome << "\nCódigo: " << P.codigo << "\nValor: R$ " << P.valor << "\nQuantidade: " << P.qtd << "\n\n";
}

void lerD(int cont, produto P[50]) {
    cout << "> Produtos cadastrados: <\n";
    for(int i = 0; i < cont; i++) {
        mostrarProduto(P[i]);
    }
}

void lerDcomZeroE(int cont, produto P[50]) {
    int existe = 0;
    for(int i = 0; i < cont; i++) {
        if(P[i].qtd == 0) {
            if(!existe) {
                existe = 1;
                cout << "> Produtos com estoque zerado: <\n";
            } mostrarProduto(P[i]);
        }
    } if(!existe) {
        cout << "Não há produtos com estoque zerado!";
    }
}

void consultar(int cont, produto P[50]) {
    int codigo = (int)(informarNum("código", "Código", 1));
    int found = 0;
    for(int i = 0; i < cont; i++) {
        if(P[i].codigo == codigo) {
            mostrarProduto(P[i]);
            found = 1;
            break;
        }
    }
    if(!found) {
        cout << "Código informado inexistente!";
    }
}

void vender(int cont, produto P[50]) {
    int codigo = (int)(informarNum("código", "Código", 1));
    int found = 0;
    for(int i = 0; i < cont; i++) {
        if(P[i].codigo == codigo) {
            do {
                int qtd = (int)(informarNum("quantidade", "Quantidade", 1));
                if(qtd > P[i].qtd) {
                    cout << "Quantidade informada excede o estoque!\n";
                }
                else {
                    P[i].qtd -= qtd;
                    gravarD(cont, P);
                    float ganho = qtd*P[i].valor;
                    cout << "\n>Lucro de R$" << ganho << ".\n> Agora há " << P[i].qtd << " quantidades no estoque.";
                    break;
                }
            } while(true);
            found = 1;
            break;
        }
    }
    if(!found) {
        cout << "Código informado inexistente!";
    }
}


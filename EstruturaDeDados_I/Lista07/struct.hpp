#ifndef _HPP_STRUCT_
#define _HPP_STRUCT_

#include <string>
using namespace std;

struct OrdemPJ
{
	string CNPJ;
	string placa;
};


struct OrdemPF
{
	string CPF;
	string placa;
	bool revisao;
};

struct FichaPF
{
    OrdemPF ordem;
	float valor;
	int nPecas;
};

struct FichaPJ
{
    OrdemPJ ordem;
	float valor;
	int nPecas;
};

#endif // _HPP_FICHAS_






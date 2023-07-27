#include <iostream>
using namespace std;
#include "lista_dupla_pet.hpp"

void inserePetLista(Lista **lista, int *cont);
bool removePeloCodigo(Lista *lista, int cod);
void imprimeTresUltimos(Lista *lista);
void separaPeloPeso(Lista *L1);

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    Lista* atendimento = new Lista();
    int cont = 1, cod, menu;

    do {
        system("cls");
        cout << "#######MENU#######\n";
        cout << "0 - Sair\n";
        cout << "1 - Inserir animal na lista de atendimento\n";
        cout << "2 - Remover um elemento da lista com base no código do animal\n";
        cout << "3 - Mostrar\n";
        cout << "4 - Mostrar 3 últimos\n";
        cout << "5 - Separar a lista em duas novas listas, com base no peso do animal\n";
        cin >> menu;
        fflush(stdin);

        switch(menu) {
        case 0:
            break;
        case 1:
            system("cls");
            inserePetLista(&atendimento, &cont);
            break;
        case 2:
            system("cls");
            cout << "Infome o codigo do animal que deseja remover: ";
            cin >> cod;
            fflush(stdin);
            system("cls");
            if(!removePeloCodigo(atendimento, cod))
                cout << "Erro na remoção";
            else
                cout << "Elemento removido da lista";
            getchar();
            break;
        case 3:
            system("cls");
            mostraL(atendimento);
            getchar();
            break;
        case 4:
            system("cls");
            imprimeTresUltimos(atendimento);
            getchar();
            break;
        case 5:
            system("cls");
            separaPeloPeso(atendimento);
            getchar();
            break;
        default:
            cout << "Opcao invalida!";
            getchar();
        }

    } while(menu != 0);

    delete(atendimento);

    return 0;
}

void inserePetLista(Lista **lista, int *cont) {
    Pet x;

    x.codigo = (*cont)++;

    cout << "Informe a idade do animal: ";
    cin >> x.idade;
    fflush(stdin);

    cout << "Informe o peso do animal: ";
    cin >> x.peso;
    fflush(stdin);

    insereFinalL(*lista, x);
}

bool removePeloCodigo(Lista *lista, int cod) {

    No *aux = lista->inicio;

    if(vaziaL(lista))
        return false;

    while(aux != NULL) {

        if(aux->dado.codigo == cod) {
            removerNoL(lista, aux);
            return true;
        }

        aux = aux->prox;
    }

    return false;
}

void imprimeTresUltimos(Lista *lista) {
    No* aux = lista->fim->ant->ant;
    cout << aux;

    aux = lista->fim->ant;
    cout << endl << aux;

    aux = lista->fim;
    cout << endl << aux;
}

void separaPeloPeso(Lista *L1) {
    Lista *L2 = new Lista();
    Lista *L3 = new Lista();

    No *aux = L1->inicio;

    while(aux != NULL) {

        if(aux->dado.peso <= 50)
            insereFinalL(L2, aux->dado);
        else
            insereFinalL(L3, aux->dado);

        aux = aux->prox;
    }

    cout << "L2: ";
    mostraL(L2);

    cout << "L3: ";
    mostraL(L3);
}

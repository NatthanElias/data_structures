#include <iostream>

using namespace std;

struct Ficha {
    string nome;
    int idade;
    char tipo;
    char quadro;

    Ficha() {
        nome = "";
        idade = 0;
        tipo = ' ';
        quadro = ' ';
    }
};

#include "fila-dinamica.hpp"
#include "pilha-dinamica.hpp"

void criaFicha(Fila *p, Fila *np);
void atendeFicha(Fila *p, Fila *np, int *cont, Pilha *s, Pilha *d);
void listaInfo(Fila *p, Fila *np, int *contTotal, int *contGrave, int *contDomest);
void mostraPilha(Pilha s, Pilha d);
void removePilha(Pilha *s, Pilha *d);
void mostraGraveNovo(Pilha s, Pilha d);

int main(void) {

    setlocale(LC_ALL, "Portuguese");

    Fila prio, noPrio;
    Pilha animalS, animalD;
    int menu;
    int cont = 0, contTotal = 0, contGrave = 0, contDomest = 0;

    do {
        system("cls");
        cout << "#######MENU#######\n";
        cout << "0 - Sair\n";
        cout << "1 - Criar ficha de atendimento e adicionar na fila\n";
        cout << "2 - Atender ficha da fila \n";
        cout << "3 - Mostrar os dados das fichas de atendimento das filas \n";
        cout << "4 - Listar as informações sobre as filas\n";
        cout << "5 - Listar as fichas já atendidas\n";
        cout << "6 - Remover uma ficha da pilha\n";
        cout << "7 - Mostrar o nome do animal armazenado nas pilhas\n";
        cin >> menu;
        fflush(stdin);

        switch(menu) {
        case 1:
            system("cls");
            criaFicha(&prio, &noPrio);
            break;
        case 2:
            system("cls");
            atendeFicha(&prio, &noPrio, &cont, &animalS, &animalD);
            break;
        case 3:
            system("cls");
            cout << "Fila prioritária:\n ";
            mostraF(&prio);
            cout << "\nFila não prioritária:\n ";
            mostraF(&noPrio);
            getchar();
            break;
        case 4:
            system("cls");
            listaInfo(&prio, &noPrio, &contTotal,&contGrave,&contDomest);
            getchar();
            break;
        case 5:
            system("cls");
            mostraPilha(animalS, animalD);
            getchar();
            break;
        case 6:
            system("cls");
            removePilha(&animalS, &animalD);
            cout << "Animal removido da pilha com sucesso!";
            getchar();
            break;
        case 7:
            system("cls");
            mostraGraveNovo(animalS, animalD);
            getchar();
            break;
        default:
            cout << "Opcao invalida!";
        }

    } while(menu != 0);


    destroiF(&prio);
    destroiF(&noPrio);

    destroiP(&animalS);
    destroiP(&animalD);

    return 0;
}

void criaFicha(Fila *p, Fila *np) {
    Ficha x;

    cout << "Informe o nome do animal: ";
    getline(cin, x.nome);
    fflush(stdin);

    cout << "Informe a idade do animal: ";
    cin >> x.idade;
    fflush(stdin);

    cout << "Informe o tipo do animal (S-selvagem, D-doméstico): ";
    cin >> x.tipo;
    fflush(stdin);

    cout << "Informe o quadro clínico do animal(E-estável, G-grave): ";
    cin >> x.quadro;
    fflush(stdin);

    if(x.quadro == 'G') {
        enfileiraF(p, x);
        system("cls");
        cout << "Animal adicionado na fila prioritária!";
        //cp++;
        getchar();
    } else if(x.quadro == 'E') {
        enfileiraF(np, x);
        system("cls");
        cout << "Animal adicionado na fila não prioritária!";
        //cnp++;
        getchar();
    } else {
        system("cls");
        cout << "ERRO: O quadro informado está incorreto!";
        getchar();
    }
}

void atendeFicha(Fila *p, Fila *np, int *cont, Pilha *s, Pilha *d) {
    if(!vaziaF(p) && *cont < 3) {
            Ficha x = desenfileiraF(p);

            if(x.tipo == 'S')
                empilhaP(s,x);
            else if(x.tipo == 'D')
                empilhaP(d,x);

            cout << "Ficha com o animal de nome " << x.nome << " prioritária atendida";
            getchar();
            cont++;

    }
    else if(*cont > 3 || !vaziaF(np)){
            Ficha x = desenfileiraF(np);

            if(x.tipo == 'S')
                empilhaP(s,x);
            else if(x.tipo == 'D')
                empilhaP(d,x);

            cout << "Ficha com o animal de nome " << x.nome << " não prioritária prioritária atendida";
            getchar();
            cont = 0;

    }

}

void listaInfo(Fila *p, Fila *np, int *contTotal, int *contGrave, int *contDomest) {

    *contTotal = 0;
    *contGrave = 0;
    *contDomest = 0;

    NoFila *n = p->inicio;

    while(n) {
        (*contTotal)++;

        if(n->dado.quadro == 'G')
            (*contGrave)++;

        if(n->dado.tipo == 'D')
            (*contDomest)++;

        n = n->prox;
    }

    n = np->inicio;

    while(n) {
        (*contTotal)++;

        if(n->dado.quadro == 'G')
            (*contGrave)++;

        if(n->dado.tipo == 'D')
            (*contDomest)++;

        n = n->prox;
    }

    cout << "Total de fichas: " << *contTotal << "\nPorcentagem de quadros graves: " << ((*contGrave)*100.0)/(*contTotal) << "\nTotal animais domesticos: " << *contDomest;
}

void mostraPilha(Pilha s, Pilha d) {
    cout << "Animais Selvagens:\n";
    mostraP(&s);

    cout << "\nAnimais Domesticos:\n";
    mostraP(&d);
}

void removePilha(Pilha *s, Pilha *d) {

    char c;

    cout << "Informe a pilha que deseja remover (S-selvagem, D-doméstico):";
    cin >> c;
    fflush(stdin);

            if(c == 'S')
                desempilhaP(s);
            else if(c == 'D')
                desempilhaP(d);
}

void mostraGraveNovo(Pilha s, Pilha d) {

    NoPilha *ns = s.topo;
    NoPilha *nd = d.topo;
    NoPilha *aux;
    int menor = INT_MAX;

    while(ns) {
        if((menor > ns->dado.idade) && (ns->dado.quadro == 'G'))
        {
            menor = ns->dado.idade;
            aux = ns;

        }

        ns = ns->prox;
    }

    while(nd) {
        if(menor > nd->dado.idade && nd->dado.quadro == 'G')
        {

            menor = nd->dado.idade;
            aux = nd;
        }

        nd = nd->prox;
    }

    cout << "O nome do animal que possui a menor idade com o quadro clínico grave é " << aux->dado.nome;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct no {
    int codigo;
    char nome[30];
    struct no *next;
} no;

struct no *inicio, *auxiliar, *auxiliar2, *corrente;

int chained = 0; // Encadeado

void enterData() {
    printf("Informe o codigo...\n");
    scanf("%d", &corrente->codigo);
    printf("Informe o nome...\n");
    scanf("%s", &corrente->nome);
}

void insert(no **lista) {
    if (inicio == NULL) {
        corrente = (no*)malloc(sizeof(no));

        inicio = corrente;
        auxiliar = corrente;

        corrente->next=NULL;

        enterData();
    } else {
        corrente=(no*)malloc(sizeof(no));

        auxiliar->next=corrente;
        corrente->next=NULL;
        auxiliar = corrente;

        enterData();
    }
}

void search() {
    printf("\n===== SEARCH =======\n");
    char nome[30];
    printf("Digite o nome pra pesquisar: ");
    scanf("%s", &nome);

    auxiliar = inicio;

    bool found = false;

    while (auxiliar != NULL) {
        if (strcmp(auxiliar->nome, nome) == 0) {
            printf("\nCodigo: %d\n", auxiliar->codigo);
            printf("Nome: %s\n", auxiliar->nome);
            found = true;
        }

        auxiliar = auxiliar->next;
    }

    if (!found) {
         printf("\nNão foi possível encontrar %s", nome);
    }
}

void show() {
    if (inicio == NULL) {
        printf("\nNão há dados para exibir.");
        return;
    }

    printf("\n===== SHOW =======\n");
    auxiliar = inicio;

    while (auxiliar != NULL) {
        printf("Codigo: %d\n", auxiliar->codigo);
        printf("Nome: %s\n", auxiliar->nome);

        auxiliar = auxiliar->next;
    }
    system("pause");
}


void classifyData() {
    corrente = (no*)malloc(sizeof(no));
    enterData();
    auxiliar=inicio;

    chained = 0;

    if (inicio == NULL) {
        inicio = corrente;
        corrente->next=NULL;
        printf("O elemento e o primeiro da lista.\n");
    } else {
        if (strcmp(corrente->nome, auxiliar->nome) <= -1) {
            printf("aaaa");
            corrente->next=auxiliar;
            inicio = corrente;
            printf("\nElemento nao precede o primeiro elemento da lista.\n");
            system("pause");
        } else {
            auxiliar2 = auxiliar->next;

            while (auxiliar2 != NULL) {
               if (strcmp(corrente->nome, auxiliar->nome) != 0 && strcmp(corrente->nome, auxiliar2->nome) != 0) {
                    auxiliar->next=corrente;
                    corrente->next=auxiliar2;
                    printf("Elemento encadeado no meio da lista");
                    chained = 1;
                    system("pause");
                    break;
               } else {
                    auxiliar=auxiliar->next;
                    auxiliar2=auxiliar2->next;
               }
            }
        }

        if (auxiliar2 == NULL && chained == 0) {
            auxiliar->next=corrente;
            corrente->next=NULL;
            printf("Elemento inserido no final da lista.");
            system("pause");
        }
    }
}

void removeData() {
    printf("\n===== REMOVE =======\n");
    char nome[30];
    printf("Digite o nome pra remover: ");
    scanf("%s", &nome);

    auxiliar = inicio;

    bool found = false;

     while (auxiliar != NULL) {
        if (strcmp(auxiliar->nome, nome) == 0) {
            corrente->next=auxiliar->next;
            printf("Codigo pra remover: %d\n", auxiliar->codigo);
            free(auxiliar);
            found = true;
        } else {
            auxiliar = auxiliar->next;
        }
    }

    if (!found) {
        printf("\nNão foi possível encontrar %s", nome);
    }

}

void menu(){
   // system("cls");
    printf("selecione a opcao\n");
    printf("(1) - inserir\n");
    printf("(2) - imprimir\n");
    printf("(3) - remover\n");
    printf("(4) - buscar\n");
    printf("(0) - sair\n");
}

int main() {
    int op;
    inicio = NULL;
    auxiliar = NULL;
    corrente = NULL;
    while(op!=0){
    menu();
    scanf("%d",&op);
    switch(op){
    case 1:
        classifyData(&inicio);
    break;
    case 2:
        show();
    break;
    case 3:
        removeData();
    break;
    case 4:
        search();
    break;
    }
    }/*
    for (int i = 0; i < 3; i++) {

    }

    show();

    search();

    removeData();

    show();*/
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct NODE {
        char caracter;
        struct NODE *prox;
} node;

typedef struct PILHA {
        int tam;
        node *inicio;
} pilha;


pilha *inicia(){
        pilha *p= (pilha *) malloc(sizeof(pilha));
        p->inicio = NULL;
        p->tam=0;
        return p;
}

int vazia(pilha *PILHA){
        return PILHA->tam == 0 ? 1 : 0;
}

void libera(pilha *PILHA){
        node *atual;
        if(vazia(PILHA))
                return;

        atual = PILHA->inicio;
        while((atual=PILHA->inicio) != NULL) {
                PILHA->inicio = atual->prox;
                free(atual);
        }
        free(PILHA);
        PILHA = NULL;
}

void push(pilha *PILHA, char caracter){
        node *novo = (node*) malloc(sizeof(node));
        novo->caracter =  caracter;
        novo->prox = PILHA->inicio;
        PILHA->inicio = novo;
        ++PILHA->tam;
}

void pop(pilha *PILHA){
        node *aux;
        aux = PILHA->inicio;
        PILHA->inicio = aux->prox;
        free(aux);
        --PILHA->tam;
}

int main(void){
        char cadeia[100];
        int i;
        pilha *PILHA = inicia();
        scanf("%[^\n]s",cadeia);
        for(i=0; i<strlen(cadeia); i++) {
                if(cadeia[i]=='(' || cadeia[i]=='[' || cadeia[i]=='{') {
                        push(PILHA, cadeia[i]);
                }
                else if(cadeia[i]==')') {
                        if(PILHA->inicio->caracter=='(') {
                                pop(PILHA);
                        }
                }else if(cadeia[i]==']') {
                        if(PILHA->inicio->caracter=='[') {
                                pop(PILHA);
                        }
                }
                else if(cadeia[i]=='}') {
                        if(PILHA->inicio->caracter=='{') {
                                pop(PILHA);
                        }
                }else if(cadeia[i]>=32 && cadeia[i]<=126) {
                        continue;
                }
        }
        if(PILHA->tam==0) {
                printf("true\n");
        }else{
                printf("false\n");
        }
        return 0;
}

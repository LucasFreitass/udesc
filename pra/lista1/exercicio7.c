#include <stdio.h>
#include <stdlib.h>

typedef struct Lista {
        int elemento;
        struct Lista *proximo;
} no;

void Inserecomeco (no **topo, int elem) {
        no *novo; // estou declarando uma lista ( ou tipo isso )
        novo = malloc(sizeof(no)); // alocando a memoria dinamicamente ...
        novo->elemento = elem; // inserindo o inteiro na lista.
        if (*topo == NULL) {
                novo->proximo = NULL;
                *topo = novo;
        }
        else { // se ja tiver algum elemento na lista
                novo->proximo = *topo;
                *topo = novo;
        }
}

void InsereFim(no **topo, int elem) {
        no *novo;
        novo = malloc(sizeof(no));
        novo->elemento = elem;
        novo->proximo = NULL;
        if (*topo == NULL) {// ou seja lista vazia..
                *topo = novo;
        } else {// nao ser vazia
                no *aux;
                for(aux = (*topo); aux->proximo != NULL; aux = aux->proximo);
                aux->proximo = novo;
        }
}

void printar(no *topo ) {
        for(no *aux = topo; aux!=NULL; aux = aux->proximo)
                printf("%d ", aux->elemento);
        printf("\n");
}

void acharCruzamento(no *topo, no *topo2) {
        for(no *aux = topo; aux != NULL; aux = aux->proximo)
                for(no *aux2 = topo2; aux2 != NULL; aux2 = aux2->proximo)
                        if(aux->elemento == aux2->elemento) {
                                printf("%d\n", aux->elemento);
                                return;
                        }
}

int main () {
        no *topo = NULL;
        no *topo2 = NULL;
        // Agora ao chamar a funcao, tenho que passar o endereco de topo
        // pois topo e um ponteiro para ponteiro ..

        int x=0;
        int cont=0;
        int cont2=0;
        while (scanf("%d",&x ) && x != -1)
                InsereFim(&topo, x); cont++;

        while (scanf("%d",&x ) && x !=-1) // LENDO A SEGUNDA LISTA PARA VERIFICAR.
                InsereFim(&topo2, x); cont++;

        acharCruzamento(topo, topo2);

        return 0;

}

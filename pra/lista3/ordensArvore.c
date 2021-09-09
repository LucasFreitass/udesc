#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    struct no *esq;
    struct no *dir;
    int elem;
} no;

typedef struct tree {
    no *root;
} tree;

tree *new_tree() {
    tree* t = (tree*) malloc(sizeof(tree));

    t->root = NULL;
    return t;
}

void insert(tree* t, int elem) {
    no *new = (no*) malloc(sizeof(no));

    new->elem = elem;
    new->esq = NULL;
    new->dir = NULL;

    if (t->root == NULL) {
        t->root = new;
        return;
    }
    no *aux = t->root;

    while (1) {
        if (elem > aux->elem) {
            if (aux->dir == NULL) {
                aux->dir = new;
                break;
            }
            aux = aux->dir;
        }
        else if (elem < aux->elem) {
            if (aux->esq == NULL) {
                aux->esq = new;
                break;
            }
            aux = aux->esq;
        }
        else {
            break;
        }
    }
}

int search(tree* t, int elem) {
    no *aux = t->root;
    int cont=0;

    while (aux != NULL) {
      cont++; // tirar esse cont dps, estou so vendo quantas iterações ele tem..
        if (elem > aux->elem) {
            aux = aux->dir;
            cont++;
        }
        else if (elem < aux->elem) {
            aux = aux->esq;
            cont++;
        }
        else {
            return cont;
        }
    }

    return printf("Chave não encontrada na arvore\n");;
}

void in_order(no* root) {
    if (root != NULL) {
        in_order(root->esq);
        printf("%d ", root->elem);
        in_order(root->dir);
    }
}

void pre_order(no* root) {
    if (root != NULL) {
        printf("%d ", root->elem);
        pre_order(root->esq);
        pre_order(root->dir);
    }
}
void pos_order(no* root) {
    if (root != NULL) {
        pos_order(root->esq);
        pos_order(root->dir);
        printf("%d ", root->elem);
    }
}
void searchWidth(no* root){
  if (root != NULL) {

  }
}


int main() {
    tree* t = new_tree();
    int e, chave, print;

    scanf("%d", &e);
    while(e != -1) {
        insert(t, e);
        scanf("%d", &e);
    }
    scanf("%d",&chave);
    printf("in-ordem: ");
    in_order(t->root);
    printf("\n");
    printf("pre-ordem: ");
    pre_order(t->root);
    printf("\n");
    printf("pos-ordem: ");
    pos_order(t->root);
    printf("\n");
    printf("%d\n", search(t ,chave));
    return 0;
}

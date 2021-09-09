#include <stdio.h>
#include <stdlib.h>
#include <math.h> // COMPILAR COM -LM NO FINAL, POIS É USADA A FUNÇÃO MATEMATICA LINK MATHEMATICS

struct vetorzao {
        int v;
        struct vetorzao *v1;
};

void powerset (int *vetor, int n, struct vetorzao *anterior) {
        struct vetorzao atual;

        if (!n) {
                printf("[");
                while (anterior) {
                        printf(" %d", anterior->v );
                        anterior = anterior->v1;
                }
                printf("]");
        } else {
                atual.v = *vetor;
                atual.v1 = anterior;
                powerset(vetor+1, n-1, anterior);// RECURSAO DAS BRABA!
                powerset(vetor+1, n-1, &atual);
        }
}
int main () {
        int *v,n,i;
        scanf("%d",&n );
        v = malloc(sizeof(int)*n);
        for (i = 0; i < n; i++)
                scanf("%d",&v[i]);
        powerset(v, n, 0);
        free(v);
        return 0;
}

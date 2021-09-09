#include <stdio.h>
#include <stdlib.h>

int main () {
        int  *v,k,n,i,teste=0,j;
        scanf("%d",&n);
        v = malloc(sizeof(int)*n);
        for (i = 0; i < n; i++)
                scanf("%d",&v[i] );
        scanf("%d",&k );
        int aux=0;
        for (i = 0; i < n; i++)
                for (j = 0; j < n; j++) {
                        aux = v[i] + v[j];
                        //  printf("%d..",aux ); testando oq ta sendo somado aqui.
                        if (aux == k) teste++;
                }
        if (teste >=1 ) printf("verdadeiro\n");
        else printf("falso\n");
        free(v);
        return 0;
}

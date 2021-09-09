#include <stdio.h>
#include <stdlib.h>

int main () {

        int  *v;
        int n;
        int i;
        int j;
//int min;
        int aux=0;
//int aux1=0;


        scanf("%d",&n);

        v = malloc(sizeof(int)*n);

        for (i = 0; i < n; i++) {
                scanf("%d",&v[i] );
        }

        for (i = 0; i < n; i++) { // ORDENAÇÃO
                for (j = 0; j < n; j++) {
                        if (v[i] < v[j]) {
                                aux = v[i];
                                v[i] = v[j];
                                v[j] = aux;
                        }
                }
        }

//for (i = 0; i < n; i++) { // TESTANDO A ORDENAÇÃO..
//  printf("%d ",v[i] );
//} // so teste de ordenaçãoo

        for (i = 0; i < n; i++) {
                if (v[i] >= 0 && (v[i]+1 != v[i+1] && v[i] != v[i+1] )) {
                        printf("%d\n",v[i]+1 );
                        break;
                }
                //printf("%d ",v[i]+1 );
        }
//printf("%d ",v[i]+1 );

        free(v);
        return 0;
}

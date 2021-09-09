#include <stdio.h>
#include <stdlib.h>

int main () {

        int  *v, *v1, n,i,j;
        scanf("%d",&n);
        v = malloc(sizeof(int)*n);
        for (i = 0; i < n; i++) {
                scanf("%d",&v[i] );
        }
        v1 = malloc(sizeof(int)*n);
        for (i = 0; i < n; i++) {
                v1[i] = 1;
        }
        for (i = 0; i < n; i++) {
                for (j = 0; j < n; j++) {
                        if (i != j ) {
                                v1[i] *= v[j];
                        }
                }
                printf("%d ",v1[i]);
        }
        free(v);
        free(v1);
        return 0;
}

    #include <stdio.h>
#include <stdlib.h>
int main () {
        int *v,*aux, n, i, k, j, maior;
        printf("Entre com o valor do tamanho do vetor -> o vetor -> o valor de k\n");
        scanf("%d",&n);
        v = malloc(sizeof(int)*n);
        for (i = 0; i < n; i++) {
                scanf("%d",&v[i]);
        }
        scanf("%d",&k);
        for (i =0; i < n-(k-1); i++) {
                maior = v[i];
                for (j = i; j < i+k; j++) {
                        if (v[j] > maior) {
                                maior = v[j];
                        }
                }
                printf("%d ",maior);
        }
        printf("\n");
        return 0;
}

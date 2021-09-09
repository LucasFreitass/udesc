#include <stdio.h>
#include <stdlib.h>

int main () {
	int *vetor, i, j, tam,aux=0;
	scanf("%d",&tam);
	vetor = malloc(sizeof(int)*tam);
	for (i = 0; i < tam; i++) {
		scanf("%d",&vetor[i]);
	}
	for (i = 0; i < tam; i++) {
		printf("%d \n",vetor[i]);
	}

	for (i = 0; i < tam; i++) {
		for (j = i+1; j < tam; j++) {
			if (vetor[i] > vetor[j]) {
				aux = vetor[i];
				vetor[i] = vetor[j];
				vetor[j] = aux;
			}
		}
	}
	for (i = 0; i < tam; i++) {
		printf("%d ",vetor[i]);
	}
	return 0;
}

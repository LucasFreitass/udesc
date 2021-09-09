#include <stdio.h>
#include <stdlib.h>

int pesquisa(int *v, int chave, int qnt) {

	int aux, i, j,meio;

	for (i = 0; i < qnt; i++) {
		for (j = i+1; j < qnt; j++) {
			if (v[j]<v[i]) {
				aux=v[i];
				v[i]=v[j];
				v[i]=aux;
			}
		}
	}
	int ini, meio, fim, n,i;
	ini=0;
	fim=n-1;

	while (ini<=fim) {
		meio=(fim+ini)/2;
		if (v[meio] == chave) {
			return meio;
		}
		if (chave > v[meio]) {
			ini=meio+1;
		}
		else fim = meio-1;
	}
}

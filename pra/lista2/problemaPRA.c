#include <stdio.h>
#include <stdlib.h>
// TO USANDO A PARADA DO N+1, PARA MELHORAR O CODIGO, FAZER MENOS LAÇOS.
int busca (int *v,int valor, int qnt ) {
    int i=0;
    qnt=qnt+1;
    v[qnt] = valor;
    while (v[i] != valor) {
      i++;
    }
    if (i<qnt){
      printf("%d\n",i );
    }
    return printf("nao achei\n");
}

int main () {
  int *v, i, qnt, valor;
  scanf("%d",&qnt);
  v = malloc(sizeof(int)*qnt);
  for (i = 0; i < qnt; i++) {
    scanf("%d",&v[i]);
  }
  scanf("%d",&valor);
  busca(v, valor,qnt);
  return 0;
}

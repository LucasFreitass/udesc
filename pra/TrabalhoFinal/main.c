#include <stdio.h>
#include <stdlib.h>
#include "ArvoreAVL.h"
#include <string.h>
#include <time.h>

int main(){
  void casoPior();
	void casoMedio();
	void casoMelhor();

	casoPior();
	casoMedio();
	casoMelhor();


  return 0;
}

void gravarArquivo (int qualTeste, int i) {

	char texto1[1][15] = {"_Adicao"};
	char texto2[1][15] = {"_Balanceamento"};
	char testes[3][30] = {"Caso_Pior", "Caso_Médio", "Caso_Melhor"};
	char test[100];

	strcpy(test,testes[qualTeste]);

	FILE *file = fopen("./saidasTrabFinal.txt","a+");
	fprintf(file,"%s;%d;%d\n", strcat(test,*texto1),i,complexidadeAdicao);

	strcpy(test,testes[qualTeste]);

	fprintf(file, "%s;%d;%d\n", strcat(test,*texto2),i,complexidadeBalanciamento);

	fclose(file);
}

void casoPior(){
	int valor, i, j, n=100;

	for (i = 1; i <= n; i++) {
		complexidadeAdicao = 0;
		complexidadeBalanciamento = 0;
		complexidadeAdicao = 0;
		ArvAVL* a;
		a = cria_ArvAVL();
		for(j=0; j<i; j++) {
			insere_ArvAVL(a,j);

		}
		gravarArquivo(0, i);
		libera_ArvAVL(a);
	}
}

void casoMedio(){
	int valor, i, j, n=100;
	srand(time(NULL));
	for (i = 1; i <= n; i++){
		complexidadeAdicao = 0;
		complexidadeBalanciamento = 0;
		ArvAVL *a;
		a = cria_ArvAVL();

		for(j=0; j<i ;j++){
			valor = rand() % 100;
			insere_ArvAVL(a, valor);
		}
		gravarArquivo(1, i);
		libera_ArvAVL(a);
	}
}

void casoMelhor(){
	int valor, i, j,n=100;

	for (i = 1; i <= n; i++){
		ArvAVL *a, *b;
		a = cria_ArvAVL();
		b = cria_ArvAVL();


		for(j=0; j<i ;j++){
			insere_ArvAVL(a, j);
		}
		complexidadeAdicao = 0;
		complexidadeBalanciamento = 0;
		insereLargura(a, b);

		gravarArquivo(2, i);
		libera_ArvAVL(a);
	}
}

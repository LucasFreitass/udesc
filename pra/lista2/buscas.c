#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
	int cont_atribuicao;
	int cont_comparacao;
	int cont_testes;
	int pos_buscas;
	int qualTeste;
} resultados;

void interpolacao(int chave, int *v, int n, resultados *res) {
	int inicio=0, meio, fim=n-1,aux, i, j;
	res->qualTeste = 4;

	for (i = 0; i < n; i++) {
		for (j = i+1; j < n; j++) {
			if (v[j]<v[i]) {
				aux=v[i];
				v[i]=v[j];
				v[j]=aux;
			}
		}
	}
	while (inicio<=fim) {
		res->cont_testes++;
		if(v[fim] != v[inicio]) {
			res->cont_comparacao++;
			meio = inicio+((fim-inicio)*(chave-v[inicio]))/(v[fim]-v[inicio]);
			res->cont_atribuicao++;
		}
		else {
			res->cont_comparacao++;
			res->pos_buscas = meio;
			res->cont_atribuicao++;
			return;
		}
		if (chave < v[meio]) {
			res->cont_comparacao++;
			fim = meio -1;
			res->cont_atribuicao++;
		} else if (chave > v[meio]) {
			res->cont_comparacao+=2;
			inicio=meio+1;
			res->cont_atribuicao++;
		} else {
			res->cont_comparacao+=2;
			res->pos_buscas = meio;
			return;
		}
	}
	res->pos_buscas = -1;
}

void sequencial(int chave, int *v, int n, resultados *res){
	res->qualTeste = 1;

	int i;
	for (i = 0; i < n; i++) {
		res->cont_testes++;
		if (v[i] == chave) {
			res->cont_comparacao++;
			res->pos_buscas = i;
			return;
		}
	}
	res->pos_buscas = -1;
}

void sequencial_sentinela(int chave, int *v, int n, resultados *res){
	res->qualTeste = 2;

	int i=0;
	v[n] = chave; // atribuindo a chave a ultima posição do vetor.
	res->cont_atribuicao++;
	while (v[i] != chave) {
		res->cont_testes++;
		i++;
	}
	if (i<n) {
		res->cont_comparacao++;
		res->pos_buscas = i;

	}
	else res->pos_buscas = -1;
}

void binaria(int chave, int *v, int n, resultados *res){
	res->qualTeste = 3;

	int inicio=0,meio, fim=n-1,i,j, aux=0;
	for (i = 0; i < n; i++) {
		for (j = i+1; j < n; j++) {
			if (v[j]<v[i]) {
				aux=v[i];
				v[i]=v[j];
				v[j]=aux;
			}
		}
	}
	while (inicio <= fim) {
		res->cont_testes++;
		meio = (inicio+fim)/2;
		if (chave < v[meio]) {
			res->cont_comparacao++;
			res->cont_atribuicao+=2;
			fim = meio-1;
		} else if (chave > v[meio]) {
			inicio = meio+1;
			res->cont_comparacao+=2;
			res->cont_atribuicao+=2;
		} else {
			res->cont_comparacao=+3;
			res->cont_atribuicao++;
			res->pos_buscas = meio;
			return;
		}
	}
	res->pos_buscas = -1;
}

void limpaDados (resultados *res){
	res->cont_testes=0;
	res->cont_atribuicao=0;
	res->cont_comparacao=0;
	res->pos_buscas=0;
	res->qualTeste=0;
}

void mostraResultado(resultados res, int chave) {
	char testes[4][30] = {"sequencial", "sentinela", "binario", "interpolacao"};
	printf("TESTE %s: A chave %d esta na pos %d do vetor\n", testes[res.qualTeste-1], chave, res.pos_buscas);
	printf("Contador atribuiicao: %d\n",res.cont_atribuicao);
	printf("Contador comparacao: %d\n",res.cont_comparacao);
	printf("Contador testes: %d\n",res.cont_testes );
	printf("Complexidade do teste %s: %d\n",testes[res.qualTeste-1],res.cont_atribuicao+res.cont_comparacao+res.cont_testes);

}

void gravarArquivo (resultados res, int max) {
	char testes[4][30] = {"Sequencial", "Sentinela", "Binário", "Interpolação"};

	FILE *file = fopen("./saidasTestes.csv","a+");
	fprintf(file,"%s;%d;%d\n",testes[res.qualTeste-1],res.cont_atribuicao + res.cont_comparacao + res.cont_testes, max);
	fclose(file);
}

int main (int argc, char *argv[]) {
	int *v,i, chave, max;
	bool grava = false;
	if(argc > 1 && strcmp(argv[1],"true")==0) {
		grava = true;
	}
	resultados res;

	limpaDados(&res);

	srand(time(0));
	max = rand()%100;
	chave = rand()%100;

	v = (int *) calloc(max, sizeof(int));
	for (i = 0; i < max; i++) {
		v[i] = rand()%100;
	}

	sequencial(chave,v, max, &res);
	mostraResultado(res, chave);
	if(grava)
		gravarArquivo(res,max);
	limpaDados(&res);

	sequencial_sentinela(chave, v, max, &res);
	mostraResultado(res, chave);
	if(grava)
		gravarArquivo(res,max);
	limpaDados(&res);

	binaria(chave,v, max, &res);
	mostraResultado(res, chave);
	if(grava)
		gravarArquivo(res,max);
	limpaDados(&res);

	interpolacao(chave,v, max, &res);
	mostraResultado(res, chave);
	if(grava)
		gravarArquivo(res,max);
	limpaDados(&res);
// SCRIPT PARA ABRIR O GRÁFICO ATUALIZADO A CADA VEZ QUE GRAVAR NOVOS ARQUIVOS NO saidasTestes.csv
	if (argc == 3 && strcmp(argv[2],"r" )==0) {
		system("Rscript geraGrafico.R");
		system("xdg-open resultados.pdf");
	}
	return 0;
}

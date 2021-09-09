#include <stdio.h>
#include <stdlib.h>

typedef struct no {
	struct no *pai;
	struct no *esquerda;
	struct no *direita;
	void *v;
} No;

typedef struct arvore {
	No *raiz;
	int tamanho;
	int (*compara)(void *, void *);
} Arvore;

typedef struct {
	int cont_atribuicao_adicao;
	int cont_comparacao_adicao;
	int cont_testes_adicao;
	int cont_atribuicao_balanceamento;
	int cont_comparacao_balanceamento;
	int cont_testes_balanceamento;
	int qualTeste;

} complex;


Arvore* cria(int tamanho, int (compara)(void *, void *));
int vazia(Arvore *arvore);
No* localiza(Arvore *arvore, No *no, void *valor);
No* adiciona(Arvore *arvore, void *valor,complex *comp);
void percorreEmOrdem(No* no, void (visita)(void *valor));
void percorrePreOrdem(No* no, void (visita)(void *valor));
void percorrePosOrdem(No* no, void (visita)(void *valor));
void removeNo(Arvore *arvore, No *no);
void percorreLargura(No* no, void (visita)(void*));
int altura(No *no);
int fb(No *no);
No *rotacaoSimplesDireita(No *no);
No *rotacaoSimplesEsquerda(No *no);
No *rotacaoDuplaDireita (No* no);
No *rotacaoDuplaEsquerda(No* no, Arvore * arvore);
void balanceamento(No *no, Arvore *arvore,complex *comp);
void gravarArquivo (complex comp, int i);
void limpaDados (complex *comp);
int Existe (int valor, int valor_tmp, int tam);

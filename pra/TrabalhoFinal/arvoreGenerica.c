#include <stdio.h>
#include <stdlib.h>
#include "ArvoreGenerica.h"
#include <string.h>

Arvore* cria(int tamanho, int (compara)(void *, void *)) {
	Arvore *arvore = malloc(sizeof(Arvore));
	arvore->raiz = NULL;
	arvore->tamanho = tamanho;
	arvore->compara = compara;

	return arvore;
}

int vazia(Arvore *arvore) {
	return (arvore->raiz == NULL);
}

No* localiza(Arvore *arvore, No *no, void *valor) {
	if (arvore->compara(valor,no->v) > 0) {
		if (no->direita != NULL) {
			return localiza(arvore, no->direita, valor);
		}
	} else {
		if (no->esquerda != NULL) {
			return localiza(arvore, no->esquerda, valor);
		}
	}

	return no;
}

No* adiciona(Arvore *arvore, void *valor, complex *comp) {
	No *pai = NULL;
	comp->cont_atribuicao_adicao++;

	if (arvore->raiz != NULL) {
		comp->cont_comparacao_adicao++;
		pai = localiza(arvore, arvore->raiz, valor);
		comp->cont_atribuicao_adicao++;
	}

	No *no = malloc(sizeof(No));
	comp->cont_atribuicao_adicao++;
	no->pai = pai;
	comp->cont_atribuicao_adicao++;

	no->esquerda = NULL;
	comp->cont_atribuicao_adicao++;
	no->direita = NULL;
	comp->cont_atribuicao_adicao++;

	no->v = malloc(arvore->tamanho);
	comp->cont_atribuicao_adicao++;
	memcpy(no->v,valor,arvore->tamanho);

	if (pai == NULL) {
		comp->cont_comparacao_adicao++;
		arvore->raiz = no;
		comp->cont_atribuicao_adicao++;
	} else {
		comp->cont_comparacao_adicao++;
		if (arvore->compara(no->v,pai->v) > 0) {
			comp->cont_comparacao_adicao++;
			pai->direita = no;
			comp->cont_atribuicao_adicao++;
		} else {
			comp->cont_comparacao_adicao++;
			pai->esquerda = no;
			comp->cont_atribuicao_adicao++;
		}
	}

	balanceamento(no, arvore, comp);

	return no;
}

void percorreEmOrdem(No* no, void (visita)(void *valor)) {
	if (no != NULL) {
		percorreEmOrdem(no->esquerda, visita);
		visita(no->v);
		percorreEmOrdem(no->direita, visita);
	}
}
void percorrePreOrdem(No* no, void (visita)(void *valor)) {
	if (no != NULL) {
		visita(no->v);
		percorrePreOrdem(no->esquerda, visita);
		percorrePreOrdem(no->direita, visita);
	}
}
void percorrePosOrdem(No* no, void (visita)(void *valor)) {
	if (no != NULL) {
		percorrePosOrdem(no->esquerda, visita);
		percorrePosOrdem(no->direita, visita);
		visita(no->v);
	}
}

void removeNo(Arvore *arvore, No *no){
	if(no->esquerda != NULL) {
		removeNo(arvore, no->esquerda);
	}

	if(no->direita != NULL) {
		removeNo(arvore, no->direita);
	}

	if(no->pai == NULL) {
		arvore->raiz = NULL;
	}
	else{
		if(no->pai->esquerda == no) {
			no->pai->esquerda = NULL;
		}
		else{
			no->pai->direita = NULL;
		}
	}

	free(no);
}

void percorreLargura(No* no, void (visita)(void*)) {
	No **nivel = malloc(sizeof(No));
	nivel[0] = no;

	int tam = 1;

	while(tam != 0) {
		int filhos = 0;

		for(int i = 0; i < tam; i++) {
			if (nivel[i]->esquerda != NULL) {
				filhos++;
			}

			if (nivel[i]->direita != NULL) {
				filhos++;
			}
		}

		No** nos = malloc(filhos * sizeof(No));
		filhos = 0;

		for(int i = 0; i < tam; i++) {
			if (nivel[i]->esquerda != NULL) {
				nos[filhos++] = nivel[i]->esquerda;
			}

			if (nivel[i]->direita != NULL) {
				nos[filhos++] = nivel[i]->direita;
			}

			visita(nivel[i]->v);
		}


		free(nivel);

		nivel = nos;
		tam = filhos;
	}
}

int altura(No *no) {
	int esquerda = 0;
	int direita = 0;

	if (no->esquerda != NULL) {
		esquerda = altura(no->esquerda) + 1;
	}

	if (no->direita != NULL) {
		direita = altura(no->direita) + 1;
	}

	return direita > esquerda ? direita : esquerda;
}

int fb(No *no) {
	int esquerda = 0;
	int direita = 0;
	if (no->direita != NULL) {
		direita = altura(no->direita) + 1;
	}

	if (no->esquerda != NULL) {
		esquerda = altura(no->esquerda) + 1;
	}

	return esquerda - direita;
}

No *rotacaoSimplesDireita(No *no){

	No *pai = no->pai;
	No *esquerda = no->esquerda;

	no->esquerda = esquerda->direita;
	no->pai = esquerda;

	esquerda->direita = no;
	esquerda->pai = pai;

	// if(pai != NULL)
	// 	pai->direita = esquerda;
	return esquerda;
}

No *rotacaoSimplesEsquerda(No *no){
	No *pai = no->pai;
	No *direita = no->direita;

	no->direita = direita->esquerda;
	no->pai = direita;

	direita->esquerda = no;
	direita->pai = pai;

	// if(pai != NULL)
	// 	pai->direita = direita;

	return direita;
}

No *rotacaoDuplaDireita (No* no) {
	no->esquerda = rotacaoSimplesEsquerda(no->esquerda);
	return rotacaoSimplesDireita(no);
}

No *rotacaoDuplaEsquerda(No* no, Arvore *arvore){
	no->direita = rotacaoSimplesDireita(no->direita);
	return rotacaoSimplesEsquerda(no);
}


void balanceamento(No *no, Arvore *arvore, complex *comp) {
	while (no != NULL) {
		comp->cont_testes_balanceamento++;
		int fator = fb(no);
		comp->cont_atribuicao_balanceamento++;
		if (fator > 1) {
			comp->cont_comparacao_balanceamento++;
			fator = fb(no->esquerda);
			comp->cont_atribuicao_balanceamento++;

			if (fator > 0) {
				comp->cont_comparacao_balanceamento++;
				No *esquerda = rotacaoSimplesDireita(no);
				comp->cont_atribuicao_balanceamento++;

				if(esquerda->pai == NULL) {
					comp->cont_comparacao_balanceamento++;
					arvore->raiz = esquerda;
					comp->cont_atribuicao_balanceamento++;
				}
			} else {
				comp->cont_comparacao_balanceamento++;
				No *esquerda = rotacaoDuplaDireita(no);

				comp->cont_atribuicao_balanceamento++;
				if(esquerda->pai == NULL) {
					comp->cont_comparacao_balanceamento++;

					arvore->raiz = esquerda;
					comp->cont_atribuicao_balanceamento++;
				}
			}
		} else if (fator < -1) {
			comp->cont_comparacao_balanceamento+=2;
			fator = fb(no->direita);
			comp->cont_atribuicao_balanceamento++;
			if (fator < 0) {
				comp->cont_comparacao_balanceamento++;

				No *direita = rotacaoSimplesEsquerda(no);
				comp->cont_atribuicao_balanceamento++;

				if(direita->pai == NULL) {
					comp->cont_comparacao_balanceamento++;
					arvore->raiz = direita;
					comp->cont_atribuicao_balanceamento++;
				}

			} else {
				comp->cont_comparacao_balanceamento++;

				no = rotacaoDuplaEsquerda(no, arvore);
				comp->cont_atribuicao_balanceamento++;
				if(no->pai == NULL) {
					comp->cont_comparacao_balanceamento++;
					arvore->raiz = no;
					comp->cont_atribuicao_balanceamento++;
				}

			}
		}
		no = no->pai;
		comp->cont_atribuicao_balanceamento++;
	}
}

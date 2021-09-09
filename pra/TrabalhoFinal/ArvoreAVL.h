
typedef struct NO* ArvAVL;
int complexidadeAdicao;
int complexidadeBalanciamento;

ArvAVL* cria_ArvAVL();
void libera_ArvAVL(ArvAVL *raiz);
int insere_ArvAVL(ArvAVL *raiz, int valor);
int remove_ArvAVL(ArvAVL *raiz, int valor);
int estaVazia_ArvAVL(ArvAVL *raiz);
int altura_ArvAVL(ArvAVL *raiz);
int totalNO_ArvAVL(ArvAVL *raiz);
int consulta_ArvAVL(ArvAVL *raiz, int valor);
void preOrdem_ArvAVL(ArvAVL *raiz);
void emOrdem_ArvAVL(ArvAVL *raiz);
void posOrdem_ArvAVL(ArvAVL *raiz);
void insereLargura(ArvAVL *raiz, ArvAVL *b);
int insereMelhorCaso(ArvAVL *raiz, int valor);
void RotacaoLLMelhorCaso(ArvAVL *A);
void RotacaoRRMelhorCaso(ArvAVL *A);
void RotacaoLRMelhorCaso(ArvAVL *A);
void RotacaoRLMelhorCaso(ArvAVL *A);

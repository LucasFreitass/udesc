#include <iostream>
#include <climits>	// Utiliza o define INT_MAX para valor infinito.
#include <fstream>	// Para ler o grafo em formato txt.

using namespace std;
#define VMAX 27      // Maximo de vertices permitidos.

int menorCaminho(int vertG, bool visitado[], int dist[]){
	int min = INT_MAX; // Inicializa cada valor com "infinito"
	int ret;

	for(int v=0; v<vertG; v++){
		if(visitado[v]==false && dist[v]<=min){
			min = dist[v];
			ret = v;
		}
	}

	return ret;
}

void Dijkstra(int grafo[VMAX][VMAX], int raiz, int vertG){
	int pesoDist[vertG];
	bool visitado[vertG];

	for(int i=0; i<vertG; i++){
		pesoDist[i] = INT_MAX;
		visitado[i] = false;
	}

	pesoDist[raiz] = raiz; // Setando a raiz para iniciar os percursos

	for(int c=0; c<vertG; c++){
		int val = menorCaminho(vertG, visitado, pesoDist);
		visitado[val]=true;

		for(int v=0;v<vertG;v++){
			if(!visitado[v] && grafo[val][v] && pesoDist[val]!=INT_MAX && (pesoDist[val]+grafo[val][v])<pesoDist[v]){
				pesoDist[v] = pesoDist[val]+grafo[val][v];
			}
		}
	}

	putchar('\n');
	cout << "Resultado:" << endl;
	cout << "VERTICE\t\tDISTANCIA" << endl;
	for(int i=0; i<vertG; i++){
		char c = 65+i; // Nomeia cada vertice com uma letra (por isso maximo de vertices = 27)
		cout << "   " << c << "\t\t    " << pesoDist[i] << endl;
	}
}

int main(){

	int opc;
	cout << "##### DIJKSTRA - LUCAS FREITAS E YURI HENRIQUE #####" << endl;
	cout << "(1) - Inserir matriz manualmente." << endl;
	cout << "(2) - Carregar arquivo (grafo.txt)." << endl;
	cout << "(0) - Encerrar." << endl;
	cout << "OPC: ";
	cin >> opc;

	switch(opc){

		case 0:{
			cout << "BYE!" << endl << endl;
			break;
		}

		case 1:{

			int grafo[VMAX][VMAX];
			int vertG, raiz;
			cout << "Defina o numero de vertices: ";
			cin >> vertG;
			cout << "Insira os pesos de cada vertice, linha por linha: " << endl;
			for(int i = 0; i<vertG; i++){
				for(int j = 0; j<vertG; j++){
					cin >> grafo[i][j];
				}
			}
			cout << "Defina a raiz deste grafo: ";
			cin >> raiz;
			Dijkstra(grafo, raiz, vertG);
			break;

		}

		case 2:{

			cout << "Por padrao, a opcao por arquivo considera a primeira linha como raiz." << endl;
			fstream infile;
			infile.open("grafo.txt", ios::in);
			if(!infile.is_open()){
				cout << "ERRO AO ABRIR ARQUIVO: NENHUM ENCONTRADO." << endl << endl;
				break;
			}

			int grafoTam=0, auxVal;
			char carac;
			string ch;

			while(getline(infile, ch)) // Calcula quantas linhas tem a matriz, para ser instanciada.
				grafoTam++;

			int grafo[VMAX][VMAX]; // Instancia o grafo apenas depois de garantir a leitura do arquivo.

			infile.clear(); // Limpa o buffer de leitura do arquivo
			infile.seekg(0); // E rebobina a fita, para o comeco do arquivo
			int coluna = 0;
			int linha = 0;

			while(!infile.eof()){

				getline(infile, ch);
				for(unsigned int count = 0; count<=ch.length(); count++){
					if(ch[count] <= '9' && ch[count] >= '0'){
						carac = ch[count];
						auxVal = atoi(&carac);
						grafo[linha][coluna/2] = auxVal;
						coluna = coluna+2; // Para poder ter espacamento entre valores de uma mesma linha
					}
					if(coluna > (grafoTam*2)-1){ // Quando chegar no fim da linha, retorna a fita e quebra linha
						coluna = 0;
						linha++;
					}
				}
			}

			Dijkstra(grafo, 0, grafoTam);
			break;

		}

		default:{
			cout << "ERRO: Opcao invalida, tente novamente." << endl << endl;
			break;
		}
	}
	return 0;

}

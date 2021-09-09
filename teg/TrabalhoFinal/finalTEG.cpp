#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <map>
#include <iterator>

using namespace std;

#define VMAX 25 //Definindo máximo de vértices para usar como parâmetro de comparação.
// 24 vertices porque estamos considerando os 24 possiveis itinerarios, sendo 1 de destino.

// Struct contendo todos os dados que serao usados nas arestas
// Um trecho é composto pelo numero de voo, saia e chegada, preço e reservas, trechos_t para entender que trechos é um tipo de dados.



typedef struct trechos {
	int numero_voo;
	int horaChegada; // sao string pq sao horas, formato - 11:30, 14:20 etc ..
	int horaPartida;
	string origem;
	string destino;
	int preco;
	int vagas;
} trechos;

typedef struct voos {
	int num_voo;
	trechos trecho;
} voos;


int menorCaminho(bool visitado[], int dist[]){
	int menor = INT_MAX;
	int ret;

	for(int v=0; v<VMAX; v++) {
		if(visitado[v]==false && dist[v]<=menor) {
			menor = dist[v];
			ret = v;
		}
	}
	return ret;
}


// Aqui fica a chamada da funcao que tem a  implementação do Dijkstra
void dijkstra(int mat[VMAX][VMAX], int raiz);

void dijkstra(int mat[VMAX][VMAX], int raiz){
	int distancia[VMAX];
	bool visitado[VMAX];

	for(int i = 0; i<VMAX; i++) {
		distancia[i] = INT_MAX;
		visitado[i] = false;
	}

	distancia[raiz] = 0;

	for(int c = 0; c<VMAX; c++) {
		int val = menorCaminho(visitado, distancia);
		visitado[val] = true;

		for(int v=0; v<VMAX; v++) {
			if(!visitado[v] && mat[val][v] && distancia[val]!=INT_MAX && (distancia[val]+mat[val][v])<distancia[v]) {
				distancia[v] = distancia[val]+mat[val][v];
			}
		}
	}
}

int main() {

	trechos t[24];

	t[0].numero_voo = 501;
	t[0].horaChegada= 1000;
	t[0].horaPartida= 800;
	t[0].origem = "SAO";
	t[0].destino = "GOI";
	t[0].preco=120;
	t[0].vagas=80;

	t[1].numero_voo = 501;
	t[1].horaChegada= 1340;
	t[1].horaPartida= 1100;
	t[1].origem = "GOI";
	t[1].destino = "SAL";
	t[1].preco=120;
	t[1].vagas=130;

	t[2].numero_voo = 501;
	t[2].horaChegada= 1700;
	t[2].horaPartida= 1550;
	t[2].origem = "SAL";
	t[2].destino = "REC";
	t[2].preco=100;
	t[2].vagas=120;

	t[3].numero_voo = 501;
	t[3].horaChegada= 1800;
	t[3].horaPartida= 1845;
	t[3].origem = "REC";
	t[3].destino = "NAT";
	t[3].preco=80;
	t[3].vagas=100;

	t[4].numero_voo = 513;
	t[4].horaChegada= 1050;
	t[4].horaPartida= 900;
	t[4].origem = "SAO";
	t[4].destino = "BRA";
	t[4].preco=25;
	t[4].vagas=20;

	t[5].numero_voo = 513;
	t[5].horaChegada= 1500;
	t[5].horaPartida= 1145;
	t[5].origem = "BRA";
	t[5].destino = "FOR";
	t[5].preco=90;
	t[5].vagas=180;

	t[6].numero_voo = 513;
	t[6].horaChegada= 1620;
	t[6].horaPartida= 1550;
	t[6].origem = "FOR";
	t[6].destino = "REC";
	t[6].preco=100;
	t[6].vagas=100;

	t[7].numero_voo = 581;
	t[7].horaChegada= 1020;
	t[7].horaPartida= 650;
	t[7].origem = "CTB";
	t[7].destino = "MAN";
	t[7].preco=320;
	t[7].vagas=20;

	t[8].numero_voo = 581;
	t[8].horaChegada= 1200;
	t[8].horaPartida= 1050;
	t[8].origem = "MAN";
	t[8].destino = "BEL";
	t[8].preco=100;
	t[8].vagas=180;

	t[9].numero_voo = 581;
	t[9].horaChegada= 1420;
	t[9].horaPartida= 1250;
	t[9].origem = "BEL";
	t[9].destino = "FOR";
	t[9].preco=100;
	t[9].vagas=100;

	t[10].numero_voo = 587;
	t[10].horaChegada= 750;
	t[10].horaPartida= 600;
	t[10].origem = "RIO";
	t[10].destino = "SAO";
	t[10].preco=80;
	t[10].vagas=40;

	t[11].numero_voo = 587;
	t[11].horaChegada= 1100;
	t[11].horaPartida= 830;
	t[11].origem = "SAO";
	t[11].destino = "MAC";
	t[11].preco=180;
	t[11].vagas=100;

	t[12].numero_voo = 587;
	t[12].horaChegada= 1300;
	t[12].horaPartida= 1200;
	t[12].origem = "MAC";
	t[12].destino = "REC";
	t[12].preco=80;
	t[12].vagas=80;

	t[13].numero_voo = 587;
	t[13].horaChegada= 1545;
	t[13].horaPartida= 1500;
	t[13].origem = "REC";
	t[13].destino = "NAT";
	t[13].preco=80;
	t[13].vagas=190;

	t[14].numero_voo = 590;
	t[14].horaChegada= 730;
	t[14].horaPartida= 600;
	t[14].origem = "POA";
	t[14].destino = "CTB";
	t[14].preco=100;
	t[14].vagas=100;

	t[15].numero_voo = 590;
	t[15].horaChegada= 1145;
	t[15].horaPartida= 1000;
	t[15].origem = "CTB";
	t[15].destino = "BRA";
	t[15].preco=75;
	t[15].vagas=60;

	t[16].numero_voo = 590;
	t[16].horaChegada= 1630;
	t[16].horaPartida= 1400;
	t[16].origem = "BRA";
	t[16].destino = "REC";
	t[16].preco=75;
	t[16].vagas=80;

	t[17].numero_voo = 592;
	t[17].horaChegada= 1430;
	t[17].horaPartida= 1200;
	t[17].origem = "BRA";
	t[17].destino = "MAC";
	t[17].preco=50;
	t[17].vagas=20;

	t[18].numero_voo = 593;
	t[18].horaChegada= 945;
	t[18].horaPartida= 900;
	t[18].origem = "RIO";
	t[18].destino = "BRA";
	t[18].preco=50;
	t[18].vagas=90;

	t[19].numero_voo = 594;
	t[19].horaChegada= 600;
	t[19].horaPartida= 500;
	t[19].origem = "RIO";
	t[19].destino = "VIT";
	t[19].preco=100;
	t[19].vagas=70;

	t[20].numero_voo = 594;
	t[20].horaChegada= 945;
	t[20].horaPartida= 830;
	t[20].origem = "VIT";
	t[20].destino = "SAL";
	t[20].preco=80;
	t[20].vagas=70;

	t[21].numero_voo = 594;
	t[21].horaChegada= 1145;
	t[21].horaPartida= 1045;
	t[21].origem = "SAL";
	t[21].destino = "MAC";
	t[21].preco=80;
	t[21].vagas=180;

	t[22].numero_voo = 594;
	t[22].horaChegada= 1800;
	t[22].horaPartida= 1645;
	t[22].origem = "MAC";
	t[22].destino = "NAT";
	t[22].preco=100;
	t[22].vagas=150;

	t[23].numero_voo = 595;
	t[23].horaChegada= 1815;
	t[23].horaPartida= 1730;
	t[23].origem = "REC";
	t[23].destino = "NAT";
	t[23].preco=50;
	t[23].vagas=80;

	// A ideia de comparacao dos horarios eh: Se o numero do voo for diferente entre t[x] e t[y], o numero_voo de x deve ser maior/igual
	// a 100 do numero de numero_voo y;



	int grafo[VMAX][VMAX]; // Instancia uma matriz adjacencia para os 24 vertices.
	int passageiros = 150; // Instancia o contador de passageiros. Este deve ser descontado somente no fim de um caminho minimo.
	int valorTotal = 0; // Inicializa um contador de custo total de viagem. Este deve ser incrementado somente no fim de um caminho minimo.

	/* ALIMENTA A MATRIZ ADJACENCIA */

	for(int linha = 0; linha<VMAX; linha++) {
		for(int coluna = 0; coluna<VMAX; coluna++) {

			grafo[linha][coluna] = 0;
			if((coluna==linha)) {
				grafo[linha][coluna] = t[coluna].preco;
			}
		}
	}

	for(int l = 0; l<VMAX; l++) { // for para corrigir a matriz, para sair de forma correta.
		grafo[l][l+1] = grafo[l][l];
		grafo[l][l] = 0;
	}

	for(int linha = 0; linha<VMAX; linha++) {
		for(int coluna = 0; coluna<VMAX; coluna++) {

			cout << grafo[linha][coluna] << " ";
		}
		putchar('\n');
	}

	/* TERMINOU DE ALIMENTAR A MATRIZ ADJACENCIA COM PRECOS DE TRAJETOS */

	// Nao da pra fazer o grafo diretamente...
	// Mas da pra fazer a tabela 24x24 e definir o que tem valor.

	// PSEUDO ROTEIRO, DOQ TALVEZ TENHA Q FAZER ..

	//Montar o grafo
	//Nao precisa ler de arquivo.
	//Este DIJKSTRA que eu fiz soh precisa de uma matriz de adjacencia com os pesos
	//O resto sao parametros que voce mexe na hora, e sai comparando PRECOS.
	//EX: Primeira iteracao, segue o menor preco.
	//Desconta o numero de passageiros dessa iteracao, junto com o preco*quantos viajaram
	//E assim vai.


	//ex:
	//primeiro cria o grafo com o total de nós e arestas
	// int V = 9, E = 14; -> esses valores tu pega dos dados.
	// Graph g(V, E);
	//agora itera sobre os dados e insere no grafo
	// while(dados) {
	// g.addEdge(origem, aresta);
	// }
	//
	// cout << "Edges of MST are \n";
	// int mst_wt = g.dijkstra();
	//
	// cout << "\nWeight of MST is " << mst_wt;

	return 0;
}

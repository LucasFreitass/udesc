#include <iostream>
#include <list>
#include <fstream>

#define SEMIEULER 1
#define EULERIANO 2

using namespace std;

class Grafo {
int V;
list<int> *adj;

public:

Grafo(int V){
	this->V = V;
	adj = new list<int>[V];
}

void adcAresta(int v1, int v2);
int checaEuler();
bool conectado();
void dfs(int v, bool visitado[]);
void resultado(Grafo &g);
};

void Grafo::adcAresta(int v1, int v2){
	adj[v1].push_back(v2);
	adj[v2].push_back(v1);
}

int Grafo::checaEuler(){
	if(conectado() == false) {
		return 0;
	}

	int ponte = 0;
	for(int cont = 0; cont<V; cont++) {
		if(adj[cont].size() & 1) {
			ponte++;
		}
	}

	if(ponte>2) { // Se um grafo possui ciclo interno maior que 2, ele nao é euleriano.
		return 0; // E a função irá retornar zero (condição de não-euleriano)
	}

	if(ponte==0) { // Do contrario, vai checar se tem ciclos itnernos.
		ponte=EULERIANO; // Se nao tiver ciclos, ele é um grafo euleriano.
	} else {
		ponte=SEMIEULER; // Caso tenha apenas um ciclo interno, semi-euleriano.
	}

	return ponte;
}

bool Grafo::conectado(){ // Esta função marca os vértices já visitados.
	int cont;
	bool visitado[V];

	for(cont = 0; cont<V; cont++) { // Primeiro, nenhum vértice foi visitado, então marcar tudo com falso.
		visitado[cont] = false;
	}

	for(cont = 0; cont<V; cont++) { // Se houver algum vértice de grau 1 ou maior, a busca por vértices irá parar.
		if(adj[cont].size()!=0) {
			break;
		}
	}

	if(cont == V) { // E se não houver nenhum vértice no grafo, ele está conectado com ele mesmo.
		return true;
	}

	dfs(cont, visitado); // Com todas as condições verificadas, será feito DFS para verificar conectividade.
	for(cont = 0; cont<V; cont++) { // Recursivamente busca algum vértice que não tenha sido marcado.
		if(visitado[cont] == false && adj[cont].size()>0) {
			return false; // Se houver algum não visitado, a função será realizada novamente.
		}
	}

	return true;
}

void Grafo::dfs(int v, bool visitado[]){ // DFS para marcar vértices das pontas.
	visitado[v] = true;
	for(list<int>::iterator it = adj[v].begin(); it!=adj[v].end(); it++) {
		if(!visitado[*it]) {
			dfs(*it, visitado);
		}
	}
}

int main(int argc, char const *argv[]){
	int opc;
	cout << "##### FLEURY - LUCAS FREITAS E YURI HENRIQUE #####" << endl;
	cout << "(1) - Inserir manualmente." << endl;
	cout << "(2) - Carregar arquivo (grafo.txt)." << endl;
	cout << "(0) - Encerrar." << endl;
	cout << "OPC: ";
	cin >> opc;

	switch (opc) {

	case 0: {
		cout << "BYE!" << endl;
		break;
	}
	case 1: {
		int vertG, v1=0, v2=0;
		cout << "Insira o numero de vertices: ";
		cin >> vertG;
		Grafo g(vertG);
		cout << "Insira as conexões, formato v1 v2 (ou -1 para terminar): " << endl;
		while(true) {
			cin >> v1 >> v2;
			if(v1==-1 || v2==-1) {
				break;
			}
			g.adcAresta(v1,v2);
		}

		if(g.checaEuler() == 0) {
			cout << "Grafo não euleriano." << endl;
		} else if (g.checaEuler() == 1) {
			cout << "Grafo possui um caminho euleriano." << endl;
		} else if (g.checaEuler() == 2) {
			cout << "Grafo possui um ciclo euleriano." << endl;
		}

		break;
	}

	case 2: {

		fstream infile;
		infile.open("grafo.txt", ios::in);
		if(!infile.is_open()) {
			cout << "ERRO AO ABRIR ARQUIVO: NENHUM ENCONTRADO." << endl << endl;
			break;
		}

		int auxVal = 0, v1, v2;
		string ch;
		char carac;

		getline(infile, ch);
		auxVal = atoi(&ch.front());
		Grafo g(auxVal);

		for(unsigned int count = 2; count<=ch.length(); count=count+4) {
			carac = ch[count];
			v1 = atoi(&carac);
			carac = ch[count+2];
			v2 = atoi(&carac);
			g.adcAresta(v1,v2);
		}

		if(g.checaEuler() == 0) {
			cout << "Grafo não euleriano." << endl;
		} else if (g.checaEuler() == 1) {
			cout << "Grafo possui um caminho euleriano." << endl;
		} else if (g.checaEuler() == 2) {
			cout << "Grafo possui um ciclo euleriano." << endl;
		}

		break;
	}

	default: {
		cout << "Opcao invalida, tente novamente." << endl << endl;
		break;
	}
	}

	return 0;
}

#include <iostream>
#include <list>
#include <fstream>
using namespace std;

class Grafo {

int numVert;
list<int> *adjM;
bool *visitado;

public: // Funcoes gerais. Nao foi feita remocao por ser um executavel de unica instancia.
Grafo(int V);
void addAresta(int org, int dest);
void DFS(int vertice);

};

Grafo::Grafo(int vert){ // Construtor do grafo
	numVert = vert;
	adjM = new list<int>[vert];
	visitado = new bool[vert];
}

void Grafo::addAresta(int org, int dest){ // Adiciona aresta de uma forma mais limpa.
	adjM[org].push_front(dest); // Para fazer um DFS invertido, push_front.
}

void Grafo::DFS(int vertice){ // DFS normal, usando booleano para verificar se houve visita no vertice.

	visitado[vertice] = true;
	list<int> adj = adjM[vertice];

	cout << vertice << " <- "; // Printa os vertices do DFS.

	list<int>::iterator i;

	for(i=adj.begin(); i!=adj.end(); i++) {
		if(!visitado[*i]) { // Realiza DFS caso o vertice em questao nao foi visitado.
			DFS(*i);
		}
	}
}

int main(int argc, char const *argv[]) {
	cout << "##### DFS - LUCAS FREITAS E YURI HENRIQUE #####" << endl;
	cout << "(1) - Inserir vertices manualmente." << endl;
	cout << "(2) - Carregar arquivo (grafo.txt)." << endl;
	cout << "(0) - Encerrar." << endl;
	cout << "OPC: ";
	int menuOPC;
	cin >> menuOPC;


	switch(menuOPC) {

	case 0: {
		cout << "BYE!" << endl;
		break;
	}

	case 1: {
		int vertG, vertDFS;
		cout << "Numero de arestas: ";
		cin >> vertG;
		Grafo g(vertG); // Instancia um grafo somente apos inserido seu numero de vertices.

		cout << "Insira as arestas, no formato 'origem destino': " << endl;
		cout << "Para encerrar as inserções, utilize -1 -1." << endl;
		int org=0, dest=0;
		while(true) { // Vai inserindo arestas ate a condicao de parada.
			cin >> org >> dest;
			if(org<0 && dest<0) {
				break;
			}
			g.addAresta(org, dest);
		}

		cout << "Insira o vertice para DFS: ";
		cin >> vertDFS;
		g.DFS(vertDFS); // Faz o DFS a partir de um certo vertice.
		break;
	}

	case 2: {

		fstream infile;
		infile.open("grafo.txt", ios::in);
		if(!infile.is_open()) {
			cout << "ERRO AO ABRIR ARQUIVO: NENHUM ENCONTRADO." << endl << endl;
			break;
		}

		int grafoTam=0, auxVal=0, contador=0, v1, v2;
		string ch, vertConectado;
		char carac;
		while(!infile.eof()) {
			getline(infile, ch);
			auxVal = atoi(&ch.front());

			if(auxVal > grafoTam) {
				grafoTam = auxVal;
			}
		}
		grafoTam++; // Para arquivo, o grafo ta estourando a memoria. Adicionar mais um espaco para vertice corrige o problema.

		Grafo g(grafoTam);

		infile.clear();
		infile.seekg(0);

		while(!infile.eof()) {

			getline(infile, ch);
			v1 = contador;
			for(unsigned int count = 3; count<=ch.length(); count++) { // Le a linha a partir do terceiro caractere, onde existe conectividade.
				if(ch[count] <= '9' && ch[count] >= '0') { // Se for numerico, carac recebe o caractere, e converte para inteiro.
					carac = ch[count];
					v2 = atoi(&carac);
					g.addAresta(v1,v2);
				}
			}

			if(contador == grafoTam) { // Quando o contador alcancar a quantidade de vertices instanciados, roda DFS.
				int dfsArq;
				cout << "DFS : ";
				cin >> dfsArq;
				g.DFS(dfsArq);
			}
			contador++;

		}

		grafoTam--; // Corrige quantidade de vertices.
		infile.close(); // Fecha o arquivo.
		break;
	}

	default: {
		cout << "ERRO: Opcao invalida, tente novamente." << endl << endl;
	}
	}

	return 0;
}

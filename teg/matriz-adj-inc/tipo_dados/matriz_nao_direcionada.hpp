#ifndef _MATRIZ_NAO_DIRECIONADA_NAO_INCLUIDO_
#define _MATRIZ_NAO_DIRECIONADA_NAO_INCLUIDO_

class Matriz_Nao_Direcionada : public Dados { // Matriz é filha de dados
protected:
int qtd_nos;
int qtd_vertices;
std::vector<int> adjacencia; // a matriz é representada como um vetor de 1 dimenção, para acessar qualquer elemento de uma matriz NxN utiliza-se o indice [i*N+j]. Ex: matrix 2x2 , formula: [i*2+j].
std::vector<int> incidencia;

public:

Matriz_Nao_Direcionada(){ // método construtor
	qtd_nos = 0;
	qtd_vertices = 0;
	nome = "Matriz de Adjacencia e Incidencia (Nao direcionado)";
}

~Matriz_Nao_Direcionada(){ //método destrutor
}

void constroiDados(std::vector<std::vector<int> > entrada){
	qtd_nos = entrada.size();
	adjacencia.resize(qtd_nos * qtd_nos); //cria o espaço para a matriz NxN
	for(int i=0; i < qtd_nos; i++) {
		if(entrada[i].size()>1)
			qtd_vertices += (entrada[i].size()-1);
		for(int j=1; j < entrada[i].size(); j++) {
			++adjacencia[i * qtd_nos + entrada[i][j]];
			if(entrada[i][0] != entrada[i][j]) {
				++adjacencia[entrada[i][j] * qtd_nos + i];
			}
		}
	}
	incidencia.resize(qtd_vertices * qtd_nos);
	int vertice_atual = 0, temp = 0;;
	for(int i = 0; i < qtd_nos; i++) {
		for(int j = i; j < qtd_nos; j++) {
			temp = adjacencia[i * qtd_nos + j];
			while(temp > 0 ) {
				incidencia[vertice_atual * qtd_nos + i] = 1;
				incidencia[vertice_atual * qtd_nos + j] = 1;
				++vertice_atual;
				--temp;
			}
		}
	}
}

void inserirVertice(int src, int dst){
	if(src <= qtd_nos || dst <= qtd_nos) {
		std::cout<<"No desejado invalido\n";
	}
	++adjacencia[src * qtd_nos + dst];

	++qtd_vertices;
	incidencia.resize(qtd_vertices * qtd_nos);
	incidencia[(qtd_vertices-1) * qtd_nos + src] = 1;
	incidencia[(qtd_vertices-1) * qtd_nos + dst] = 1;
}

void removerVertice(int src,int dst){
	if(adjacencia[src * qtd_nos + dst] == 0 ) {
		std::cout<<"Não existem vértices entre "<<src<<" e "<<dst<<"\n";
		return;
	}
	if(src <= qtd_nos || dst <= qtd_nos) {
		std::cout<<"No desejado invalido\n";
	}

	//Troca o src e o dst, caso o maior valor entre eles deve ser SEMPRE armazenado no dst e o menor em src.
	int temp = src;
	if(src > dst) {
		src = dst;
		dst = temp;
	}

	--adjacencia[src * qtd_nos + dst];
	if(src != dst) {
		--adjacencia[dst * qtd_nos + src];

		for(int vertice_atual = 0; vertice_atual < qtd_vertices; vertice_atual++) {
			if(incidencia[vertice_atual * qtd_nos + src] == 1 && incidencia[vertice_atual * qtd_nos + dst] == 1) {
				incidencia.erase(incidencia.begin()+(vertice_atual * qtd_nos),incidencia.begin()+((vertice_atual+1) * qtd_nos));
				break;
			}
		}
	}else{
		bool linha_valida;
		for(int vertice_atual = 0; vertice_atual < qtd_vertices; vertice_atual++) {
			linha_valida = true;
			for(int j = 0; j < qtd_nos; j++) {
				if(incidencia[vertice_atual * qtd_nos + j] != 0 && src != j ) {
					linha_valida = false;
					break;
				}
			}
			if(linha_valida) {
				incidencia.erase(incidencia.begin()+(vertice_atual * qtd_nos),incidencia.begin()+((vertice_atual+1) * qtd_nos));
				break;
			}
		}
	}
	--qtd_vertices;
}

void calculaGrau(int no){
	int qtd_grau=0;
	for ( int j = 0; j < qtd_vertices; j++) {
		qtd_grau +=incidencia[j*qtd_nos+no];
	}
	qtd_grau/=2;
	printf("O grau do no %d e igual a: %d\n",no,qtd_grau);
}

void geraComplemento(){
	int vertice_atual=0;
	std::vector<int> complemento;
	complemento.resize(qtd_nos * qtd_nos);
	for (vertice_atual = 0; vertice_atual < adjacencia.size(); vertice_atual++) {
		if (adjacencia[vertice_atual] > 0) complemento[vertice_atual] = 0;
		else complemento[vertice_atual] = 1;
	}
	printf("O Complemento do grafo por matriz de Adjacencia:\n");
	std::cout<<" Matriz de Complemento do grafo\n";
	if(!complemento.empty()) {
		for(int i = 0; i < qtd_nos; i++) {
			for(int j = 0; j< qtd_nos; j++) {
				if(i <= j )
					std::cout<< std::setw(3) << std::setfill(' ') << complemento[i*qtd_nos+j]<<" ";
				else
					std::cout<< std::setw(4) << std::setfill(' ')<<" ";
			}
			std::cout<<"\n";
		}
	}else{
		std::cout<<"Vazia\n";
	}
}

void mostrarDados(){
	std::cout<<"Matriz de Adjacencia\n";
	if(!adjacencia.empty()) {
		for(int i = 0; i < qtd_nos; i++) {
			for(int j = 0; j< qtd_nos; j++) {
				if(i <= j )
					std::cout<< std::setw(3) << std::setfill(' ') << adjacencia[i*qtd_nos+j]<<" ";
				else
					std::cout<< std::setw(4) << std::setfill(' ')<<" ";
			}
			std::cout<<"\n";
		}
	}else{
		std::cout<<"Vazia\n";
	}
	std::cout<<"-------------------------\n";
	std::cout<<"Matriz de Incidencia\n";
	if(!incidencia.empty()) {
		for(int i = 0; i < qtd_vertices; i++) {
			for(int j = 0; j< qtd_nos; j++) {
				std::cout<< std::setw(3) << std::setfill(' ') << incidencia[i * qtd_nos + j]<<" ";
				std::cout<< std::setw(3) << std::setfill(' ');
			}
			std::cout<<"\n";
		}
	}else{
		std::cout<<"Vazia\n";
	}
}

std::string getNome(){
	return this->nome;
}

};

#endif

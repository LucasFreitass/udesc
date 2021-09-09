#ifndef _LISTA_ADJACENCIA_ND_
#define _LISTA_ADJACENCIA_ND_

class Lista_Adjacencia_ND : public Dados {     // Matriz é filha de dados
private:
std::vector<std::vector<int> >listaADJ;

public:

Lista_Adjacencia_ND(){         // método construtor
	nome = "Lista Adjacencia Nao Direcionada";
}

~Lista_Adjacencia_ND(){         //método destrutor
}

void constroiDados(std::vector<std::vector<int> > entrada){
	listaADJ = entrada;
}


void inserirVertice(int src, int dst){

	listaADJ[src].push_back(dst);
	listaADJ[dst].push_back(src);
}

void removerVertice(int src,int dst){
	int i;
	if (!listaADJ.empty()) {
		for (i = 1; i < listaADJ[src].size(); i++) {
			if (dst == listaADJ[src][i]) {
				break;
			}
		}
		listaADJ[src].erase(listaADJ[src].begin()+i);

		for (i = 1; i < listaADJ[dst].size(); i++) {
			if (src == listaADJ[dst][i]) {
				break;
			}
		}
		listaADJ[dst].erase(listaADJ[dst].begin()+i);
	}
	else printf("A lista esta vazia\n");
}


void calculaGrau(int no){
	std::cout << "O grau do no "<<no<<" e igual a: "<<listaADJ[no].size()-1<< '\n';
}

void geraComplemento(){
	std::cout<<"Funcao nao implementada para esta estrutura\n";
}

void mostrarDados(){
	int i, j;
	std::cout<<"Lista de Adjacencia nao direcionada\n";
	if(!listaADJ.empty()) {
		for(i = 0; i < listaADJ.size(); i++) {
			for (j = 0; j < listaADJ[i].size(); j++) {
				std::cout<<listaADJ[i][j]<<" ";
			}
			std::cout<<"\n";
		}
	}
	else std::cout<<"A lista esta vazia!\n";
}


std::string getNome(){
	return this->nome;
}

};
#endif

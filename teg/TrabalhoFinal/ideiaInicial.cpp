#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <iterator>

// Struct contendo todos os dados que serao usados nas arestas
// Um trecho é composto pelo numero de voo, saia e chegada, preço e reservas, trechos_t para entender que trechos é um tipo de dados.
typedef struct trechos_t {
	int numero_voo;
	std::string chegada; // sao string pq sao horas, formato - 11:30, 14:20 etc ..
	std::string destino;
	float preco;
	int reservas;
} trechos_t;

// ostream é uma " funcao do c++ para saidas ", usada para conseguir juntar o valor das variaveis com a parte escrita ..
//
std::ostream& operator<<(std::ostream& os,  const trechos_t &t){
	return os<<"(Voo número: "<<t.numero_voo<<";chegada: "<<t.chegada<<"; destino: "<<t.destino<<";preco: "<<t.preco<<";reservas: "<<t.reservas<<")";
}
//
struct Graph {
	//cria um dicionario das origens, destinos mostrando todos os trechos
	std::map<std::string, std::map<std::string, std::vector<trechos_t> > > g;

	// Construtor falta implementar
	Graph()  {
	}

	// Essa função serve para adicionar uma aresta
	// Eu passo para funcao o nome de origem e destino, e um trecho (que seria todas as informações que estao na struct)
	void adicionaTrecho(std::string origem, std::string destino, trechos_t trecho)  { // AQUI JÁ É MONTADA A LISTA DIRECIONADA
		g[origem][destino].push_back(trecho);
	}
// Funcao para printar e poder ver como tudo esta funcionando agora ..
	void print(){
		for(auto const & it: g) {
			std::cout<<"Origem: "<<it.first;
			for(auto const &it2: it.second) {
				std::cout<<"| Destino: "<<it2.first<<" [";
				for(auto const &it3: it2.second) {
					std::cout<< it3;
				}
				std::cout<<"]\n";
			}
		}
	}



	// Aqui fica a chamada da funcao que tem a  implementação do Dijkstra
	int dijkstra();
};

int Graph::dijkstra(){
	//Codigo vai aqui
	return 0;
}

int main() {
	// fazer ele ler do arquivo ..
	//Le o arquivo
	// leArquivo();

	// declaração das coisas, basico!
	Graph graph; // grafo que guarda, manipula os trechos ja com as cidades
	trechos_t t; // aqui é so o trecho
	// dando valores apenas para adicionar e ir testando oq foi lido ..
	t.numero_voo = 1;
	t.chegada= "10:00";
	t.destino="9:00";
	t.preco=12;
	t.reservas=100;
	graph.adicionaTrecho("SP","RJ",t);

	t.numero_voo = 2;
	t.chegada= "14:50";
	t.destino="12:00";
	t.preco=10;
	t.reservas=1;
	graph.adicionaTrecho("RJ","NATAL",t);

	t.numero_voo = 3;
	t.chegada= "14:50";
	t.destino="12:00";
	t.preco=10;
	t.reservas=1;
	graph.adicionaTrecho("SP","RJ",t);

	graph.print();

	// PSEUDO ROTEIRO, DOQ TALVEZ TENHA Q FAZER ..

	//Montar o grafo (fazer um loop para todos os dados que tu leu do arquivo e inserir na estrutura)
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

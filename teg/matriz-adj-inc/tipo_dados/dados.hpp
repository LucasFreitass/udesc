#ifndef _DADOS_NAO_INCLUIDO_
#define _DADOS_NAO_INCLUIDO_

#include <cstdlib>
#include <cstdio>

class Dados {
protected:
int n; // qtd_elementos
std::string nome;
public:

//Duvidas -  http://programadoraprendendo.blogspot.com/2013/02/c-o-que-sao-metodos-virtuais.html
virtual ~Dados() = 0; //função puramente virtual
virtual void constroiDados(std::vector<std::vector<int> > entrada) = 0;
virtual void inserirVertice(int,int) = 0;
virtual void removerVertice(int,int) = 0;
virtual void calculaGrau(int) = 0;
virtual void geraComplemento() = 0;

virtual void mostrarDados() = 0;

virtual std::string getNome() = 0;

void menuDados(){
	unsigned int opc = 1;
	while(opc!=0) {
		std::cout<< std::setw(100) << std::setfill('-')<<"\n";
		std::string title = "menu dados "+ this->getNome()+"\n";
		std::cout<< std::setw(100) << std::setfill('-')<<title;
		std::cout<< std::setw(100) << std::setfill('-')<<"\n";
		printf("1: inserir vertice\n");
		printf("2: remover vertice\n");
		printf("3: calcula grau no\n");
		printf("4: gera complemento\n");
		printf("5: mostrar dados\n");
		printf("0: Sair\n");
		std::cout<< std::setw(100) << std::setfill('-')<<"\n";
		printf("::>");
		scanf("%u",&opc);
		system("clear");
		switch(opc) {
		case 1:
		{
			int i,j;
			printf("Digite os nos para inserir o vertice\n");
			scanf("%d %d",&i, &j);
			inserirVertice(i,j);
			break;
		}
		case 2:
		{
			int i,j;
			printf("Digite os nos para remover o vertice\n");
			scanf("%d %d",&i, &j);
			removerVertice(i,j);
			break;
		}
		case 3:
		{
			int i;
			printf("Digite os nos para calcular o grau\n");
			scanf("%d",&i);
			calculaGrau(i);
			break;
		}
		case 4:
			geraComplemento();
			break;
		case 5:
			mostrarDados();
			break;
		case 0:
			printf("Saindo do menu dos dados\n");
			break;
		default:
			printf("Valor invalido\n");
			break;

		}
		std::cout<< std::setw(100) << std::setfill('-') << "\n";
		std::cout<<"Digite algo para continuar\n";
		getchar();
		getchar();
		system("clear");
	}
}

};

inline Dados::~Dados(){ // destrutor da classe
}

#endif

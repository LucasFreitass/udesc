#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <string>
#include <cstdlib>

#include "tipo_dados/dados.hpp"
#include "tipo_dados/matriz_nao_direcionada.hpp"
#include "leitor.hpp"

int main () {
	std::vector<std::vector<int> > entrada = LeituraArquivo();
	system("clear");

	Dados *dados;
	// Grafo *grafo;

	unsigned int opc = 1;
	while(opc!=0) {

		printf("--------------------------------------\n");
		printf("------------MENU GERAL----------------\n");
		printf("--------------------------------------\n");
		printf("1: Implementação 1 - Matriz Adjacencia e Incidencia(Nao direcionado)\n");
		printf("2: Implementação 1.2 - Matriz Adjacencia e Incidencia(Direcionado)\n");
		printf("3: Implementação 2 - Lista e Vetores\n");
		printf("4: --\n");
		printf("5: --\n");
		printf("6: --\n");
		printf("0: Sair\n");
		printf("--------------------------------------\n");             printf("::>");
		scanf("%u",&opc);
		system("clear");
		switch (opc) {
		case 1: //matriz de adjacencia
			dados = new Matriz_Nao_Direcionada();
			dados->constroiDados(entrada);
			dados->menuDados();
			break;
		case 0:
			printf("Falou\n");
			break;
		default:
			printf("Valor invalido\n");
			break;
		}
	}

	return 0;
}

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <string>

void LeituraArquivo ( ) {

	std::ifstream EntradaArquivo;
	EntradaArquivo.open("entradaTeste.txt");
	if (!EntradaArquivo) {
		std::cerr <<"entradaTeste.txt"; // essa parada é saida padrao para erros
	}
	while (true) {
		std::string linha; // criando uma string para ver as linhas.
		std::getline(EntradaArquivo, linha); // funcao para pegar toda a linhas
		if (linha.empty()) {
			break;
		}
		std::istringstream MinhaLinha(linha); // criando uma classe
		std::istream_iterator<int> begin(MinhaLinha), eof;// criando um iterador tipo inteiro, e falando q ele vai iterar na minhaLinha, ate o final ( eof )
		std::vector<int> numeros(begin, eof); // declarando um vetor do tipo inteiro q vai do inicio ao fim, nome dele e numeros
		std::copy(numeros.begin(), numeros.end(), std::ostream_iterator<int>(std::cout," ")); // isso tudo para printar
		std::cout << '\n'; // em copy eu copio do inicio ate o fim para ostream_iterator e printo.
	}
}


int main () {
	LeituraArquivo();
	return 0;
}

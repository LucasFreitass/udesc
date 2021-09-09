#ifndef _LEITOR_NAO_INCLUIDO_
#define _LEITOR_NAO_INCLUIDO_

std::vector<std::vector<int> > LeituraArquivo () {
	std::string teste;
	std::cout<<"Digite o nome do teste\n::>";
	std::cin>>teste;

	if(teste=="1")
		teste="defaultTeste";

	std::ifstream EntradaArquivo;
	EntradaArquivo.open("testes/"+teste+".txt");

	if (!EntradaArquivo) {
		std::cerr <<"entradaTeste.txt"; // essa parada é saida padrao para erros
	}
	std::vector<std::vector<int> > entrada;
	while (true) {
		std::string linha; // criando uma string para ver as linhas.
		std::getline(EntradaArquivo, linha); // funcao para pegar toda a linhas
		if (linha.empty()) {
			break;
		}
		std::istringstream MinhaLinha(linha); // criando uma classe
		std::istream_iterator<int> begin(MinhaLinha), eof;// criando um iterador tipo inteiro, e falando q ele vai iterar na minhaLinha, ate o final ( eof )
		std::vector<int> numeros(begin, eof); // declarando um vetor do tipo inteiro q vai do inicio ao fim, nome dele e numeros
		entrada.push_back(numeros);
	}
	return entrada;
}

#endif

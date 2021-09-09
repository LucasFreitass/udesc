/*
@authors Lucas Eduardo Rosa de Freitas
@authors Lucas Matheus Camilo  
*/ 

#include <iostream>
#include <cstdlib>

#include "rsa.hpp"

// Para gerar aquivos de texto grandes 
// https://www.lipsum.com/feed/html

void menu(RSA *rsa) {
    unsigned int opcao = 0;
    while(true){
        std::cout << "Digite uma opção\n";
        std::cout << "1- Criptografar arquivo\n";
        std::cout << "2- Descriptografar arquivo\n";
        std::cout << "3- Usar Bruteforce no arquivo\n";
        std::cout << "4- Usar Bruteforce com heurística no arquivo\n";
        std::cout << "5- Comparar os arquivos resultantes\n";
        std::cout << "6- Executar captura de tempos\n";
        std::cout << "0- Sair\n";
        std::cout << "::> ";

        std::cin >> opcao;

        if(opcao == 1) {
            rsa->criptografarArquivo();
        } else if (opcao == 2) {
            rsa->descriptografarArquivo();
        } else if (opcao == 3) {
            rsa->bruteForce();
        } else if (opcao == 4) {
            rsa->bruteForceHeuristica();
        } else if (opcao == 5) {
            rsa->verificaArquivos();
        } else if (opcao == 6) {
            rsa->capturaTempo();
        } else if (opcao == 0) {
            break;
        } else {
            std::cout << "Opcao desconhecida\n";
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout<<"É necessário somente 1 argumento (quantidade bits)\n";
        exit(1);
    }
    RSA *rsa = new RSA(atoi(argv[1]));

    menu(rsa);
}
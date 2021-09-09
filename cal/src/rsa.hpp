/*
@authors Lucas Eduardo Rosa de Freitas
@authors Lucas Matheus Camilo  
*/ 

#ifndef _RSA_NOT_INCLUDED_
#define _RSA_NOT_INCLUDED_

#include <iostream>
#include <fstream> 
#include <string>
#include <random>
#include <cmath>
#include <utility>
#include <chrono>

#include <gmpxx.h>

typedef struct {
    std::pair<mpz_class, mpz_class> publica;
    std::pair<mpz_class, mpz_class> privada;
} ParChaves;

class RSA {
    private: 
        static gmp_randclass *gerador_rand;
        mpz_class p, q;
        unsigned int bits;

        ParChaves chaves;

        bool millerRabin(const mpz_class, const size_t);

        void setChaves();
    public:
        RSA(unsigned int);
        ~RSA();

        mpz_class gcd(mpz_class, mpz_class);
        mpz_class egcd(mpz_class, mpz_class);
        mpz_class inversoModular(mpz_class, mpz_class);

        mpz_class exponenciacaoModular(const mpz_class, const mpz_class, const mpz_class);
        mpz_class gera_big_rand();

        void criptografarArquivo();
        void descriptografarArquivo(std::string dfile="descriptografado.txt");

        void verificaArquivos();
        
        void bruteForce();
        void bruteForceHeuristica();
        void breakFile(mpz_class, std::string);

        void capturaTempo();
};

#endif
#ifndef _GRAFO_NAO_INCLUIDO_
#define _GRAFO_NAO_INCLUIDO_

#include "../tipo_dados/dados.hpp"

class Grafo {
protected:
Dados *dados;

public:

virtual ~Grafo() = 0; //função pure virtual

virtual void constroiGrafo(std::vector<std::vector<int> > entrada) = 0;
virtual void executar() = 0;

};

inline Grafo::~Grafo(){
}

#endif

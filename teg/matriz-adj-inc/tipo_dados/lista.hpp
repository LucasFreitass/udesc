#ifndef _GRAFO_NAO_INCLUIDO_
#define _GRAFO_NAO_INCLUIDO_

class dados {
protected:
int qtd; // qtd_elementos

public:

virtual ~dados() = 0; //função pure virtual
virtual void constroiGrafo(std::vector<std::vector<int> > entrada) = 0;

};

inline dados::~dados(){ // destrutor da classe
}

#endif

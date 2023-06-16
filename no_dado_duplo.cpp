//no_dado.cpp
#include "no_dado_duplo.h"

no_dado_duplo::no_dado_duplo(){ //Construtor - inicializar atributos em NULL
	this->info = 0;
	this->prox = 0; //NULL
	this->ant = 0; //NULL
}

no_dado_duplo::no_dado_duplo(int x, no_dado_duplo* ptr){ //construtor com passagem de parâmetros	
	this->info = x;
	this->prox = ptr;
}

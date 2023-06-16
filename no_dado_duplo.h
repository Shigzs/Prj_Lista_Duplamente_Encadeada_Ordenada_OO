//no_dado_duplo.h

class no_dado_duplo{
	//Declarar atributos
	public:
		int info;
		no_dado_duplo* prox; 
		no_dado_duplo* ant; 
	
	//Declara métodos
	public:
		no_dado_duplo(); //construtor sem passagem de parâmetros
		no_dado_duplo(int x, no_dado_duplo* ptr); //construtor com passagem de parâmetros				
};

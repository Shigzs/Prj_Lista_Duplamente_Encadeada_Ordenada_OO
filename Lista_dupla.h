//Lista.h
#include <stdlib.h>
#include <iostream>
#include <locale.h>
#include "no_dado_duplo.h"
using namespace std;


class Lista_dupla{
	private:
		no_dado_duplo* cabeca; //controla a lista (nó-cabeça)
		int qtd; //guarda a qtd de nós na lista
	
	public:
		Lista_dupla(); //Construtor - inicializar a lista em NULL
		~Lista_dupla(); //Destrutor - invocar método libera
		void insere_ordenado(int i); //Inserir dado i no início da Lista
		void imprime(); //Imprime a lista do início para o fim
		bool vazia(); //retornar bool se lista é vazia
		bool busca(int i); //Busca i na Lista, retornando bool
		bool retira(int i); //Remove 1a ocorrência de i, retornando true caso encontre
		int tamanho(); //Retorna a qtd de nós na lista
		void libera(); //Libera a lista
		bool remove_inicio();
		bool remove_fim();
		void imprime_invertido();
	private:
		bool isEmpty(no_dado_duplo* l); //Método privado que auxiliará verificação de lista vazia a partir de dada referência	
};

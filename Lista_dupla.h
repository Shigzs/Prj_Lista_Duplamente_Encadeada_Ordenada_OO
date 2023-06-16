//Lista.h
#include <stdlib.h>
#include <iostream>
#include <locale.h>
#include "no_dado_duplo.h"
using namespace std;


class Lista_dupla{
	private:
		no_dado_duplo* cabeca; //controla a lista (n�-cabe�a)
		int qtd; //guarda a qtd de n�s na lista
	
	public:
		Lista_dupla(); //Construtor - inicializar a lista em NULL
		~Lista_dupla(); //Destrutor - invocar m�todo libera
		void insere_ordenado(int i); //Inserir dado i no in�cio da Lista
		void imprime(); //Imprime a lista do in�cio para o fim
		bool vazia(); //retornar bool se lista � vazia
		bool busca(int i); //Busca i na Lista, retornando bool
		bool retira(int i); //Remove 1a ocorr�ncia de i, retornando true caso encontre
		int tamanho(); //Retorna a qtd de n�s na lista
		void libera(); //Libera a lista
		bool remove_inicio();
		bool remove_fim();
		void imprime_invertido();
	private:
		bool isEmpty(no_dado_duplo* l); //M�todo privado que auxiliar� verifica��o de lista vazia a partir de dada refer�ncia	
};

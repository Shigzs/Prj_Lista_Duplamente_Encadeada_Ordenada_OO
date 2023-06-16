#include "Lista_dupla.h"

Lista_dupla::Lista_dupla(){ //Construtor - inicializar a lista em NULL
	this->cabeca = 0; //inicializa a lista vazia, mesmo que NULL
	this->qtd = 0;
}

Lista_dupla::~Lista_dupla(){ //Destrutor - invocar m�todo libera
	libera();
}

void Lista_dupla::insere_ordenado(int i){
	no_dado_duplo* p; 
	no_dado_duplo* novo = new no_dado_duplo(i, this->cabeca); 
	
	if(!isEmpty(this->cabeca)){
			
		if(this->cabeca->info >= novo->info){ // verifica ser a cabeca � maior que o novo
			this->cabeca->ant = novo;
			novo->prox = this->cabeca;
			this->cabeca = novo;
			this->qtd++; // se for, a info vai ser inserida atr�s da cabeca, e vai ser a nova cabeca
			
		} else { // se a cabeca for menor que a info
			p = this->cabeca;
			
			for (; p->prox != NULL && p->prox->info < novo->info; p = p->prox); // percorre a lista pra encontrar a posicao
			novo->prox = p->prox;
			
			if(p->prox != NULL){
				novo->prox->ant = novo;
			}
			p->prox = novo;
			novo->ant = p;
		}
			
		
	} else { // se for vazia cria um novo do e aponta ant e prox para null
		novo->prox = NULL;
		novo->ant = NULL;
		this->cabeca = novo;
	}
	this->qtd++;	
}

void Lista_dupla::imprime(){ //Imprime a lista do in�cio para o fim
	if(!isEmpty(this->cabeca)){
		no_dado_duplo* p = this->cabeca; /* vari�vel auxiliar para percorrer a lista */
 		cout << "Info: ";
		while(p != NULL){
			cout << p->info << " - ";
			p = p->prox;
		}
		cout << endl;
	} else {
		cout << "Lista � vazia!" << endl;
	}
}

bool Lista_dupla::vazia(){ //True se lista � vazia, false caso contr�rio
	return isEmpty(this->cabeca);
}

bool Lista_dupla::busca(int i){
	if(!isEmpty(this->cabeca)){
		no_dado_duplo* p = this->cabeca; /* ponteiro para percorrer a lista*/
		while (p->prox != NULL && p->info != i) {
			p = p->prox;
		}
		if(p->info == i)
			return 1;
		return 0;	
	}else {
		cout << "Lista � vazia!" << endl;
	}
}

bool Lista_dupla::retira(int i){
	no_dado_duplo* ant = NULL; /* ponteiro para elemento anterior */
	no_dado_duplo* p = this->cabeca; /* ponteiro para percorrer a lista*/
	/* procura elemento na lista, guardando anterior */
	while (p != NULL && p->info != i) {
		ant = p;
		p = p->prox;
	}
	/* verifica se achou elemento */
	/* caso n�o achou, retorne false */
	if (p == NULL)
		return 0; //false
 	
	/* sen�o, achou elemento para retirar e retorne true*/
	if (ant == NULL) { /* retira elemento do inicio */
		this->cabeca = p->prox;
		this->cabeca->ant = NULL;
	}
 	else { /* retira elemento do meio da lista */
		ant->prox = p->prox;
		p->prox->ant = ant;
	}
	free(p); //desaloca o n�-dado
	this->qtd--; //decrementa o contador de no-dados da lista
	return 1; //true
}

int Lista_dupla::tamanho(){ //Retorna a qtd de n�s na lista
	return this->qtd;
}

void Lista_dupla::libera(){ //Libera a lista
	no_dado_duplo* p = this->cabeca;
 	while (p != NULL) {
 		no_dado_duplo* t = p->prox; /* guarda refer�ncia para o pr�ximo elemento*/
 		free(p); /* libera a mem�ria apontada por p */
 		p = t; /* faz p apontar para o pr�ximo */
	}
	this->qtd = 0;
	this->cabeca = 0;
}

bool Lista_dupla::remove_inicio(){
	if(!isEmpty(this->cabeca)){
		no_dado_duplo* p = this->cabeca;
		this->cabeca = p->prox;
		free(p);
	}else{
		cout << "Lista � vazia!" << endl;
	}
}
bool Lista_dupla::remove_fim(){
	if(!isEmpty(this->cabeca)){
		no_dado_duplo* p = this->cabeca;
		do{
			p = p->prox;
		}while(p->prox != NULL);
		p->ant->prox = NULL;
		free(p);
	}else{
		cout << "Lista � vazia!" << endl;
	}
}

void Lista_dupla::imprime_invertido(){
	if(!isEmpty(this->cabeca)){
		no_dado_duplo* p = this->cabeca; /* vari�vel auxiliar para percorrer a lista */
 		cout << "Info: ";
 		do{
			p = p->prox;
		}while(p->prox != NULL);
		while(p != NULL){
			cout << p->info << " - ";
			p = p->ant;
		}
		cout << endl;
	} else {
		cout << "Lista � vazia!" << endl;
	}
}

bool Lista_dupla::isEmpty(no_dado_duplo* l){ //M�todo privado que auxiliar� verifica��o de lista vazia a partir de dada refer�ncia	
	return l==NULL;
}

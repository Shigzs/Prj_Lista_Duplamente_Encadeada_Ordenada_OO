#include "Lista_dupla.h"

void menu(){
	cout << "1 - Imprimir lista" << endl;
	cout << "2 - Inserir ordenado" << endl;
	cout << "3 - Verificar se a lista é vazia" << endl;
	cout << "4 - Imprimir o tamanho da lista" << endl;
	cout << "5 - Liberar Lista" << endl;
	cout << "6 - Destruir lista" << endl;
	cout << "7 - Remover um valor da lista" << endl;
	cout << "8 - Remover o primeiro nó dado da lista" << endl;
	cout << "9 - Remover o último nó dado da lista" << endl;
	cout << "10 - Imprimir lista invertida" << endl;
	cout << "11 - Buscar elemento" << endl;
	//cout << "12 - Imprimir primeiro item da lista" << endl;
	//cout << "13 - Imprimir ultimo item da lista" << endl;
	cout << "Escolha uma opção:  ";
}
void print_tamanho(int t){
	cout << "Tamanho da Lista: " << t << endl;	
}

void print_retira(bool x){
	if (x)
		cout << "Dado removido com sucesso da lista!" << endl;
	else	
		cout << "Dado não encontrado na lista!" << endl;
}

void print_retira_inicio(bool x){
	if (x)
		cout << "Dado removido com sucesso da lista!" << endl;
	else	
		cout << "Lista Vazia" << endl;
}

void print_retira_fim(bool x){
	if (x)
		cout << "Dado removido com sucesso da lista!" << endl;
	else	
		cout << "Lista Vazia" << endl;
}

void print_vazia(bool x){
	if (x)
		cout << "Lista vazia!" << endl;
	else	
		cout << "Lista não vazia!" << endl;
}

void print_busca(bool x){
	if (x)
		cout << "Dado encontrado!" << endl;
	else	
		cout << "Dado não encontrado!" << endl;
}

int main(int argc, char** argv) {
	setlocale(LC_ALL, "");

	cout << "PROGRAMA DUPLAMNETE ENCADEADA ORDENADA" << endl;
	int i,x;
	Lista_dupla l; //instanciando o objeto l conforme a classe Lista
	
	do{
		cout << endl << "=========================================================" << endl << endl;
		menu();
		cin >> i;
		switch(i){
			case 1:  //Imprime
				l.imprime();
				break;
			case 2: //Inserir ordenado
				cout << "Digite o valor a ser inserido: " << endl;
				cin >> x;
				l.insere_ordenado(x);
				break;
			case 3: //Vazia
				print_vazia(l.vazia());
				break;
			case 4:  //Tamanho
				print_tamanho(l.tamanho());
				break;
			case 5: // Liberar Lista (libera)
				l.libera();
				cout << "Lista liberada!!" << endl;
				break;
			case 6: //Destruir Lista (Destrutor)
				l.~Lista_dupla();
				cout << "Lista Destruída!!" << endl;
				break;
			case 7: //Remover um valor da lista
				cout << "Digite o valor a ser removido: " << endl;
				cin >> x;
				print_retira(l.retira(x));
				break;
			case 8: //Remove inicio
				print_retira_inicio(l.remove_inicio());
				break;
			case 9: //Remover fim
				print_retira_fim(l.remove_fim());
				break;
			case 10:  //Imprime invertido
				l.imprime_invertido();
				break;
			case 11:  //Imprime invertido
				cout << "Digite o valor a ser buscado: " << endl;
				cin >> x;
				print_busca(l.busca(x));
				break;
			default:
				cout << "A opção inserida é inválida!!" << endl;
				break;
		}
	}while(i!=0);
	return 0;
}

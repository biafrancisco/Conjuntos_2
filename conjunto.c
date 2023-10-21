// Arquivo conjunto.c
// Declara as funcoes definidas no arquivo conjunto.h

/* Colocar as bibliotecas necessárias aqui no início */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "conjunto.h"
#include "auxiliar.h"

// Aloca memoria para um conjunto, define seu tamanho para 0 e aloca memoria para 1 elemento e retorna o endereco deste conjunto
struct conjunto *criaConj() {
	struct conjunto *c = malloc(sizeof(struct conjunto));
	if (c) {
		c->tam = 0;
		c->maxTam = 1;
		c->elementos = malloc(c->maxTam * sizeof(int));
	}
	return c;
}

// Libera a memoria alocada para o conjunto e seus elementos
void destroiConj(struct conjunto *c) {
	free(c->elementos);
	free(c);
}

// Retorna o tamanho do conjunto
int tamConj(struct conjunto *c) {
	return c->tam;
}

// Retorna 'true' para conjunto vazio ou 'false' para conjunto com pelo menos um elemento
bool conjVazio(struct conjunto *c) {
	if (tamConj(c) == 0)
		return true;
	return false;
}

// Verifica se o elemento x pertence ao conjunto C
bool pertenceConj(struct conjunto *c, int x) {
	// Realiza busca binaria no conjunto
	int result = buscaBinaria(c->elementos, tamConj(c), x);
	if (result == -1)
		return false;
	return true;
}

// Insere o elemento x ao conjunto C, caso x não exista em C
void insereConj(struct conjunto *c, int x) {
	// Verifica se o elemento 'x' pertence ao conjunto
	if (!pertenceConj(c, x)) {
		// Verifica se o espaco foi alocado
		if (c->elementos) {	
			c->elementos[tamConj(c)] = x;
			c->tam++;
			c->maxTam++;
			// Ordena o elemento que foi inserido no conjunto
			inserir(c->elementos, 0, tamConj(c) - 1);
			// Realoca memoria para mais um elemento
			int *aux = realloc(c->elementos, c->maxTam * sizeof(int));
			if (aux) 
				c->elementos = aux;
			else 
				printf("Nao foi possivel alocar mais memoria para o conjunto!\n\n");
		} else {
			printf("Nao foi possivel adicionar elemento ao conjunto!\n\n");
		}
	} else {
		printf("Elemento ja pertence ao conjunto!\n\n");
	}
}

// Remove o elemento x do conjunto C, caso ele pertenca a C
void removeConj(struct conjunto *c, int x) {
	// Verifica se o conjunto nao esta vazio
	if (!conjVazio(c)) {
		// Verifica se o elemento 'x' pertence ao conjunto 
		// Variavel result recebe a posicao do elemento
		int result = buscaBinaria(c->elementos, tamConj(c), x);
		if (result != -1) {
			// Reposiciona todos os elementos do conjunto de forma que o elemento 'x' seja removido
			for (int i = result; i < (tamConj(c) - 1); i++) 
				c->elementos[i] = c->elementos[i + 1];
			c->tam--;
			c->maxTam--;
			// Realoca memoria para menos um elemento
			int *aux = realloc(c->elementos, c->maxTam * sizeof(int));
			if (aux) 
				c->elementos = aux;
			else 
				printf("Nao foi possivel remover elemento do conjunto!");
		} else {
			printf("Elemento nao pertence ao conjunto!\n\n");
		}
	} else {
		printf("O conjunto esta vazio!\n\n");
	}
}

// Retorna conjunto uniao de tamanho alocado máximo tamConj(c1) + tamConj(c2)
struct conjunto *uniao(struct conjunto *c1, struct conjunto *c2) {
	// Cria um novo conjunto uniao 
	struct conjunto *novo = criaConj();
	// Insere no conjunto uniao, de forma ordenada, todos os elementos do conjunto c1 
	for (int i = 0; i < tamConj(c1); i++) 
		insereConj(novo, c1->elementos[i]);
	// Insere no conjunto uniao, de forma ordenada, os elementos do conjunto c2 que ainda nao pertencem ao conjunto uniao
	for (int i = 0; i < tamConj(c2); i++) 
		if (!pertenceConj(novo, c2->elementos[i]))
			insereConj(novo, c2->elementos[i]);
	// Retorna o conjunto uniao
	return novo;
}

// Retorna conjunto intersecao
struct conjunto *intersecao(struct conjunto *c1, struct conjunto *c2) {
	// Cria um novo conjunto intersecao
	struct conjunto *novo = criaConj();
	// Insere no conjunto intersecao, de forma ordenada, todos os elementos que pertecem ao conjunto c1 e c2 simultaneamente
	for (int i = 0; i < tamConj(c1); i++) 
		if (pertenceConj(c2, c1->elementos[i]))
			insereConj(novo, c1->elementos[i]);
	// Retorna o conjunto intersecao
	return novo;
}

// Imprime os elementos do conjunto
void imprimeConj(struct conjunto *c) {
	// Verifica se o conjunto nao esta vazio
	if (!conjVazio(c)) {
		printf("C = ");
		// Imprime todos os elementos
		for (int i = 0; i < tamConj(c); i++)
			printf("%d ", c->elementos[i]);
		printf("\n\n");
	} else {
		printf("O conjunto eh vazio!\n\n");
	}
}



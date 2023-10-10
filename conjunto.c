/* Colocar as bibliotecas necessárias aqui no início */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "conjunto.h"


struct conjunto *criaConj() {
	struct conjunto *c = malloc(sizeof(struct conjunto));
	if (c) {
		c->tam = 0;
		c->maxTam = 1;
		c->elementos = malloc(c->maxTam * sizeof(int));
	}
	return c;
}

void destroiConj(struct conjunto *c) {
	free(c->elementos);
	free(c);
}

// Retorna o tamanho do conjunto
int tamConj(struct conjunto *c) {
	return c->tam;
}

// Verifica se o elemento x pertence ao conjunto C
bool pertenceConj(struct conjunto *c, int x) {

}

// Insere o elemento x ao conjunto C, caso x não exista em C
void insereConj(struct conjunto *c, int x) {
	if (c->elementos) {	
		c->elementos[tamConj(c)] = x;
		c->tam++;
		c->maxTam++;
		printf("tam = %d e maxTam = %d\n", c->tam, c->maxTam);
		int *aux = realloc(c->elementos, c->maxTam * sizeof(int));
		if (aux) {
			printf("alocou\n");
			c->elementos = aux;
		} else
			printf("Nao foi possivel alocar mais memoria!\n\n");
	}
}

void removeConj(struct conjunto *c, int x) {

}

// Retorna conjunto de tamanho alocado máximo tamConj(c1) + tamConj(c2)
struct conjunto *uniao(struct conjunto *c1, struct conjunto *c2) {

}

struct conjunto *intersecao(struct conjunto *c1, struct conjunto *c2) {

}

void imprimeConj(struct conjunto *c) {
	for(int i = 0; i < tamConj(c); i++)
		printf("%d ", c->elementos[i]);
	printf("\n");
}

bool conjVazio(struct conjunto *c) {
	if (tamConj(c) == 0)
		return true;
	return false;bool conjVazio(struct conjunto *c);
}

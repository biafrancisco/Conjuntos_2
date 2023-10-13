/* Colocar as bibliotecas necessárias aqui no início */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "conjunto.h"
#include "ordenacao.h"


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
	int result = buscaBinaria(c->elementos, c->tam, x);
	if (result == -1)
		return false;
	return true;
}

// Insere o elemento x ao conjunto C, caso x não exista em C
void insereConj(struct conjunto *c, int x) {
	if (!pertenceConj(c, x)) {
		if (c->elementos) {	
			c->elementos[tamConj(c)] = x;
			c->tam++;
			c->maxTam++;
			inserir(c->elementos, 0, c->tam - 1);
			printf("tam = %d e maxTam = %d\n", c->tam, c->maxTam);
			int *aux = realloc(c->elementos, c->maxTam * sizeof(int));
			if (aux) 
				c->elementos = aux;
			else
				printf("Nao foi possivel alocar mais memoria!\n\n");
		}
	} else {
		printf("Elemento ja pertence ao conjunto!\n\n");
	}
}

void removeConj(struct conjunto *c, int x) {
	if (!conjVazio(c)) {
		int result = buscaBinaria(c->elementos, c->tam, x);
		if (result == -1) {
			printf("Elemento nao pertence ao conjunto!\n\n");
		} else {
			for(int i = result; i < (c->tam - 1); i++) 
				c->elementos[i] = c->elementos[i + 1];
			c->tam--;
			c->maxTam--;
			int *aux = realloc(c->elementos, c->maxTam * sizeof(int));
			if (aux)
				c->elementos = aux;
			else
				printf("Nao foi possivel remover elemento");
		}
	}
}

// Retorna conjunto de tamanho alocado máximo tamConj(c1) + tamConj(c2)
struct conjunto *uniao(struct conjunto *c1, struct conjunto *c2) {
	struct conjunto *novo = criaConj();
	for (int i = 0; i < c1->tam; i++) {
		if (pertenceConj(c2, c1->elementos[i]))
			insereConj(novo, c1->elementos[i]);
	}

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

#include <stdbool.h>

struct conjunto {
	int tam;
	int maxTam;
	int *elementos;
};

struct conjunto *criaConj();

void destroiConj(struct conjunto *c);

// Retorna o tamanho do conjunto
int tamConj(struct conjunto *c);

// Verifica se o elemento x pertence ao conjunto C
bool pertenceConj(struct conjunto *c, int x);

// Insere o elemento x ao conjunto C, caso x não exista em C
void insereConj(struct conjunto *c, int x);

void removeConj(struct conjunto *c, int x);

// Retorna conjunto de tamanho alocado máximo tamConj(c1) + tamConj(c2)
struct conjunto *uniao(struct conjunto *c1, struct conjunto *c2);

struct conjunto *intersecao(struct conjunto *c1, struct conjunto *c2);

void imprimeConj(struct conjunto *c);

bool conjVazio(struct conjunto *c);

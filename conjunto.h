// Arquivo conjunto.h
// Define as funcoes presentes na biblioteca para manipular conjuntos

#include <stdbool.h>

struct conjunto {
	int tam;
	int maxTam;
	int *elementos;
};

// Aloca memoria para um conjunto, define seu tamanho para 0, aloca memoria para 1 elemento e retorna o endereco desse conjunto
struct conjunto *criaConj();

// Libera a memoria alocada para o conjunto e seus elementos
void destroiConj(struct conjunto *c);

// Retorna o tamanho do conjunto
int tamConj(struct conjunto *c);

// Verifica se o elemento x pertence ao conjunto C
bool pertenceConj(struct conjunto *c, int x);

// Insere o elemento x ao conjunto C, caso x não exista em C
void insereConj(struct conjunto *c, int x);

// Remove o elemento x do conjunto C, caso ele pertenca a C
void removeConj(struct conjunto *c, int x);

// Retorna conjunto de tamanho alocado máximo tamConj(c1) + tamConj(c2)
struct conjunto *uniao(struct conjunto *c1, struct conjunto *c2);

// Retorna conjunto intersecao
struct conjunto *intersecao(struct conjunto *c1, struct conjunto *c2);

// Imprime os elementos do conjunto
void imprimeConj(struct conjunto *c);

// Retorna 'true' para conjunto vazio ou 'false' para conjunto com pelo menos um elemento
bool conjVazio(struct conjunto *c);

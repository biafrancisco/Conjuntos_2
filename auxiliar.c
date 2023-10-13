#include <stdio.h>
#include "auxiliar.h"

//troca dois elementos de posição x e y em um vetor
void trocar(int vetor[], int x, int y) {
    int aux = vetor[x];
    vetor[x] = vetor[y];
    vetor[y] = aux;
}

//retorna a posicao que um elemento deveria estar num vetor ordenado 
int busca(int vetor[], int a, int b, int valor) {
    if (a > b) 
        return a-1;
    int m = (a + b) / 2;
    if (valor < vetor[m])
        return busca(vetor, a, m - 1, valor);
    else 
        return busca(vetor, m + 1, b, valor);
}

//busca binaria no vetor
int buscaBinaria(int vetor[], int tam, int valor) {
    int a = 0;
    int b = tam - 1;
    int result = busca(vetor, a, b, valor);
    if (vetor[result] == valor)
        return result;
    return -1;
}

//função que insere um elemento no vetor de forma ordenada
void inserir(int vetor[], int a, int b) {
    int p = busca(vetor, a, b - 1, vetor[b]);
    printf("busca = %d\n", p);
    int i = b;
    while (i > p + 1) {
        trocar(vetor, i, i - 1);
        i--;
    }
    return;
} 
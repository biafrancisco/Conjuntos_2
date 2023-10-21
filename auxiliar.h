// Arquivo auxiliar.h
// Define funcoes auxiliares necessarias para a implementacao das funcoes presentes no arquivo conjunto.c

// Troca dois elementos de posição x e y em um vetor
void trocar(int vetor[], int x, int y);

// Retorna a posicao que um elemento deveria estar num vetor ordenado 
int busca(int vetor[], int a, int b, int valor);

// Realiza a busca binaria no vetor
int buscaBinaria(int vetor[], int tam, int valor);

// Ordena o ultimo elemento inserido no vetor (v[b])
void inserir(int vetor[], int a, int b);

// Arquivo main.c
// Testa a biblioteca criada para manipulacao de conjuntos
// Aluna: Bianca Mendes Francisco
// GRR 20234263

#include <stdio.h>
#include <stdlib.h>
#include "conjunto.h"

int main(){

	// Cria dois conjuntos 
	struct conjunto *c1 = criaConj();
	struct conjunto *c2 = criaConj();
	
	// Verifica se a memoria para os conjuntos foi alocada com sucesso
	if ((c1) && (c2)) {
		
		int n = 1;

		// Imprime as operacoes disponiveis ao usuario
		printf("\nOperacoes disponiveis:\n");
		printf("1- Adicionar elemento ao conjunto 1!\n");
		printf("2- Adicionar elemento ao conjunto 2!\n");
		printf("3- Remover elemento do conjunto 1!\n");
		printf("4- Remover elemento do conjunto 2!\n");
		printf("5- Imprimir elementos do conjunto 1!\n");
		printf("6- Imprimir elementos do conjunto 2!\n");
		printf("7- Realizar a uniao dos conjuntos!\n");
		printf("8- Realizar a intersecao entre os conjuntos!\n\n");

		do {
			
			// Define a operacao escolhida pelo usuario
			printf("Digite o numero referente a operacao que deseja realizar: ");
			scanf("%d", &n);
			printf("\n");

			// Realiza a operacao escolhida pelo usuario
			switch (n) {
			case 1:
				printf("Digite o elemento que deseja adicionar ao conjunto 1: ");
				scanf("%d", &n);
				printf("\n");
				insereConj(c1, n);
				break;
			
			case 2:
				printf("Digite o elemento que deseja adicionar ao conjunto 2: ");
				scanf("%d", &n);
				printf("\n");
				insereConj(c2, n);
				break;

			case 3:
				printf("Digite o elemento que deseja remover do conjunto 1: ");
				scanf("%d", &n);
				printf("\n");
				removeConj(c1, n);
				break;

			case 4:
				printf("Digite o elemento que deseja remover do conjunto 2: ");
				scanf("%d", &n);
				printf("\n");
				removeConj(c2, n);
				break;

			case 5:
				printf("Imprimindo conjunto 1...\n");
				imprimeConj(c1);
				break;

			case 6:
				printf("Imprimindo conjunto 2...\n");
				imprimeConj(c2);
				break;

			case 7:
				printf("Realizando a uniao entre os conjuntos...\n");
				struct conjunto *tmp = uniao(c1, c2);
				imprimeConj(tmp);
				free(tmp);
				break;

			case 8:
				printf("Realizando a intersecao entre os conjuntos...\n");
				struct conjunto *tmp2 = intersecao(c1, c2);
				imprimeConj(tmp2);
				free(tmp2);
				break;

			default:
				printf("Operacao invalida!\n\n");
				break;
			}

			// Define se o usuario deseja realizar outra operacao
			printf("Deseja realizar outra operacao? Digite 1 para SIM ou 0 para NAO! ");
			scanf("%d", &n);
			printf("\n");

		} while(n != 0);

		// Destroi os dois conjuntos criados
		destroiConj(c1);
		destroiConj(c2);
		
	} else {
		printf("Nao foi possivel alocar memoria para os conjuntos!\n\n");
	}
	return 0;
}

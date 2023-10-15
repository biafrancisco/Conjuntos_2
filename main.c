#include <stdio.h>
#include "conjunto.h"

int main(){
	struct conjunto *c = criaConj();
	struct conjunto *c2 = criaConj();
	if ((c) && (c2)) {
		
		int n = 1;

		do {
			printf("\nOperacoes disponiveis:\n");


			printf("Deseja realizar outra operacao? Digite 1 para SIM ou 0 para NAO! ");
			scanf("%d", &n);
			printf("\n");

		} while(n != 0);






		destroiConj(c);
		destroiConj(c2);
		
	} else {
		printf("Nao foi possivel alocar memoria para os conjuntos!\n\n");
	}
	return 0;
}

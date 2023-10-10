#include <stdio.h>
#include "conjunto.h"

int main(){
	struct conjunto *c = criaConj();
	if (c) {
		insereConj(c, 7);
		insereConj(c, 4);
		imprimeConj(c);
	
		destroiConj(c);
	} else {
		printf("Nao foi possivel alocar memoria para o conjunto!\n\n");
	}
	return 0;
}

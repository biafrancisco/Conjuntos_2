#include <stdio.h>
#include "conjunto.h"

int main(){
	struct conjunto *c = criaConj();
	if (c) {
		insereConj(c, 7);
		imprimeConj(c);
		insereConj(c, 2);
		imprimeConj(c);
		insereConj(c, 6);
		imprimeConj(c);
		if (pertenceConj(c, 2))
			printf("2 pertence ao conjunto!\n");
		else
			printf("2 nao pertence ao conjunto!\n");
		if (pertenceConj(c, 4))
			printf("4 pertence ao conjunto!\n");
		else
			printf("4 nao pertence ao conjunto!\n");
		removeConj(c, 4);
		removeConj(c, 2);
		imprimeConj(c);
		destroiConj(c);
	} else {
		printf("Nao foi possivel alocar memoria para o conjunto!\n\n");
	}
	return 0;
}

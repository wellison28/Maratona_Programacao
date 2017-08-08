#include <stdio.h>
#include "pilha_simples.c"

void iniciar(){
	push('F');
	push('A');
	push('C');
	push('E');
}

int pontuou(char cs[]){
	int igual = 1;
	int i = 0;
	while(igual && i < 4){
		if(pilha[topo - i] != cs[i])
			igual = 0;
		else
			i++;
	}	
	if(i == 4)
		return 1;
	else
		return 0;
}

void desempilha(){
	pop();
	pop();
	pop();
	pop();
}

void empilha(char cs[]){
	push(cs[0]);
	push(cs[1]);
	push(cs[2]);
	push(cs[3]);
}

int main(){
	char c;
	char cs[5];
	int i, brindes = 0;

	iniciar();

	for(i = 0; i < 4; i++){
		scanf("%c", &c);
		cs[i] = c;
		scanf("%c");
	}
	cs[5] = '\n';

	if(pontuou(cs)){
		brindes++;
		desempilha();
		if(isEmpty())
			iniciar();
	}else
		empilha(cs);

	printf("%d\n", brindes);	

	return 0;
}
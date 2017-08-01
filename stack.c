#include <stdio.h>
#include <stdlib.h>
#include "stackS.c"
#include <string.h>

char expressao[310];
char saida[310];
int tam;
int i;
char c;
int pos = 0;

int prioridade(char c){
	switch(c){
		case ')': 
			return 0;
			break;
		case '+': case '-':
			return 1;
			break;
		case '*': case '/':
			return 2;
			break;
		case '^':
			return 3;
			break;
		case '(':
			return 4;
			break;
		default:
			return -1;
	}
}

void operando(char c){
	saida[pos++] = c;
}

void operador(Pilha * pilha, char c){
	int pPilha = prioridade(topo(pilha));
	int pExpressao = prioridade(c);
	
	if(pPilha != -1){
		if(pExpressao < pPilha){
			while(!isEmpty(pilha) || topo(pilha) == '('){
				operando(topo(pilha));
				pop(pilha);
			}
		}
	}
	push(pilha, c);
}

int main(){
		
	Pilha *pilha = criaPilha();
	init(pilha, -1);

	scanf("%s", expressao);

	tam = strlen(expressao);

	for(i = 0; i < tam; i++){
		c = expressao[i];
		if(prioridade(c) == -1)
			operando(c);
		else
			operador(pilha, c);		
	}
	
	while(!isEmpty(pilha)){
		saida[pos++] = topo(pilha);
		pop(pilha);
	}

	expressao[pos] = '\0';

	printf("%s\n", saida);

	return 0;
}

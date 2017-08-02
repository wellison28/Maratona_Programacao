#include <stdio.h>
#include <string.h>

char pilha[300];
int topo;

void init(){
	topo = 0;
}

void pop(){
	topo--;
}

void push(char elem){
	pilha[topo++ + 1] = elem;
}

int isEmpty(){
	if (topo == 0)
		return 1;
	return 0;
}

char top(){
	return pilha[topo];
}

int isLink(char elem){
	if((top() == 'B' && elem == 'S') || (top() == 'C' && elem == 'F') || (top() == 'S' && elem == 'B') || (top() == 'F' && elem == 'C'))
		return 1;
	return 0;
}

int main(){
	int ligacoes = 0;
	int tam, i;
	char bases[300];

	scanf("%s", bases);
	tam = strlen(bases);

	init();
	push(bases[0]);

	for(i = 1; i < tam; i++){
		if(isLink(bases[i])){
			pop();
			ligacoes++;
		}else
			push(bases[i]);
	}

	printf("%d\n", ligacoes);

	return 0;
}







































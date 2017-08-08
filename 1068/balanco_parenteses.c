#include <stdio.h>
#include <string.h>

char pilha[1010];
int topo;

void init(){
	topo = 0;
}

void pop(){
	topo--;
}

void push(char elem){
	pilha[topo + 1] = elem;
	topo++;
}

int isEmpty(){
	if (topo == 0)
		return 1;
	return 0; 
}

char top(){
	return pilha[topo];
}


int main(){
	char express[1010];
	
	int erro;

	int i;

	while(scanf("%s", express) != EOF ){
		erro = 0;
		int tam = strlen(express);
		
		for(i = 0; i < tam; i++){
			if(express[i] == '(')
				push(express[i]);
			else if(express[i] == ')'){
				if(isEmpty()){
					printf("incorrect\n");
					erro = 1;
				}
				else
					pop();
			}
		}

		if(erro == 0){
			if(!isEmpty())
				printf("incorrect\n");
			else
				printf("correct\n");
		}

	}

	return 0;
}




















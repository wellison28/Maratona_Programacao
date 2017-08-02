#include <stdlib.h>

//Tipo de dado que a pilha ira armazenar
typedef char tipoDado;

typedef struct{
	tipoDado dado;
	struct Node *prox;
	struct Node *ant;
}Node;

typedef struct{
	int tam;
	int tamMax;
	Node *topo;
}Pilha;


void init(Pilha * pilha, int tamMax){
	pilha->topo = NULL;
	pilha->tam = 0;
	pilha->tamMax = tamMax;
}

Pilha * criaPilha(){
	Pilha *pilha = (Pilha *)malloc(sizeof(Pilha));
	return pilha;
}

int isEmpty(Pilha * pilha){
	if(pilha->topo == NULL)
		return 1;
	return 0;
}

Node * criaNode(tipoDado dado){
	Node *node = (Node *)malloc(sizeof(Node));
	node->dado = dado;
	return node;
}

int isFull(Pilha * pilha){
	if(pilha->tamMax == pilha->tam)
		return 1;
	return 0;
}

int push(Pilha *pilha, tipoDado dado){
	if(!isFull(pilha)){
		Node *node = criaNode(dado);
		if(isEmpty(pilha))
			node->ant = NULL;
		else
			node->ant = pilha->topo;
		node->prox = NULL;
		pilha->topo = node;
		pilha->tam++;
		return 1;
	}
	return 0;
}

tipoDado topo(Pilha * pilha){
	if(pilha->topo == NULL)
		return ' ';
	Node *node = pilha->topo;
	return node->dado;
}

int pop(Pilha * pilha){
	if(!isEmpty(pilha)){
		Node *node = pilha->topo;
		pilha->topo = node->ant;
		free(node->prox);
		node->prox = NULL;
		pilha->tam--;
		return 1;
	}
	return 0;
}

void showStack(Pilha * pilha){
	
}

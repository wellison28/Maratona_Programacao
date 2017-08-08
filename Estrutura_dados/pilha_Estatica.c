/*-------------------------------------------------
Pilha de tamanho estatico

OBS.: Para uso da função show(), sempre alterer
o printf para o tipo de dados utilizados;

Pilha * cria();
void init(Pilha * p);
void push(Pilha * p, tipoDado dado);
tipoDado pop(Pilha * p);
tipoDado top(Pilha * p);
int isEmpty(Pilha * p);
int isFull(Pilha * p);
void show(Pilha * p);
---------------------------------------------------*/
#include <stdlib.h>

#define TAM 100
typedef int tipoDado;

typedef struct{
	int topo;
	tipoDado vetor[TAM];
}Pilha;

Pilha * cria(){
	Pilha *p = (Pilha *)malloc(sizeof(Pilha));
	init(p);
	return p;
}

void init(Pilha * p){
	p->topo = 0;
}

void push(Pilha * p, tipoDado dado){
	p->vetor[p->topo] = dado;
	p->topo++;
}

tipoDado pop(Pilha * p){
	tipoDado aux = p->vetor[p->topo--];
	return aux;
}

tipoDado top(Pilha * p){
	return p->vetor[p->topo];
}

int isEmpty(Pilha * p){
	if(p->topo == 0)
		return 1;
	return 0;
}

int isFull(Pilha * p){
	if(p->topo == TAM)
		return 1;
	return 0;
}

void show(Pilha * p){
	int i = 0;
	for(i; i < p->topo; i++)
		printf("%d\n", p->vetor[i]);
}

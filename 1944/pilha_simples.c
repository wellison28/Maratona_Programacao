/*-------------------------------------------------
Pilha unica de tamanho estatico

Estrutura simples que permite operações em apenas 
uma pilha.

void init();
void pop();
void push(tipoDado elem);
int isEmpty();
int isFull();
tipoDado top();
---------------------------------------------------*/
typedef char tipoDado;

tipoDado pilha[450];
int topo;

void init(){
	topo = 0;
}

void pop(){
	topo--;
}

void push(tipoDado elem){
	pilha[topo++ + 1] = elem;
}

int isEmpty(){
	if (topo == 0)
		return 1;
	return 0;
}

int isFull(){
	if (topo == 0)
		return 1;
	return 0;
}

tipoDado top(){
	return pilha[topo];
}

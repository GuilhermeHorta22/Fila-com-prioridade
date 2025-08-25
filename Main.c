#include<stdio.h>
#include<conio2.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

struct TpFilaPrior
{
	int info, prior;
	struct TpFilaPrior *prox;
};
typedef struct TpFilaPrior filaP;

//inicializando fila
void init(filaP **fp)
{
	*fp = NULL;
}

//aloca memoria e cria uma nova caixa dinamica para guardar os dados
filaP *criaCaixa(int info, int prior)
{
	filaP *nova = (filaP*)malloc(sizeof(filaP));
	nova->info = info;
	nova->prior = prior;
	nova->prox = NULL;
	return NULL;
}

//inserir um elemento na fila
void enqueue(filaP **fp, int info, int prioridade)
{
	filaP *aux, *ant, *nova = criaNova(info,prioridade);
	
	if(*fp == NULL || prioridade < (*fp)->prior)
	{
		nova->prox = *fp;
		*fp = nova;
	}
	else
	{
		aux = *fp;
		while(aux->prox != NULL && prioridade >= aux->prior)
		{
			ant = aux;
			aux = aux->prox;
		}
		
		ant->prox = nova;
		nova->prox = aux;
	}
}

//verifica se a fila está vazia
char isEmpty(filaP *fp)
{
	return fp == NULL;
}

//retirando um elemento da fila
void dequeue(filaP **fp, int *info, int *prioridade)
{
	filaP *aux;
	
	if(!isEmpty(*fp))
	{
		aux = *fp;
		*info = aux->info;
		*prioridade = aux->prior;
		*fp = aux->prox;
		free(aux);
	}
}

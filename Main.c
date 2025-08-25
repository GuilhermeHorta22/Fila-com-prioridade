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
	return nova;
}

//inserir um elemento na fila
void enqueue(filaP **fp, int info, int prioridade)
{
	filaP *aux, *ant = NULL, *nova = criaCaixa(info,prioridade);
	
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

//exibe fila
void exibe(filaP *fp)
{
	printf("\n");
	while(fp != NULL)
	{
		printf("%d - %d\t|\t",fp->info,fp->prior);
		fp = fp->prox;
	}
}

int main(void)
{
	filaP *fp;
	int info, prioridade;
	
	init(&fp);
	
	if(isEmpty(fp))
		printf("\nFila Vazia!"); //vai ser vazia
	else
		printf("\nFila com informacao!");
	
	enqueue(&fp,9,3);   // 4º
	enqueue(&fp,7,1);   // 1º
	enqueue(&fp,10,3);  // 3º
	enqueue(&fp,8,2);   // 2º
	
	exibe(fp); //7, 8, 9, 10
	
	dequeue(&fp,&info,&prioridade);
	printf("\nInfo: %d | Prioridade: %d",info,prioridade); //7 | 1
	
	exibe(fp); //8, 10, 9
	
	dequeue(&fp,&info,&prioridade);
	printf("\nInfo: %d | Prioridade: %d",info,prioridade); //8 | 2
	
	exibe(fp); //10, 9
	
	getch();
}

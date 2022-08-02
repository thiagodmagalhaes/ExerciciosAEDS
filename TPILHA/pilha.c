#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"


void FPVazia(TPilha *Pilha)
{
    Pilha->topo = (TCelula*)
                  malloc(sizeof(TCelula));
    Pilha->fundo = Pilha->topo;
    Pilha->topo->prox = NULL;
    Pilha->tamanho = 0;
}

int PVazia(TPilha Pilha)
{
    return (Pilha.topo == Pilha.fundo);
}

void Empilhar(TProduto x,TPilha *Pilha)
{
    TCelula* Aux;
    Aux = (TCelula*)
          malloc(sizeof(TCelula));
    Pilha->topo->item = x;
    Aux->prox = Pilha->topo;
    Pilha->topo = Aux;
    Pilha->tamanho++;
}

void Desempilhar(TPilha *Pilha,TProduto *Item)
{
    TCelula* q;
    if (PVazia(*Pilha))
    {
        printf("Erro: lista vazia\n");
        return;
    }
    q = Pilha->topo;
    Pilha->topo = q->prox;
    *Item = q->prox->item;
    free(q);
    Pilha->tamanho--;
}

void ImprimirPilha(TPilha Pilha)
{
    TPilha PilhaAux;
    FPVazia(&PilhaAux);
    TProduto auxItem;

    // Pop de PIlha e Push em Pilha auxiliar
    while(!PVazia(Pilha))
    {
        Desempilhar(&Pilha, &auxItem);
        Empilhar(auxItem,&PilhaAux);

    }

    while(!PVazia(PilhaAux))
    {
        Desempilhar(&PilhaAux, &auxItem);
        PImprimirProduto(auxItem);// realizar a impressão
        // de cada campo do produto
        Empilhar(auxItem,&Pilha);
    }
    free(PilhaAux.fundo);// eliminar a célula cabeça
}

void PImprimirProduto(TProduto Item)
{
    printf("\n\tCODIGO DO PRODUTO: %d", Item.codigo);
}

int PPesquisar(TPilha Pilha, TProduto Item)
{
    int retorno= -1;
    TPilha PilhaAux;
    FPVazia(&PilhaAux);
    TProduto auxItem;

    if(PVazia(Pilha))
    {
        retorno =0;
        return retorno;
    }
    else
    {

        while(!PVazia(Pilha))
        {
            Desempilhar(&Pilha, &auxItem);
            if(auxItem.codigo == Item.codigo)
                retorno = 1;
            Empilhar(auxItem,&PilhaAux);

        }

        while(!PVazia(PilhaAux))
        {
            Desempilhar(&PilhaAux, &auxItem);
            Empilhar(auxItem,&Pilha);
        }
        free(PilhaAux.fundo);// eliminar a célula cabeça
    }
    return retorno;
}

void PAltera(TPilha Pilha, TProduto Item)
{
    TPilha PilhaAux;
    FPVazia(&PilhaAux);
    TProduto auxItem;

    while(!PVazia(Pilha))
    {
        Desempilhar(&Pilha, &auxItem);
        if(auxItem.codigo == Item.codigo)
            PLerProduto(&auxItem);
        Empilhar(auxItem,&PilhaAux);

    }

    while(!PVazia(PilhaAux))
    {
        Desempilhar(&PilhaAux, &auxItem);
        Empilhar(auxItem,&Pilha);
    }
    free(PilhaAux.fundo);// eliminar a célula cabeça
    printf("\n\tPRODUTO ALTERADO COM SUCESSO!!!");
}


void PLiberar(TPilha *Pilha)
{
    TProduto Item;
    while(!PVazia(*Pilha))
    {
        Desempilhar(Pilha, &Item);
    }
    free(Pilha->topo);
}

int PTamanho(TPilha Pilha)
{
    return (Pilha.tamanho);
}


void PLerProduto(TProduto *item)
{
    printf("\n\tDIGITE O CODIGO DO PRODUTO: ");
    fflush(stdin);
    scanf("%d", &item->codigo);

    printf("\tDIGITE O NOME DO PRODUTO: ");
    fflush(stdin);
    fgets(item->nome,100,stdin);

    printf("\tDIGITE A DESCRICAO DO PRODUTO: ");
    fflush(stdin);
    fgets(item->nome,100,stdin);

    printf("\tDIGITE O PRECO DO PRODUTO: ");
    fflush(stdin);
    scanf("%lf", &item->preco);

    printf("\tDIGITE O NUMERO DE UNIDADES DO PRODUTO: ");
    fflush(stdin);
    scanf("%d", &item->unidade);

}

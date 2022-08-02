#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"
#include "util.h"

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
        printf("Erro: PILHA VAZIA\n");
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
        ImprimirProduto(auxItem);
        Empilhar(auxItem,&PilhaAux);

    }

    while(!PVazia(PilhaAux))
    {
        Desempilhar(&PilhaAux, &auxItem);
       // realizar a impressão
        // de cada campo do produto
        Empilhar(auxItem,&Pilha);
    }
    free(PilhaAux.fundo);// eliminar a célula cabeça
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
            LerProduto(&auxItem);
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



